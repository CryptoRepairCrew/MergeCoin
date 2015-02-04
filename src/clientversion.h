// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2011-2014 The Ixcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef IXCOIN_CLIENTVERSION_H
#define IXCOIN_CLIENTVERSION_H

#if defined(HAVE_CONFIG_H)
#include "config/ixcoin-config.h"
#else
//
// client versioning and copyright year
//

// Note: When ixcoin-config.h is undefined, these are needed to build
// things like the ixcoind-res.rc object file.  Perhaps other tasks.
// Manually keep these the same as the rest of your build for a release.
// Ixcoin-config.h settings are what 'most' of the build process is using.
// ixcoind-res.rc building is at least one that needs these values to match.
//

// These need to be macros, as version.cpp's and ixcoin-qt.rc's voodoo requires it
#define CLIENT_VERSION_MAJOR       0
#define CLIENT_VERSION_MINOR       9
#define CLIENT_VERSION_REVISION    4
#define CLIENT_VERSION_BUILD       0

// Set to true for release, false for prerelease or test build
#define CLIENT_VERSION_IS_RELEASE  false

/**
 * Copyright year (2011-this)
 * Todo: update this when changing our copyright comments in the source
 */
#define COPYRIGHT_YEAR 2014

#endif //HAVE_CONFIG_H

/**
 * Converts the parameter X to a string after macro replacement on X has been performed.
 * Don't merge these into one macro!
 */
#define STRINGIZE(X) DO_STRINGIZE(X)
#define DO_STRINGIZE(X) #X

//! Copyright string used in Windows .rc files
#define COPYRIGHT_STR "2011-" STRINGIZE(COPYRIGHT_YEAR) " The Ixcoin Core Developers"

/**
 * bitcoind-res.rc includes this file, but it cannot cope with real c++ code.
 * WINDRES_PREPROC is defined to indicate that its pre-processor is running.
 * Anything other than a define should be guarded below.
 */

#if !defined(WINDRES_PREPROC)

#include <string>
#include <vector>

static const int CLIENT_VERSION =
                           1000000 * CLIENT_VERSION_MAJOR
                         +   10000 * CLIENT_VERSION_MINOR
                         +     100 * CLIENT_VERSION_REVISION
                         +       1 * CLIENT_VERSION_BUILD;

extern const std::string CLIENT_NAME;
extern const std::string CLIENT_BUILD;
extern const std::string CLIENT_DATE;


std::string FormatFullVersion();
std::string FormatSubVersion(const std::string& name, int nClientVersion, const std::vector<std::string>& comments);

#endif // WINDRES_PREPROC

#endif // IXCOIN_CLIENTVERSION_H

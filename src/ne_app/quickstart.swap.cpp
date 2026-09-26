// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/adb

#include <atomic>
#include <boost/throw_exception.hpp>
#include <exception>
#include <filesystem>
#include <ne_app/quickstart/quickstart.hpp>

#ifndef QS_MAGIC_IDENT
#define QS_MAGIC_IDENT ((uint32_t)' QSINF')
#endif

#ifndef QS_PAD_LEN
#define QS_PAD_LEN (4)
#endif

/// @brief The swapping format for QS.

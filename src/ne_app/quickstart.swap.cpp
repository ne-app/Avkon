// SPDX-License-Identifier: Apache-2.0
// Copyright 2026, Ne.app. All rights reserved
// Official repository: https://github.com/ne-app/adb

#include <boost/throw_exception.hpp>
#include <ne_app/quickstart/quickstart.hpp>
#include <stdexcept>

#ifndef QS_MAGIC_IDENT
#define QS_MAGIC_IDENT ((uint32_t)' QSINF')
#endif

#ifndef QS_PAD_LEN
#define QS_PAD_LEN (4)
#endif

/// @brief The swapping format for QS.

namespace ne_app {

    namespace detail {

        struct FILE_HEADER final {
            char magic_[4];
            int32_t len_;
            int32_t flags_;
            int32_t type_;
            char pad_[4];
        };

    }

    using format_error = std::runtime_error;
    using swap_error = std::runtime_error;

}
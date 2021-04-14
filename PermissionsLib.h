/**
 * @file    PermissionsLib.h
 * @brief   PermissionsLib has function which checks root permissions.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef PERMISSIONSLIB_H
#define PERMISSIONSLIB_H

#include <unistd.h>

#define REDPERMISSIONSLIB_VERSION            "1.0.0"  // 1.0.0
#define REDPERMISSIONSLIB_VERSION_NUMBER     100      // 1.0.0

namespace Red {
    namespace PermissionsLib {
        #define PERMISSIONSLIB_HAS_ROOT true
        #define PERMISSIONSLIB_HAS_NO_ROOT false

        /**
         * @brief CheckRootPermissions
         *
         * @return true if has root, false if hasn't.
         */
        bool CheckRootPermissions() {
            return !getuid();
        }
    }
}
#endif // PERMISSIONSLIB_H

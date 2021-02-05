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

namespace Red {
    namespace PermissionsLib {
        #define PERMISSIONSLIB_HAS_ROOT true
        #define PERMISSIONSLIB_HAS_NOT_ROOT false

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

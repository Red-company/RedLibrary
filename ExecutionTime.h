/**
 * @file    ExecutionTime.h
 * @brief   ExecutionTime has function which calculates time of execution.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_EXECUTIONTIME_H
#define RED_EXECUTIONTIME_H

#include <chrono>

#define REDEXECUTIONTIME_VERSION            "1.0"

namespace Red {
    template<typename TimeT = std::chrono::milliseconds>
    struct Measure {
        template<typename F, typename ...Args>
        /**
         * @brief ExecutionTime
         *
         * @param func Function which execution time need to be calculated.
         * @param args Arguments to Function.
         *
         * @return Time of executing.
         */
        inline static typename TimeT::rep ExecutionTime(F func, Args&&... args) {
            auto start = std::chrono::system_clock::now();

            func(std::forward<Args>(args)...);

            auto duration = std::chrono::duration_cast<TimeT>
                            (std::chrono::system_clock::now() - start);

            return duration.count();
        }
    };
}

#endif // RED_EXECUTIONTIME_H

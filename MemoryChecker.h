/**
 * @file    MemoryChecker.h
 * @brief   MemoryChecker is lib, which has some functions uses to get system memory info.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_MEMORYCHECKER_H
#define RED_MEMORYCHECKER_H

#define REDMEMORYCHECKER_VERSION "1.0"

namespace Red {
    namespace RAM {
        #ifdef __linux__
        #include <sys/sysinfo.h>
        #endif

        #ifdef __APPLE__
        #include <mach/task.h>
        #include <mach/mach_init.h>
        #endif

        #ifdef _WINDOWS
        #include <windows.h>
        #else
        #include <sys/resource.h>
        #endif

        /**
         * @brief GetMemoryUsage
         *
         * @return Num of using memory (in bytes).
         */
        unsigned long long int GetMemoryUsage() {
            /// The amount of memory currently being used by this process, in bytes.
            /// By default, returns the full virtual arena, but if resident=true,
            /// it will report just the resident set in RAM (if supported on that OS).
            bool resident = false;

            #if defined(__linux__)
            size_t size = 0;
            FILE *file  = fopen("/proc/self/statm", "r");

            if (file) {
                unsigned long vm = 0;
                fscanf (file, "%ul", &vm);  // Just need the first num: vm size
                fclose (file);
                size = (unsigned long long int) vm * getpagesize();
            }

            return size;

            #elif defined(__APPLE__)
            struct task_basic_info t_info;
            mach_msg_type_number_t t_info_count = TASK_BASIC_INFO_COUNT;

            task_info(current_task(), TASK_BASIC_INFO, (task_info_t) &t_info, &t_info_count);

            size_t size = (resident ? t_info.resident_size : t_info.virtual_size);

            return size;

            #elif defined(_WINDOWS)
            // According to MSDN...
            PROCESS_MEMORY_COUNTERS counters;

            if (GetProcessMemoryInfo (GetCurrentProcess(), &counters, sizeof (counters))) {
                return counters.PagefileUsage;

            } else {
                return 0;
            }

            #else
            // No idea what platform this is
            return 0;   // Punt
            #endif
        }

        #if defined(_WINDOWS)
        #include <windows.h>

        /**
         * @brief GetTotalSystemMemory
         *
         * @return Total num of memory (in bytes).
         */
        unsigned long long int GetTotalSystemMemory() {
            MEMORYSTATUSEX status;
            status.dwLength = sizeof (status);
            GlobalMemoryStatusEx(&status);
            return status.ullTotalPhys;
        }

        #elif defined(__APPLE__) || defined(__linux__)
        #include <unistd.h>

        /**
         * @brief GetTotalSystemMemory
         *
         * @return Total num of memory (in bytes).
         */
        unsigned long long int GetTotalMemory() {
            unsigned long long int pages     = (unsigned long long int) sysconf(_SC_PHYS_PAGES);
            unsigned long long int page_size = (unsigned long long int) sysconf(_SC_PAGE_SIZE);
            return pages * page_size;
        }

        #endif

        /**
         * @brief GetFreeMemory
         *
         * @return Num of free memory (in bytes).
         */
        unsigned long long int GetFreeMemory() {
            return GetTotalMemory() - GetMemoryUsage();
        }
    }

    namespace ROM {
        #include <sys/statvfs.h>
        #include <string>

        /**
         * @brief GetTotalMemory
         *
         * @param path Path to folder which need to be parsed.
         *
         * @return Total num of memory.
         */
        unsigned long long int GetTotalMemory(std::string& path) {
            struct statvfs stat;

            if (statvfs(path.c_str(), &stat) != 0) {
                // error happens, just quits here
                return -1;
            }

            return stat.f_bsize * stat.f_blocks * 4;
        }

        /**
         * @brief GetFreeMemory
         *
         * @param path Path to folder which need to be parsed.
         *
         * @return Num of memory available to non-root user.
         */
        unsigned long long int GetFreeMemory(std::string& path) {
            struct statvfs stat;

            if (statvfs(path.c_str(), &stat) != 0) {
                // error happens, just quits here
                return -1;
            }

            return stat.f_bsize * stat.f_bavail;
        }

        /**
         * @brief GetFreeMemory_root
         *
         * @param path Path to folder which need to be parsed.
         *
         * @return Num of memory available to root user.
         */
        unsigned long long int GetFreeMemory_root(std::string& path) {
            struct statvfs stat;

            if (statvfs(path.c_str(), &stat) != 0) {
                // error happens, just quits here
                return -1;
            }

            return stat.f_bsize * stat.f_bfree;
        }

        /**
         * @brief GetMemoryUsage
         *
         * @param path Path to folder which need to be parsed.
         *
         * @return Num of using memory available to non-root user.
         */
        unsigned long long int GetMemoryUsage(std::string& path) {
            struct statvfs stat;

            if (statvfs(path.c_str(), &stat) != 0) {
                // error happens, just quits here
                return -1;
            }

            return stat.f_bsize * (stat.f_blocks - stat.f_bavail);
        }

        /**
         * @brief GetMemoryUsage_root
         *
         * @param path Path to folder which need to be parsed.
         *
         * @return Num of using memory available to non-root user.
         */
        unsigned long long int GetMemoryUsage_root(std::string& path) {
            struct statvfs stat;

            if (statvfs(path.c_str(), &stat) != 0) {
                // error happens, just quits here
                return -1;
            }

            return stat.f_bsize * (stat.f_blocks - stat.f_bfree);
        }
    }
}

#endif // RED_MEMORYCHECKER_H

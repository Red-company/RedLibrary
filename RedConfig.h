/**
 * @file    RedConfig.h
 * @ingroup RedConfig
 * @brief   RedConfig is a lib to create/use variables preset.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#ifndef RED_CONFIG_H
#define RED_CONFIG_H

#include <string>
#include <map>

// RedLibrary.
#include "../RedLibrary/InsensitiveMap.h"

#define REDCONFIG_VERSION           "1.0"

namespace Red {
    namespace RedConfig {
        // Macroses.

        /// Types.
        #define REDCONFIG_STRING_TYPE  "str"
        #define REDCONFIG_INTEGER_TYPE "int"

        /// Throw.
        #define REDCONFIG_THROW    true
        #define REDCONFIG_NO_THROW false

        /// Base object.
        struct Variable {
            // Variables.

            std::string Type;
            std::string Data;

            // Return functions.

            /**
             * @brief data
             *
             * @return Data of variable.
             */
            std::string data();

            /**
             * @brief type
             *
             * @return Type of variable.
             */
            std::string type();
        };

        //
        // RedConfig functions.
        //

        // Check functions.

        /**
         * @brief is_int
         *
         * @param s String to parse.
         *
         * @return '1' if s is number, '0' if isn't.
         */
        bool is_int(const std::string& s);

        /**
         * @brief is_str
         *
         * @param s String to parse.
         *
         * @return '1' if s is string, '0' if isn't.
         */
        bool is_str(const std::string& s);

        // Others.

        /**
         * @brief GetType
         *
         * @param str Value to parse.
         *
         * @return "int" if str is integer, "str" if isn't.
         */
        std::string GetType(std::string& str);

        /**
         * @brief ConfigFileExists
         *
         * @param path Path to .rcfg file.
         *
         * @return True if configuration file exists, false if not.
         */
        bool ConfigFileExists(std::string& path);

        /**
         * @brief HasVariable
         *
         * @param path     Path to .rcfg file.
         * @param variable Variable to be found in .rcfg file.
         *
         * @return True if there is the variable, false if not.
         */
        bool HasVariable(std::string& path, std::string& variable);

        /**
         * @brief HasValue
         *
         * @param path     Path to .rcfg file.
         * @param variable Variable to be parsed.
         *
         * @return True if "variable" has any value, false if hasn't.
         */
        bool HasValue(std::string& path, std::string& variable);

        // Base functions.

        /**
         * @brief CreateConfigFile
         *
         * @param path      Path where .rcfg file will be created.
         * @param name      File name.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_create_file();
         */
        bool CreateConfigFile(std::string path, std::string name, bool can_throw = REDCONFIG_THROW);

        /**
         * @brief SaveValues
         *
         * @param variables Key-value array of variables to save.
         * @param path      Path where new .rcfg setup will be saved.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_create_file();
         */
        bool SaveValues(std::map<std::string, Variable>& variables, std::string& path, bool can_throw = REDCONFIG_THROW);

        /**
         * @brief SaveValues
         *
         * @param variables Key-value array of variables to save.
         * @param path      Path where new .rcfg setup will be saved.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_create_file();
         */
        bool SaveValues(Red::InsensitiveMap<std::string, Variable>& variables, std::string& path, bool can_throw = REDCONFIG_THROW);

        /**
         * @brief UpdateValues
         *
         * Wrapper for SaveValues
         *
         * @param variables Key-value array of variables to save.
         * @param path      Path where new .rcfg setup will be saved.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_create_file();
         */
        bool UpdateValues(std::map<std::string, Variable> &variables, std::string& path, bool can_throw = REDCONFIG_THROW);

        /**
         * @brief UpdateValues
         *
         * Wrapper for SaveValues
         *
         * @param variables Key-value array of variables to save.
         * @param path      Path where new .rcfg setup will be saved.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_create_file();
         */
        bool UpdateValues(Red::InsensitiveMap<std::string, Variable> &variables, std::string& path, bool can_throw = REDCONFIG_THROW);

        /**
         * @brief LoadValues
         *
         * @param variables Key-value array where variables will be saved.
         * @param path      Path of .rcfg file which need to be loaded.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_open_file();
         */
        bool LoadValues(std::map<std::string, Variable> * variables, std::string& path, bool can_throw = REDCONFIG_THROW);

        /**
         * @brief LoadValues
         *
         * @param variables Key-value array where variables will be saved.
         * @param path      Path of .rcfg file which need to be loaded.
         * @param can_throw If true, may throw an exception,
         *                  if false, returns false.
         *
         * @throw Red::RedConfig::Exceptions::can_not_open_file();
         */
        bool LoadValues(Red::InsensitiveMap<std::string, Variable> * variables, std::string& path, bool can_throw = REDCONFIG_THROW);
    }
}

#endif // RED_CONFIG_H

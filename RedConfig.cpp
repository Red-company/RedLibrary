/**
 * @file    RedConfig.cpp
 * @ingroup RedConfig
 * @brief   RedConfig is a lib to create/use variables preset.
 *
 * Copyright (c) 2020-2021 Vladimir Rogozin (vladimir20040609@gmail.com)
 *
 * Distributed under the MIT License (MIT) (See accompanying file LICENSE.txt
 * or copy at http://opensource.org/licenses/MIT)
 */
#include "RedConfig.h"

#include <fstream>
#include <sstream>

#include "RedConfig/Exceptions.h"

#include "InsensitiveMap.h"

namespace Red {
    namespace RedConfig {
        //
        // Variable return functions.
        //

        /**
         * @brief Variable::data
         *
         * @return Data variable as string object.
         */
        std::string Variable::data() {
            return Data;
        }

        /**
         * @brief Variable::type
         *
         * @return Type variable as string object.
         */
        std::string Variable::type() {
            return Type;
        }

        //
        // RedConfig functions.
        //

        /**
         * @brief is_int
         *
         * @param s String to parse.
         *
         * @return '1' if s is number, '0' if isn't.
         */
        bool is_int(const std::string& s) {
            std::string::const_iterator it = s.begin();
            while (it != s.end() && std::isdigit(*it)) { ++it; }
            return !s.empty() && it == s.end();
        }

        /**
         * @brief is_str
         *
         * @param s String to parse.
         *
         * @return '1' if s is string, '0' if isn't.
         */
        bool is_str(const std::string& s) {
            std::string::const_iterator it = s.begin();
            while (it != s.end() && std::isalpha(*it)) { ++it; }
            return !s.empty() && it == s.end();
        }

        /**
         * @brief GetType
         *
         * @param str Value to parse.
         *
         * @return "int" if str is integer, "str" if isn't.
         */
        std::string GetType(std::string& str) {
            if (is_int(str)) {
                return REDCONFIG_INTEGER_TYPE;

            } else {
                return REDCONFIG_STRING_TYPE;
            }
        }

        /**
         * @brief ConfigFileExists
         *
         * @param path Path to .rcfg file.
         *
         * @return True if configuration file exists, false if not.
         */
        bool ConfigFileExists(std::string& path) {
            std::ifstream is(path);
            bool res = false;

            if (is.is_open()) {
                res = true;
            }

            is.close();

            return res;
        }

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
        bool CreateConfigFile(std::string path, std::string name, bool can_throw) {
            if (path[path.length()] != '/') {
                path += "/";
            }

            path += name + ".rcfg";

            std::ofstream os(path);

            if (os.is_open()) {
                os.close();
                return true;

            } else {
                if (can_throw) {
                    throw Red::RedConfig::Exceptions::can_not_create_file();

                } else {
                    return false;
                }
            }
        }

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
        bool SaveValues(std::map<std::string, Variable> &variables, std::string& path, bool can_throw) {
            std::string toSave = "#start\n";
            std::map<std::string, Variable>::iterator it = variables.begin();

            while (it != variables.end()){
                if (GetType(it->second.Data) == REDCONFIG_STRING_TYPE) {
                    toSave += "$" + it->first + "=" + "\"" + it->second.Data + "\"" + "\n";

                } else if (GetType(it->second.Data) == REDCONFIG_INTEGER_TYPE) {
                    toSave += "$" + it->first + "=" + it->second.Data + "," + "\n";
                }

                it++;
            }

            toSave += "#end";

            std::ofstream outfile(path);

            if (outfile.is_open()) {
                outfile << toSave;
                outfile.close();
                return true;

            } else {
                if (can_throw) {
                    throw Red::RedConfig::Exceptions::can_not_create_file();

                } else {
                    return false;
                }
            }
        }

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
        bool SaveValues(Red::InsensitiveMap<std::string, Variable>& variables, std::string& path, bool can_throw) {
            std::string toSave = "#start\n";
            Red::InsensitiveMap<std::string, Variable>::iterator it = variables.begin();

            while (it != variables.end()){
                if (GetType(it->second.Data) == REDCONFIG_STRING_TYPE) {
                    toSave += "$" + it->first + "=" + "\"" + it->second.Data + "\"" + "\n";

                } else if (GetType(it->second.Data) == REDCONFIG_INTEGER_TYPE) {
                    toSave += "$" + it->first + "=" + it->second.Data + "," + "\n";
                }

                it++;
            }

            toSave += "#end";

            std::ofstream outfile(path);

            if (outfile.is_open()) {
                outfile << toSave;
                outfile.close();
                return true;

            } else {
                if (can_throw) {
                    throw Red::RedConfig::Exceptions::can_not_create_file();

                } else {
                    return false;
                }
            }
        }

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
        bool UpdateValues(std::map<std::string, Variable> &variables, std::string& path, bool can_throw) {
            return SaveValues(variables, path, can_throw);
        }

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
        bool UpdateValues(Red::InsensitiveMap<std::string, Variable> &variables, std::string& path, bool can_throw) {
            return SaveValues(variables, path, can_throw);
        }

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
        bool LoadValues(std::map<std::string, Variable> * variables, std::string& path, bool can_throw) {
            std::string source;

            {
                std::ifstream file(path);

                if (file.is_open()) {
                    std::stringstream buffer;

                    buffer << file.rdbuf();
                    source = buffer.str();

                } else {
                    if (can_throw) {
                        throw Red::RedConfig::Exceptions::can_not_open_file();

                    } else {
                        return false;
                    }
                }

            }

            for (unsigned long int i = 0; i < source.length() - 1; i++) {
                if (source.at(i) == '/' && source.at(i + 1) == '/') {
                    //the line is a comment and should be skipped
                    while (1) {
                        if (source.at(i) == '\n') {
                            break;
                        }

                        i++;
                    }

                } else if (source.at(i) == '#') {
                    unsigned long int it = 1;
                    std::string s;

                    while (true) {
                        if (i + it == source.length() || source.at(i + it) == '\n' ||
                            source.at(i + it) == ' '  || source.at(i + it) == ' ') {
                            break;
                        }

                        s += source.at(i + it);
                        it++;
                    }

                    i = i + it;

                } else if (source.at(i) == '$') {
                    std::string variableName;
                    std::string variableValue;
                    unsigned long int it = 1;

                    while (true) {
                        if (source.at(i + it) == '=') {
                            break;
                        }

                        if (source.at(i + it) != ' ' && source.at(i + it) != '\t') {
                            variableName += source.at(i + it);
                            it++;
                        }
                    }

                    i = i + it;
                    it = 1;

                    bool IsStr = false;

                    if (source.at(i + it) == '\'' || source.at(i + it) == '\"' ||
                        std::isalpha(source.at(i + it)) || !std::isdigit(source.at(i + it))) {
                        IsStr = true;
                        it++;
                    }

                    while (true) {
                        if (IsStr) {
                            if (source.at(i + it) == '\'' || source.at(i + it) == '\"') {
                                break;
                            }

                        } else {
                            if (source.at(i + it) == ',' || source.at(i + it) == '\n' ||
                                source.at(i + it) == ' ' || source.at(i + it) == '\t') {
                                break;
                            }
                        }

                        variableValue += source.at(i + it);
                        it++;
                    }

                    i = i + it - 1;

                    std::string variableType = GetType(variableValue);

                    Variable v;

                    v.Data = variableValue;

                    if (variableType == REDCONFIG_STRING_TYPE) {
                        v.Type = REDCONFIG_STRING_TYPE;

                    } else if (variableType == REDCONFIG_INTEGER_TYPE) {
                        v.Type = REDCONFIG_INTEGER_TYPE;
                    }

                    variables->insert(std::make_pair(variableName, v));
                }
            }

            return true;
        }

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
        bool LoadValues(Red::InsensitiveMap<std::string, Variable> * variables, std::string& path, bool can_throw) {
            std::string source;

            {
                std::ifstream file(path);

                if (file.is_open()) {
                    std::stringstream buffer;

                    buffer << file.rdbuf();
                    source = buffer.str();

                } else {
                    if (can_throw) {
                        throw Red::RedConfig::Exceptions::can_not_open_file();

                    } else {
                        return false;
                    }
                }

            }

            for (unsigned long int i = 0; i < source.length() - 1; i++) {
                if (source.at(i) == '/' && source.at(i + 1) == '/') {
                    //the line is a comment and should be skipped
                    while (1) {
                        if (source.at(i) == '\n') {
                            break;
                        }

                        i++;
                    }

                } else if (source.at(i) == '#') {
                    unsigned long int it = 1;
                    std::string s;

                    while (true) {
                        if (i + it == source.length() || source.at(i + it) == '\n' ||
                            source.at(i + it) == ' '  || source.at(i + it) == ' ') {
                            break;
                        }

                        s += source.at(i + it);
                        it++;
                    }

                    i = i + it;

                } else if (source.at(i) == '$') {
                    std::string variableName;
                    std::string variableValue;
                    unsigned long int it = 1;

                    while (true) {
                        if (source.at(i + it) == '=') {
                            break;
                        }

                        if (source.at(i + it) != ' ' && source.at(i + it) != '\t') {
                            variableName += source.at(i + it);
                            it++;
                        }
                    }

                    i = i + it;
                    it = 1;

                    bool IsStr = false;

                    if (source.at(i + it) == '\'' || source.at(i + it) == '\"' ||
                        std::isalpha(source.at(i + it)) || !std::isdigit(source.at(i + it))) {
                        IsStr = true;
                        it++;
                    }

                    while (true) {
                        if (IsStr) {
                            if (source.at(i + it) == '\'' || source.at(i + it) == '\"') {
                                break;
                            }

                        } else {
                            if (source.at(i + it) == ',' || source.at(i + it) == '\n' ||
                                source.at(i + it) == ' ' || source.at(i + it) == '\t') {
                                break;
                            }
                        }

                        variableValue += source.at(i + it);
                        it++;
                    }

                    i = i + it - 1;

                    std::string variableType = GetType(variableValue);

                    Variable v;

                    v.Data = variableValue;

                    if (variableType == REDCONFIG_STRING_TYPE) {
                        v.Type = REDCONFIG_STRING_TYPE;

                    } else if (variableType == REDCONFIG_INTEGER_TYPE) {
                        v.Type = REDCONFIG_INTEGER_TYPE;
                    }

                    variables->insert(std::make_pair(variableName, v));
                }
            }

            return true;
        }

        /**
         * @brief HasVariable
         *
         * @param path     Path to .rcfg file.
         * @param variable Variable to be found in .rcfg file.
         *
         * @return True if there is the variable, false if not.
         */
        bool HasVariable(std::string& path, std::string& variable) {
            //std::map<std::string, Red::RedConfig::Variable> variables;
            Red::InsensitiveMap<std::string, Red::RedConfig::Variable> variables;

            Red::RedConfig::LoadValues(&variables, path, REDCONFIG_THROW);

            return variables.find(variable) != variables.end()
                    ?
                   true
                    :
                   false
                    ;
        }

        /**
         * @brief HasValue
         *
         * @param path     Path to .rcfg file.
         * @param variable Variable to be parsed.
         *
         * @return True if "variable" has any value, false if hasn't.
         */
        bool HasValue(std::string& path, std::string& variable) {
            //std::map<std::string, Red::RedConfig::Variable> variables;
            Red::InsensitiveMap<std::string, Red::RedConfig::Variable> variables;

            Red::RedConfig::LoadValues(&variables, path, REDCONFIG_THROW);

            return variables.find(variable)->second.Data != ""
                    ?
                   true
                    :
                   false
                    ;
        }
    }
}

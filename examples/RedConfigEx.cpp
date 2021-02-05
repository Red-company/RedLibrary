#include <iostream>
#include <string>
#include <map>

// Connecting lib.
#include "../RedLibrary/RedConfig.h"

// For part 2.
#include "../RedLibrary/RedConfig/Exceptions.h"

// Pathes for example.
static std::string Open     = "/Users/vladimir/Desktop/test.rcfg";
static std::string Save     = "/Users/vladimir/Desktop/out.rcfg";
static std::string SavePath = "/Users/vladimir/Desktop/";

int main(){
    system("clear");

    std::map<std::string, Red::RedConfig::Variable> variables;

    ////////////////////////////////////////////////////////////////////////////////////
    /// Part 1. ///

    //
    // Checking config file for existance.
    //

    if (Red::RedConfig::ConfigFileExists(Open)) {
        // Config file exists.
    }

    //
    // Checking for variable.
    //

    std::string var = "hello";

    if (Red::RedConfig::HasVariable(Open, var)) {
        // Config file has the variable.
    }

    //
    // Checking for value.
    //

    if (Red::RedConfig::HasValue(Open, var)) {
        // Config file's variable "valueString" has a value.
    }

    //
    // Loading variables from "test.rcfg".
    //

    if (Red::RedConfig::LoadValues(&variables, Open)) {
        // Loaded successfully.
    }

    //
    // Getting types of some variables.
    //

    std::string value1;
    std::string typeValue1 = variables["valueString"].type();
    // std::string typeValue1 = variables["valueString"].Type;

    std::string value2;
    // std::string typeValue2 = variables["valueInteger"].type();
    std::string typeValue2 = variables["valueInteger"].Type;

    //
    // Example of using macroses.
    //

    if (typeValue1 == REDCONFIG_STRING_TYPE) {
        // value1 = variables["valueString"].Data;
        value1 = variables["valueString"].data();
    }

    if (typeValue2 == REDCONFIG_INTEGER_TYPE) {
        value2 = variables["valueInteger"].Data;
        // value2 = variables["valueInteger"].data();
    }

    //
    // GetType function example.
    //

    if (Red::RedConfig::GetType(value1) == REDCONFIG_STRING_TYPE) {
        // ...
    }

    //
    // Changing values of some variables.
    //

    variables["valueString"].Data = "hi";
    variables["valueInteger"].Data = "24";

    //
    // Showing new values.
    //

    std::cout << "'valueString':  '" << value1 << "'." << std::endl;
    std::cout << "'valueInteger': '" << value2 << "'." << std::endl;

    //
    // Creating empty config file (May be omitted).
    //

    if (Red::RedConfig::CreateConfigFile(SavePath, "out")) {
        // Created out.cfg at SavePath successfully.
    }

    //
    // Saving new values in "out.rcfg" (may be used without "CreateConfigFile").
    //

    if (Red::RedConfig::SaveValues(variables, Save)) {
        // Saved successfully.
    }

    //
    // Update values (wrapper of SaveValues).
    //

    if (Red::RedConfig::UpdateValues(variables, Save)) {
        // Updated successfully.
    }


    ////////////////////////////////////////////////////////////////////////////////////
    /// Part 2. ///

    //
    // Handling included exceptions.
    //

    std::string BadPath = "\0";

    std::cout << std::endl << "### Base exceptions ###" << std::endl << std::endl;

    // CreateConfigFile exception.

    try {
        if (Red::RedConfig::CreateConfigFile(BadPath, "new", REDCONFIG_THROW)) { // REDCONFIG_THROW may be omitted
                                                                            // or changed to "true".
            // Loaded successfully.
        }
    } catch (std::exception& e) {
        std::cout << "CreateConfigFile error occured. Name of exception: '" << e.what() << "'." << std::endl;
    }

    // LoadValues exception.

    try {
        if (Red::RedConfig::LoadValues(&variables, BadPath, REDCONFIG_THROW)) { // REDCONFIG_THROW may be omitted
                                                                               // or changed to "true".
            // Loaded successfully.
        }
    } catch (std::exception& e) {
        std::cout << "LoadValues error occured. Name of exception: '" << e.what() << "'." << std::endl;
    }

    // SaveValues exception.

    try {
        if (Red::RedConfig::SaveValues(variables, BadPath, REDCONFIG_THROW)) { // REDCONFIG_THROW may be omitted
                                                                               // // or changed to "true".
            // Loaded successfully.
        }
    } catch (std::exception& e) {
        std::cout << "SaveValues error occured. Name of exception: '" << e.what() << "'." << std::endl;
    }

    // UpdateValues exception.

    try {
        if (Red::RedConfig::UpdateValues(variables, BadPath, REDCONFIG_THROW)) { // REDCONFIG_THROW may be omitted
                                                                               // // or changed to "true".
            // Loaded successfully.
        }
    } catch (std::exception& e) {
        std::cout << "UpdateValues error occured. Name of exception: '" << e.what() << "'." << std::endl;
    }

    //
    // Handling your own exceptions.
    //

    std::cout << std::endl << "### Own exceptions ###" << std::endl << std::endl;

    // CreateConfigFile.

    try {
        if (Red::RedConfig::CreateConfigFile(BadPath, "new", REDCONFIG_NO_THROW)) {
            // Loaded successfully.
        } else { // Your exception inside.
            throw "CreateConfigFile err";
        }
    } catch (const char *& e) {
        std::cout << "CreateConfigFile error occured. Text: " << e << std::endl;
    }

    // LoadValues.

    try {
        if (Red::RedConfig::LoadValues(&variables, BadPath, REDCONFIG_NO_THROW)) {
            // Loaded successfully.
        } else { // Your exception inside.
            throw "LoadValues err";
        }
    } catch (const char *& e) {
        std::cout << "LoadValues error occured. Text: " << e << std::endl;
    }

    // Save values.

    try {
        if (Red::RedConfig::SaveValues(variables, BadPath, REDCONFIG_NO_THROW)) {
            // Loaded successfully.
        } else { // Your exception inside.
            throw "SaveValues err";
        }
    } catch (const char *& e) {
        std::cout << "LoadValues error occured. Text: " << e << std::endl;
    }

    try {
        if (Red::RedConfig::UpdateValues(variables, BadPath, REDCONFIG_NO_THROW)) {
            // Loaded successfully.
        } else {
            throw "UpdateValues err";
        }
    } catch (const char *& e) {
        std::cout << "UpdateValues error occured. Text: " << e << std::endl;
    }

    return 0;
}

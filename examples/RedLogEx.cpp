#include <iostream>
#include <string>

#include "../RedLibrary/RedLog.h"

int main() {
    system("clear");

    std::string path = "/Users/vladimir/Desktop/RedLogTest.rlog";

    ReCheck:


    if (Red::RedLog::FileExists(path)) {
        std::cout << "Log file exists." << std::endl;

        Red::RedLog rl(path);
        rl.NewNote("Main module", "Test is running..");
        rl.NewNote("Main module", "Test was finished");
        rl.NewNote(REDLOG_NO_GROUP, "New note");

    } else {
        std::cout << "Log file does not exist, creating file." << std::endl;

        if (Red::RedLog::CreateLogFile(path)) {
            std::cout << "File was created." << std::endl;
            goto ReCheck;

        } else {
            std::cout << "File was not created." << std::endl;
        }
    }


    /*
    if (Red::RedLog::DeleteFile(path)) {
        std::cout << "Log file was successfully deleted." << std::endl;

    } else {
        std::cout << "Log file was not deleted." << std::endl;
    }
    */

    return 0;
}

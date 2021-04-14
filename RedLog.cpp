#include "RedLog.h"

#include <string>


//
// Local functions.
//

/**
 * @brief GetCurrentTime
 *
 * @return String with time.
 */
static std::string GetCurrentTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%d-%m-%Y %X", &tstruct);

   return std::string(buf);
}

namespace Red {
    /**
     * @brief RedLog
     *
     * Base ctor.
     */
    RedLog::RedLog() {}

    /**
     * @brief RedLog
     *
     * Ctor.
     *
     * @param path Path to log file.
     */
    RedLog::RedLog(std::string& path) {
        LogFile.open(path, std::ios::app);
    }

    /**
     * @brief OpenFile
     *
     * Uses to open log file.
     *
     * @param path Path to log file.
     */
    void RedLog::OpenFile(std::string& path) {
        LogFile.open(path, std::ios::app);
    }

    /**
     * @brief NewNote
     *
     * Uses to add new line to log file.
     *
     * Date and time will be added automatically.
     *
     * @param group Group of module you logging.
     * @param note String which will be added to log file.
     */
    void RedLog::NewNote(std::string group, std::string note) {
        // Getting necessary variables.

        std::string time = GetCurrentTime();
        std::string res  = "\n";


        // Creating string.

        /// Inserting time.
        res += "[" + time + "]";

        /// Insering group if need.
        if (group != RED_REDLOG_NO_GROUP) {
            res += "(" + group + ")";
        }

        /// Inserting note.
        res += " " + note + ".";

        LogFile << res;
    }
}


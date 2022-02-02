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
static inline std::string _GetCurrentTime() {
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
        m_LogFile.open(path, std::ios::app);
    }

    /**
     * @brief OpenFile
     *
     * Uses to open log file.
     *
     * @param path Path to log file.
     */
    void RedLog::OpenFile(std::string& path) {
        m_LogFile.open(path, std::ios::app);
    }

    /**
     * @brief FileExists
     *
     * Uses to check log file for existance.
     *
     * @param path Path to log file.
     *
     * @return True if log file exists, false if not.
     */
    bool RedLog::FileExists(std::string& path) {
        std::ifstream is(path);
        return is.is_open() ? true : false;
    }

    /**
     * @brief CreateLogFile
     *
     * Uses to create log file.
     *
     * @param path Path to log file.
     *
     * @return True if file was created, false if not.
     */
    bool RedLog::CreateLogFile(std::string& path) {
        // Creating a log file.

        std::ofstream of(path);

        if (!of.is_open()){
            return false;
        }

        of << "############################" << "\n";
        of << "    RedLog version: " << REDLOG_VERSION << "\n";
        of << "############################" << "\n";
        of << "Created: " + _GetCurrentTime() << "\n";
        of << "############################" << "\n";

        of.close();

        // Checking file for existance.

        std::ifstream is(path);

        if (is.is_open()) {
            return true;

        } else {
            return false;
        }
    }

    /**
     * @brief DeleteFile
     *
     * Uses to delete log file.
     *
     * @param path Path to log file.
     *
     * @return True if file was deleted successfully, false if not.
     */
    bool RedLog::DeleteFile(std::string& path) {
        return std::remove(path.c_str()) == 0 ? true : false;
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
    void RedLog::NewNote(std::string *group, std::string *note) {
        // Getting necessary variables.

        std::string time = _GetCurrentTime();
        std::string res  = "\n";


        // Creating string.

        /// Inserting time.
        res += "[" + time + "]";

        /// Insering group if needed.
        if (*group != REDLOG_NO_GROUP) {
            res += "(" + *group + ")";
        }

        /// Inserting our note.
        res += " " + *note + ".";

        m_LogFile << res;
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

        std::string time = _GetCurrentTime();
        std::string res  = "\n";


        // Creating string.

        /// Inserting time.
        res += "[" + time + "]";

        /// Insering group if needed.
        if (group != REDLOG_NO_GROUP) {
            res += "(" + group + ")";
        }

        /// Inserting our note.
        res += " " + note + ".";

        m_LogFile << res;
    }
}


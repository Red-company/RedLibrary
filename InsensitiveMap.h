#ifndef RED_INSENSITIVEMAP_H
#define RED_INSENSITIVEMAP_H

#include <strings.h>
#include <string>
#include <map>

namespace Red {
    // Private.
    namespace _InsensitiveMap {
        struct CaseInsensitiveComparator {
            bool operator()(const std::string& a, const std::string& b) const noexcept {
                return ::strcasecmp(a.c_str(), b.c_str()) < 0;
            }
        };
    }

    // Insensitive map.
    template <typename T1, typename T2>
    using InsensitiveMap = std::map<T1, T2, _InsensitiveMap::CaseInsensitiveComparator>;
}

#endif // RED_INSENSITIVEMAP_H

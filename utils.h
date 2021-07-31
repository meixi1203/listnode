#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <vector>
#include <algorithm>

namespace utils {
static inline std::string trim_(const std::string &s) {
    std::string::const_iterator it = s.begin();
    while (it != s.end() && isspace(*it)) {
        it++;
    }

    std::string::const_reverse_iterator rit = s.rbegin();
    while (rit.base() != it && isspace(*rit)) {
        rit++;
    }

    return std::string(it, rit.base());
}

static inline std::vector<std::string> split(const std::string& str, char sep) {
	std::vector<std::string> res;
	std::string::const_iterator start = str.begin();
	std::string::const_iterator end = str.end();
	std::string::const_iterator next = find(start, end, sep);
	while (next != end) {
		res.emplace_back(start, next);
		start = next + 1;
		next = std::find(start, end, sep);
	}

	res.emplace_back(start, next);
	return res;
}
}
#endif // UTILS_H
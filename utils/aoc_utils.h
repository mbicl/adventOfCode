#pragma once

#include <string>
#include <vector>

namespace aoc {
	namespace str {
		std::string trim(std::string s) {
			while (s.size() && s.back() == ' ') {
				s.pop_back();
			}
			while (s.size() && s.front() == ' ')
				s.erase(0, 1);
			return s;
		}

		std::vector<std::string> split(std::string s, char sep = ' ') {
			std::string c;
			std::vector<std::string> res;
			for (char i : s) {
				if (i == sep) {
					if (c.empty())
						continue;
					res.push_back(c);
					c.clear();
				} else {
					c += i;
				}
			}
			if (c.size() > 0)
				res.push_back(c);
			return res;
		}

		template <typename T>
		std::string join(std::vector<T> v, std::string c) {
			std::string s;
			for (int i = 0; i < v.size(); ++i) {
				s += std::to_string(v[i]);
				if (i != v.size() - 1)
					s += c;
			}
			return s;
		}

		std::string remove_spaces(std::string s) {
			std::string res;
			for (char c : s) {
				if (c != ' ') res += c;
			}
			return res;
		}
	}; // namespace str
}; // namespace aoc
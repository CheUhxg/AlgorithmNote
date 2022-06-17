#include "kmp.h"

#include <algorithm>

namespace myalgorithm {

	std::vector<int>
		Kmp::GetNext(const std::string& pattern) const {
		std::vector<int> next(pattern.size());
		next[0] = -1;

		int j = -1;
		for (int i = 1; i < pattern.size(); ++i) {
			while (j != -1 && pattern[i] != pattern[j + 1]) {
				j = next[j];
			}
			if (pattern[i] == pattern[j + 1]) {
				++j;
			}
			next[i] = j;
		}
		return next;
	}

	int Kmp::FindFirst(const std::string& origin,
										const std::string& pattern) const {
		std::vector<int> next(GetNext(pattern));

		int j = -1;
		for (int i = 0; i < origin.size(); ++i) {
			while (j != -1 && origin[i] != pattern[j + 1]) {
				j = next[j];
			}
			if (origin[i] == pattern[j + 1]) {
				++j;
			}
			if (j == pattern.size() - 1) {
				return i + 1 - pattern.size();
			}
		}
		return -1;
	}

	int Kmp::FindLast(const std::string& origin,
										const std::string& pattern) const {
		std::string tmp_origin(origin);
		std::string tmp_pattern(pattern);

		std::reverse(tmp_origin.begin(), tmp_origin.end());
		std::reverse(tmp_pattern.begin(), tmp_pattern.end());

		return origin.size() - FindFirst(tmp_origin, tmp_pattern);
	}

}
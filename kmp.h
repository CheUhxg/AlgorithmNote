#ifndef KMP_H_
#define KMP_H_

#include <vector>
#include <string>

namespace myalgorithm {

class Kmp {
private:
	std::vector<int> GetNext(const std::string& origin) const;
public:
	explicit Kmp() = default;

	int FindFirst(const std::string& origin,
								const std::string& pattern) const;
	int FindLast(const std::string& origin,
								const std::string& pattern) const;
};	//	class Kmp

}	//	namespace myalgorithm

#endif
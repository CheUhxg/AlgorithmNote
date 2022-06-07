#ifndef STRASSEN_H_
#define STRASSEN_H_

#include <vector>

namespace myalgorithm {

class Strassen {
public:
	Strassen();

	std::vector<std::vector<int>>
		GetRandomMatrix(const int dimension) const;
	std::vector<std::vector<int>>
		MultiMatrix(std::vector<std::vector<int>>& lfs,
								std::vector<std::vector<int>>& rhs) const;
};

}

#endif	//	STRASSEN_H_
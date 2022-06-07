#ifndef STRASSEN_H_
#define STRASSEN_H_

#include <vector>

namespace myalgorithm {

class Strassen {
private:
	std::vector<std::vector<int>>
		MultiMatrix(std::vector<std::vector<int>>& lfs,
								std::vector<std::vector<int>>& rhs,
								const int x_start, const int y_start) const;
	std::vector<std::vector<int>>
		SetS(const std::vector<std::vector<int>>& lfs,
				 const int l_x, const int l_y,
				 const std::vector<std::vector<int>>& rhs,
				 const int r_x, const int r_y,
				 const bool is_add) const;
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
#ifndef STRASSEN_H_
#define STRASSEN_H_

#include <random>
#include <vector>

namespace myalgorithm {

class Strassen {
private:
	std::default_random_engine random_engine;
	std::uniform_int_distribution<int> uniform;

	void MultiMatrix(std::vector<std::vector<int>>& result,
									 const std::vector<std::vector<int>>& lfs,
									 const int l_x, const int l_y,
									 const std::vector<std::vector<int>>& rhs,
									 const int r_x, const int r_y) const;
	void MultiMatrix(std::vector<std::vector<int>>& result,
									 const int m1, const int n, const int m2,
									 const std::vector<std::vector<int>>& lfs,
									 const int l_x, const int l_y,
									 const std::vector<std::vector<int>>& rhs,
									 const int r_x, const int r_y) const;
	std::vector<std::vector<int>>
		SetS(const std::vector<std::vector<int>>& lfs,
				 const int l_x, const int l_y,
				 const std::vector<std::vector<int>>& rhs,
				 const int r_x, const int r_y,
				 const bool is_add, const int len) const;
	void AddMatrix(std::vector<std::vector<int>>& result,
									const int x, const int y,
									const std::vector<std::vector<int>>& lfs,
									const int l_x, const int l_y,
									const std::vector<std::vector<int>>& rhs,
									const int r_x, const int r_y,
									const bool is_add,
									const int len_x, const int len_y) const;
public:
	Strassen();

	std::vector<std::vector<int>>
		GetRandomMatrix(const int dimension);
	std::vector<std::vector<int>>
		MultiMatrix(std::vector<std::vector<int>>& lfs,
								std::vector<std::vector<int>>& rhs) const;
};

}

#endif	//	STRASSEN_H_
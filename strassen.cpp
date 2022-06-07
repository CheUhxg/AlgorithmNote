#include "strassen.h"
#include <random>
#include <ctime>
#include <cassert>

namespace myalgorithm {

Strassen::Strassen() {}

std::vector<std::vector<int>>
	Strassen::GetRandomMatrix(const int dimension) const {
	std::default_random_engine random_engine;
	std::uniform_int_distribution<int> uniform(INT_MIN, INT_MAX);
	random_engine.seed(time(NULL));

	std::vector<std::vector<int>> matrix(dimension, std::vector<int>(dimension));
	for (auto& arr : matrix) {
		for (auto& ele : arr) {
			ele = uniform(random_engine);
		}
	}
	return matrix;
}

std::vector<std::vector<int>>
	Strassen::MultiMatrix(std::vector<std::vector<int>>& lfs,
												std::vector<std::vector<int>>& rhs) const {
	assert(lfs.size() > 0 && rhs.size() > 0);
	assert(lfs.size() == lfs[0].size() && rhs.size() == rhs[0].size());
	assert(lfs.size() == rhs.size());

	return MultiMatrix(lfs, rhs, 0, 0);
}

std::vector<std::vector<int>>
	Strassen::MultiMatrix(std::vector<std::vector<int>>& lfs,
												std::vector<std::vector<int>>& rhs,
												const int x_start, const int y_start) const {
	std::vector<std::vector<int>> result(lfs);
	result.clear();

	int dimension = lfs.size();
	if (dimension % 2 == 0) {
		std::vector<std::vector<std::vector<int>>> S(11);
		S[1] = SetS(rhs, 0, dimension / 2,
								rhs, dimension / 2, dimension / 2,
								false);
		S[2] = SetS(lfs, 0, 0,
								lfs, 0, dimension / 2,
								true);
		S[3] = SetS(lfs, dimension / 2, 0,
								lfs, dimension / 2, dimension / 2,
								true);
		S[4] = SetS(rhs, dimension / 2, 0,
								rhs, 0, 0,
								false);
		S[5] = SetS(lfs, 0, 0,
								lfs, dimension / 2, dimension / 2,
								true);
		S[6] = SetS(rhs, 0, 0,
								rhs, dimension / 2, dimension / 2,
								true);
		S[7] = SetS(lfs, 0, dimension / 2,
								lfs, dimension / 2, dimension / 2,
								false);
		S[8] = SetS(rhs, dimension / 2, 0,
								rhs, dimension / 2, dimension / 2,
								true);
		S[9] = SetS(lfs, 0, 0,
								lfs, dimension / 2, 0,
								false);
		S[10] = SetS(rhs, 0, 0,
								 rhs, 0, dimension / 2,
								 true);
	}
	return result;
}

std::vector<std::vector<int>>
	Strassen::SetS(const std::vector<std::vector<int>>& lfs,
								 const int l_x, const int l_y,
								 const std::vector<std::vector<int>>& rhs,
								 const int r_x, const int r_y,
								 const bool is_add) const {
	int dimension = lfs.size();
	std::vector<std::vector<int>> S(dimension,
																	std::vector<int>(dimension));
	for (int i = 0; i < dimension / 2; ++i) {
		for (int j = 0; j < dimension / 2; ++j) {
			S[i][j] = lfs[l_x + i][l_y + j];
			S[i][j] += rhs[r_x + i][r_y + j] * (is_add ? 1 : -1);
		}
	}
	return S;
}

}

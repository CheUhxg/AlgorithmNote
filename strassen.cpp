#include "strassen.h"
#include <algorithm>
#include <ctime>
#include <cassert>

namespace myalgorithm {

Strassen::Strassen() 
		: uniform(-3, 3) {
	random_engine.seed(time(NULL)); 
}

std::vector<std::vector<int>>
	Strassen::GetRandomMatrix(const int dimension) {
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

	std::vector<std::vector<int>> result(lfs);
	MultiMatrix(result, lfs, 0, 0, rhs, 0, 0);
	return result;
}

void Strassen::MultiMatrix(std::vector<std::vector<int>>& result,
													 const std::vector<std::vector<int>>& lfs,
													 const int l_x, const int l_y,
													 const std::vector<std::vector<int>>& rhs,
													 const int r_x, const int r_y) const {
	int dim = result.size();
	if (dim == 1) {
		result[0][0] = lfs[l_x][l_y] * rhs[r_x][r_y];
		return;
	}
	if (dim % 2 == 0) {
		std::vector<std::vector<std::vector<int>>> S(11);
		S[1] = SetS(rhs, r_x, r_y + dim / 2,
								rhs, r_x + dim / 2, r_y + dim / 2,
								false, dim / 2);
		S[2] = SetS(lfs, l_x, l_y,
								lfs, l_x, l_y + dim / 2,
								true, dim / 2);
		S[3] = SetS(lfs, l_x + dim / 2, l_y,
								lfs, l_x + dim / 2, l_y + dim / 2,
								true, dim / 2);
		S[4] = SetS(rhs, r_x + dim / 2, r_y,
								rhs, r_x, r_y,
								false, dim / 2);
		S[5] = SetS(lfs, l_x, l_y,
								lfs, l_x + dim / 2, l_y + dim / 2,
								true, dim / 2);
		S[6] = SetS(rhs, r_x, r_y,
								rhs, r_x + dim / 2, r_y + dim / 2,
								true, dim / 2);
		S[7] = SetS(lfs, l_x, l_y + dim / 2,
								lfs, l_x + dim / 2, l_y + dim / 2,
								false, dim / 2);
		S[8] = SetS(rhs, r_x + dim / 2, r_y,
								rhs, r_x + dim / 2, r_y + dim / 2,
								true, dim / 2);
		S[9] = SetS(lfs, l_x, l_y,
								lfs, l_x + dim / 2, l_y,
								false, dim / 2);
		S[10] = SetS(rhs, r_x, r_y,
								 rhs, r_x, r_y + dim / 2,
								 true, dim / 2);

		std::vector<std::vector<std::vector<int>>> P(8);
		for (int i = 1; i <= 7; ++i) {
			P[i] = std::vector<std::vector<int>>(dim / 2,
				std::vector<int>(dim / 2, 0));
		}
		MultiMatrix(P[1], lfs, l_x, l_y, S[1], 0, 0);
		MultiMatrix(P[2], S[2], 0, 0, rhs, r_x + dim / 2, r_y + dim / 2);
		MultiMatrix(P[3], S[3], 0, 0, rhs, r_x, r_y);
		MultiMatrix(P[4], lfs, l_x + dim / 2, l_y + dim / 2, S[4], 0, 0);
		MultiMatrix(P[5], S[5], 0, 0, S[6], 0, 0);
		MultiMatrix(P[6], S[7], 0, 0, S[8], 0, 0);
		MultiMatrix(P[7], S[9], 0, 0, S[10], 0, 0);

		//C11
		AddMatrix(result, 0, 0, 
							P[5], 0, 0, 
							P[4], 0, 0, 
							true, dim / 2);
		AddMatrix(result, 0, 0, 
							result, 0, 0, 
							P[2], 0, 0, 
							false, dim / 2);
		AddMatrix(result, 0, 0, 
							result, 0, 0, 
							P[6], 0, 0, 
							true, dim / 2);
		//C12
		AddMatrix(result, 0, dim / 2,
							P[1], 0, 0, 
							P[2], 0, 0, 
							true, dim / 2);
		//C21
		AddMatrix(result, dim / 2, 0,
							P[3], 0, 0,
							P[4], 0, 0,
							true, dim / 2);
		//C22
		AddMatrix(result, dim / 2, dim / 2,
							P[5], 0, 0, P[1], 0, 0,
							true, dim / 2);
		AddMatrix(result, dim / 2, dim / 2,
							result, dim / 2, dim / 2,
							P[3], 0, 0, false, dim / 2);
		AddMatrix(result, dim / 2, dim / 2,
							result, dim / 2, dim / 2,
							P[7], 0, 0, false, dim / 2);
	}
}

std::vector<std::vector<int>>
	Strassen::SetS(const std::vector<std::vector<int>>& lfs,
								 const int l_x, const int l_y,
								 const std::vector<std::vector<int>>& rhs,
								 const int r_x, const int r_y,
								 const bool is_add, const int len) const {
	std::vector<std::vector<int>> S(len, std::vector<int>(len));
	AddMatrix(S, 0, 0, lfs, l_x, l_y, rhs, r_x, r_y, is_add, len);
	return S;
}

void Strassen::AddMatrix(std::vector<std::vector<int>>& result,
													const int x, const int y,
													const std::vector<std::vector<int>>& lfs,
													const int l_x, const int l_y,
													const std::vector<std::vector<int>>& rhs,
													const int r_x, const int r_y,
													const bool is_add, const int len) const {
	for (int i = 0; i < len; ++i) {
		for (int j = 0; j < len; ++j) {
			result[x + i][y + j] = lfs[l_x + i][l_y + j];
			result[x + i][y + j] += rhs[r_x + i][r_y + j] * (is_add ? 1 : -1);
		}
	}
}

}

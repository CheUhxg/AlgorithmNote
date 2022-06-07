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

		int dimension = lfs.size();
		std::vector<std::vector<int>> result;
		return result;
	}
}

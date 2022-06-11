#ifndef QUICK_SORT_H_
#define QUICK_SORT_H_

#include <vector>
#include <random>

namespace myalgorithm {

class QuickSort {
private:
	std::mt19937 gen{ std::random_device{}() };
	std::uniform_int_distribution<int> uniform;

	bool is_increase;

	template<typename T>
	void Sort(std::vector<T>& origin,
						const int start_index, 
						const int end_index,
						const bool is_random) {
		if (start_index >= end_index)
			return;

		int privot = Partition(origin, start_index, end_index, is_random);
		Sort(origin, start_index, privot - 1, is_random);
		Sort(origin, privot + 1, end_index, is_random);
	}

	template<typename T>
	int Partition(std::vector<T>& origin,
								const int start_index, 
								const int end_index,
								const bool is_random) {
		if (is_random) {
			decltype(uniform)::param_type param{ start_index, end_index };
			uniform.param(param);
			std::swap(origin[uniform(gen)], origin[end_index]);
		}

		T mid_value = origin[end_index];
		int index = start_index - 1;
		for (int i = start_index; i < end_index; ++i) {
			if (JudgeForOrder(mid_value, origin[i])) {
				std::swap(origin[i], origin[++index]);
			}
		}
		std::swap(origin[end_index], origin[++index]);
		return index;
	}

	template<typename T>
	inline bool JudgeForOrder(const T& lt, const T& rt) const {
		return is_increase == (lt > rt);
	}
public:
	QuickSort();

	template<typename T>
	void Sort(std::vector<T>& origin, 
						const bool is_random = true,
						const bool is_increase = true) {
		this->is_increase = is_increase;
		Sort(origin, 0, origin.size() - 1, is_random);
	}
};	//	class QuickSort

}	//	namespace myalgorithm

#endif	//	QUICK_SORT_H_
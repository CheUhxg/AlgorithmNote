#include "quicksort.h"
#include <ctime>
#include <limits>

namespace myalgorithm {

QuickSort::QuickSort()
	: is_increase(true) {}

template<typename T>
void QuickSort::GetRandomVector(std::vector<T>& origin) const {
	T type_max = std::numeric_limits<T>::max();
	T type_min = std::numeric_limits<T>::min();
	std::uniform_int_distribution<T> item_uniform(type_min, type_max);
	for (T& item : origin) {
		item = item_uniform(gen);
	}
}

template<typename T>
void QuickSort::Sort(std::vector<T>& origin,
										const bool is_random,
										const bool is_increase) const {
	this->is_increase = is_increase;
	Sort(origin, 0, origin.size(), is_random);
}

template<typename T>
void QuickSort::Sort(std::vector<T>& origin,
										const int start_index,
										const int end_index,
										const bool is_random) const {
	if (start_index >= end_index)
		return;

	int privot = Partition(origin, start_index, end_index, is_random);
	Sort(origin, start_index, privot - 1);
	Sort(origin, privot + 1, end_index);
}

template<typename T>
void QuickSort::Partition(std::vector<T>& origin,
													const int start_index,
													const int end_index,
													const bool is_random) const {
	if (is_random) {
		decltype(uniform)::param_type param{ start_index, end_index };
		uniform.param(param);
		std::swap(origin[uniform(gen)], origin.back());
	}

	T mid_value = origin.back();
	int index = start_index - 1;
	for (int i = start_index; i < end_index; ++i) {
		if (JudgeForOrder(mid_value, origin[i])) {
			std::swap(origin[i], origin[++index]);
		}
	}
	std::swap(origin.back(), origin[++index]);
	return index;
}

template<typename T>
bool QuickSort::JudgeForOrder(const T& lt, const T& rt) {
	return is_increase == (lt > rt);
}

}
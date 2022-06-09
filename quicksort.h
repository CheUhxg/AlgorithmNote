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
						const bool is_random) const;

	template<typename T>
	void Partition(std::vector<T>& origin,
								const int start_index, 
								const int end_index,
								const bool is_random) const;

	template<typename T>
	inline bool JudgeForOrder(const T& lt, const T& rt);
public:
	QuickSort();

	template<typename T>
	void GetRandomVector(std::vector<T>& origin) const;

	template<typename T>
	void Sort(std::vector<T>& origin, 
						const bool is_random,
						const bool is_increase = true) const;
};	//	class QuickSort

}	//	namespace myalgorithm

#endif	//	QUICK_SORT_H_
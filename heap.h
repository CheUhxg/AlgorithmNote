#ifndef HEAP_H_
#define HEAP_H_

#include <vector>

namespace myalgorithm {
class Heap {
private:
	using size_t = unsigned int;

	std::vector<int> heap_;
	size_t tail_index_;
	const bool big_heap_;

	void MakeHeap();
	void DownAdjust(const int begin_index, const int end_index);
	void UpAdjust(const int begin_index, const int end_index);
	bool JudgeForOrder(const int left_value, const int right_value) const;
public:
	explicit Heap(const std::vector<int>& heap, const bool isBigHeap = true);

	void Pop();
	void Push(const int val);
	void Sort();
	void Show() const;
};	// class Heap
}	//	namespace myalgorithm

#endif	//	HEAP_H_
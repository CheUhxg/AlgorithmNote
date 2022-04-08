#include "heap.h"
#include <assert.h>
#include <iostream>

namespace myalgorithm {
	Heap::Heap(const std::vector<int>& heap, bool isBigHeap)
		: heap_(heap),
			tail_index_(heap.size() - 1),
			big_heap_(isBigHeap) {
		MakeHeap();
	}

	void Heap::MakeHeap() {
		for (int i = heap_.size() / 2; i >= 1; --i) {
			DownAdjust(i, tail_index_);
		}
	}

	void Heap::DownAdjust(const int begin_index, const int end_index) {
		assert(end_index <= tail_index_);

		int father = begin_index, child = father * 2;
		while (child <= end_index) {
			if (child != end_index && JudgeForOrder(heap_[child + 1], heap_[child])) {
				++child;
			}

			if (JudgeForOrder(heap_[father], heap_[child]))
				break;
			std::swap(heap_[child], heap_[father]);
			father = child;
			child = child * 2;
		}
	}

	void Heap::UpAdjust(const int begin_index, const int end_index) {
		assert(end_index >= 1);

		int child = end_index, father = child / 2;
		while (father >= begin_index) {
			if (JudgeForOrder(heap_[father], heap_[child]))
				break;
			std::swap(heap_[child], heap_[father]);
			child = father;
			father = child / 2;
		}
	}

	bool Heap::JudgeForOrder(const int up_value, const int down_value) const {
		return big_heap_ == up_value > down_value;
	}

	void Heap::Pop() {
		assert(tail_index_ >= 1);

		heap_[1] = heap_[tail_index_--];
		DownAdjust(1, tail_index_);
	}

	void Heap::Push(const int val) {
		if (++tail_index_ < heap_.size()) {
			heap_[tail_index_] = val;
		} else {
			heap_.push_back(val);
		}
		UpAdjust(1, tail_index_);
	}

	void Heap::Sort() {
		MakeHeap();

		for (int i = tail_index_; i > 1; --i) {
			std::swap(heap_[i], heap_[1]);
			DownAdjust(1, i - 1);
		}
	}

	void Heap::Show() const {
		for (int i = 1; i <= tail_index_; ++i) {
			std::cout << heap_[i] << " ";
		}
		std::cout << std::endl;
	}
}
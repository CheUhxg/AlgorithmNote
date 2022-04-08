#include "disjointset.h"

namespace myalgorithm {
	DisJointSet::DisJointSet(const int set_size)
		: father_(set_size) {
		for (int i = 0; i < set_size; ++i) {
			father_[i] = i;
		}
	}

	const int DisJointSet::FindFather(int child_index) {
		int father_index = child_index;
		while (father_[father_index] != father_index) {
			father_index = father_[father_index];
		}
		while (father_[child_index] != child_index) {
			int tmp = father_[child_index];
			father_[child_index] = father_index;
			child_index = tmp;
		}
		return father_index;
	}

	void DisJointSet::Union(const int primary_child, const int secondary_child) {
		const int primary_father = FindFather(primary_child);
		const int secondary_father = FindFather(secondary_child);
		if (primary_father != secondary_father)
			father_[secondary_father] = primary_father;
	}
}
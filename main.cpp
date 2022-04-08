#include "avltree.h"
#include "disjointset.h"
#include "heap.h"
#include <iostream>
#include <algorithm>
#include <unordered_set>

using myalgorithm::AVLTree;
using myalgorithm::DisJointSet;
using myalgorithm::Heap;

void TestAVLTree() {
	AVLTree avltree;
	std::vector<int> datas{ 1,2,3,4,5,6,7,8 };
	AVLTree::AVLNode* root = avltree.Create(datas);
	std::cout << (avltree.Search(3, root) == nullptr) << std::endl;
	avltree.Show(root);
}

void TestDisJointSet() {
	int n, m;
	std::cin >> n >> m;

	DisJointSet disjointset(n+1);
	while (m--) {
		int primary_friend, secondary_friend;
		std::cin >> primary_friend >> secondary_friend;
		if (primary_friend > secondary_friend)
			std::swap(primary_friend, secondary_friend);
		disjointset.Union(primary_friend, secondary_friend);
	}

	std::unordered_set<int> set_roots;
	for (int i = 1; i <= n; ++i) {
		int root = disjointset.FindFather(i);
		if (set_roots.count(root) == 0) {
			set_roots.insert(root);
		}
	}
	std::cout << set_roots.size() << std::endl;
}

void TestHeap() {
	std::vector<int> origin{ 0,3,6,4,3,7,9,1,2 };
	Heap heap(origin, false);

	heap.Show();
	heap.Push(5);
	heap.Show();
	heap.Sort();
	heap.Show();
}

int main() {
	//TestAVLTree();
	//TestDisJointSet();
	TestHeap();
}
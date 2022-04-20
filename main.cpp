#include "avltree.h"
#include "disjointset.h"
#include "heap.h"
#include "huffmantree.h"
#include "adjacencymatrix.h"
#include "adjacencytable.h"
#include <iostream>
#include <algorithm>
#include <unordered_set>

using myalgorithm::AVLTree;
using myalgorithm::DisJointSet;
using myalgorithm::Heap;
using myalgorithm::HuffmanTree;
using myalgorithm::AdjacencyMatrix;
using myalgorithm::AdjacencyTable;

void TestAVLTree() {
	AVLTree avltree;
	std::vector<int> datas{ 1,2,3,4,5,6,7,8 };
	AVLTree::AVLNode* root = avltree.Create(datas);
	std::cout << (avltree.Search(3, root) == nullptr) << std::endl;
	avltree.Show(root);
	avltree.Delete(root);
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

void TestHuffmanTree() {
	HuffmanTree huffmantree(std::vector<int>{ 6, 1, 2, 3, 4, 5 });
	huffmantree.Show();
	std::cout << huffmantree.sum() << std::endl;
	std::cout << huffmantree.Decode(huffmantree.Encode("AABCDDBCA")) << std::endl;
	huffmantree.Show();
}

void TestAdjacencyMatrix() {
	AdjacencyMatrix adjmat(6);
	adjmat.UpdateEdge(0, 1, 1);
	adjmat.UpdateEdge(0, 2, 1);
	adjmat.UpdateEdge(1, 3, 1);
	adjmat.UpdateEdge(1, 4, 1);
	adjmat.UpdateEdge(2, 1, 1);
	adjmat.UpdateEdge(2, 4, 1);
	adjmat.UpdateEdge(4, 3, 1);
	adjmat.UpdateEdge(4, 5, 1);
	adjmat.UpdateEdge(5, 3, 1);
	adjmat.Show();

	std::vector<size_t> ret_vertices;
	adjmat.BFS(0, ret_vertices);
}

void TestAdjacencyTable() {
	AdjacencyTable adjtab(6);
	adjtab.UpdateEdge(0, 1, 1);
	adjtab.UpdateEdge(0, 2, 1);
	adjtab.UpdateEdge(1, 3, 1);
	adjtab.UpdateEdge(1, 4, 1);
	adjtab.UpdateEdge(2, 1, 1);
	adjtab.UpdateEdge(2, 4, 1);
	adjtab.UpdateEdge(4, 3, 1);
	adjtab.UpdateEdge(4, 5, 1);
	adjtab.UpdateEdge(5, 3, 1);
	adjtab.Show();

	std::vector<size_t> ret_vertices;
	adjtab.BFS(0, ret_vertices);
}

int main() {
	//TestAVLTree();
	//TestDisJointSet();
	//TestHeap();
	//TestHuffmanTree();
	TestAdjacencyMatrix();
	TestAdjacencyTable();
}
#include "avltree.h"
#include "disjointset.h"
#include "heap.h"
#include "huffmantree.h"
#include "adjacencymatrix.h"
#include "adjacencytable.h"
#include "strassen.h"
#include "timer.h"
#include <iostream>
#include <algorithm>
#include <unordered_set>

using myalgorithm::AVLTree;
using myalgorithm::DisJointSet;
using myalgorithm::Heap;
using myalgorithm::HuffmanTree;
using myalgorithm::AdjacencyMatrix;
using myalgorithm::AdjacencyTable;
using myalgorithm::Strassen;
using myalgorithm::Timer;

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
	adjmat.UpdateEdge(0, 4, 4);
	adjmat.UpdateEdge(0, 3, 4);
	adjmat.UpdateEdge(1, 3, 2);
	adjmat.UpdateEdge(2, 5, 1);
	adjmat.UpdateEdge(3, 2, 2);
	adjmat.UpdateEdge(3, 4, 3);
	adjmat.UpdateEdge(4, 5, 3);
	adjmat.Show();

	std::vector<size_t> ret_path;
	std::vector<int> ret_weights;
	adjmat.Dijkstra(0, ret_path, ret_weights);
}

void TestAdjacencyTable() {
	AdjacencyTable adjtab(6);
	adjtab.UpdateEdge(0, 1, 1);
	adjtab.UpdateEdge(0, 4, 4);
	adjtab.UpdateEdge(0, 3, 4);
	adjtab.UpdateEdge(1, 3, 2);
	adjtab.UpdateEdge(2, 5, 1);
	adjtab.UpdateEdge(3, 2, 2);
	adjtab.UpdateEdge(3, 4, 3);
	adjtab.UpdateEdge(4, 5, 3);
	adjtab.Show();

	std::vector<size_t> ret_path;
	std::vector<int> ret_weights;
	adjtab.Dijkstra(0, ret_path, ret_weights);
}

void TestPrime() {
	AdjacencyTable adjtab(6);
	adjtab.UpdateEdge(0, 1, 1, false);
	adjtab.UpdateEdge(0, 4, 4, false);
	adjtab.UpdateEdge(0, 3, 4, false);
	adjtab.UpdateEdge(1, 3, 2, false);
	adjtab.UpdateEdge(2, 5, 1, false);
	adjtab.UpdateEdge(3, 2, 2, false);
	adjtab.UpdateEdge(3, 4, 3, false);
	adjtab.UpdateEdge(4, 5, 3, false);

	std::cout << adjtab.Prime() << std::endl;
}

void TestStrassen() {
	Strassen strassen;
	int matrix_dimension = 100;
	while (true) {
		auto m1 = strassen.GetRandomMatrix(matrix_dimension);
		auto m2 = strassen.GetRandomMatrix(matrix_dimension);

		Timer::Start();
		std::cout << "Test " << matrix_dimension
			<< '*' << matrix_dimension << " matrix: ";
		auto res = strassen.MultiMatrix(m1, m2);
		Timer::End();

		double duration = Timer::GetDuration();
		std::cout << duration << "ms" << std::endl;
		if (duration > 1000 * 100)
			break;

		matrix_dimension += 100;
	}

	//for (const auto& arr : m1) {
	//	for (const int num : arr) {
	//		std::cout << num << ',';
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	//for (const auto& arr : m2) {
	//	for (const int num : arr) {
	//		std::cout << num << ',';
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
	//for (const auto& arr : res) {
	//	for (const int num : arr) {
	//		std::cout << num << ',';
	//	}
	//	std::cout << std::endl;
	//}
	//std::cout << std::endl;
}

int main() {
	//TestAVLTree();
	//TestDisJointSet();
	//TestHeap();
	//TestHuffmanTree();
	//TestAdjacencyMatrix();
	//TestAdjacencyTable();
	//TestPrime();
	TestStrassen();
}
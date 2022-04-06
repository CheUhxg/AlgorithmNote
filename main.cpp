#include "avltree.h"
#include <vector>
#include <iostream>

using myalgorithm::AVLTree;

void TestAVLTree() {
	AVLTree avltree;
	std::vector<int> datas{ 1,2,3,4,5,6,7,8 };
	AVLTree::AVLNode* root = avltree.Create(datas);
	std::cout << (avltree.Search(3, root) == nullptr) << std::endl;
	avltree.Show(root);
}

int main() {
	TestAVLTree();
}
#ifndef AVL_TREE_H_
#define AVL_TREE_H_

#include <vector>

namespace myalgorithm {
class AVLTree {
public:
	struct AVLNode
	{
		int val_, height_;
		AVLNode* left_, * right_;

		explicit AVLNode(const int val);
	};

	AVLNode* Create(const std::vector<int>& datas);
	AVLNode* Search(const int val, AVLNode* root);
	AVLNode* Insert(const int val, AVLNode* root);
	void Delete(AVLNode* root);
	void Show(const AVLNode* root) const;

private:
	AVLNode* new_node(const int val);

	int get_height(AVLNode* root);
	int get_balance_factor(AVLNode* root);
	void update_height(AVLNode* root);

	AVLNode* LeftRotation(AVLNode* root);
	AVLNode* RightRotation(AVLNode* root);

	void Show(const AVLNode* root, const int level) const;
};	// class AVLTree
}	//	namespace myalgorithm

#endif	//AVL_TREE_H_

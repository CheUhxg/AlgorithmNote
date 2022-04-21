#include "avltree.h"
#include <queue>
#include <iostream>
#include <algorithm>

using std::vector;

namespace myalgorithm {

AVLTree::AVLNode::AVLNode(const int val)
	: val_(val), height_(1),
		left_(nullptr), right_(nullptr) {}

AVLTree::AVLNode* AVLTree::new_node(const int val) {
	return new AVLNode(val);
}

void AVLTree::Delete(AVLNode* root) {
	if (root == nullptr)
		return;
	Delete(root->left_);
	Delete(root->right_);
	delete root;
}

int AVLTree::get_height(AVLNode* root) {
	if (root == nullptr)
		return 0;
	return root->height_;
}

int AVLTree::get_balance_factor(AVLNode* root) {
	return get_height(root->left_) - get_height(root->right_);
}

void AVLTree::update_height(AVLNode* root) {
	root->height_ = std::max(get_height(root->left_), get_height(root->right_)) + 1;
}

AVLTree::AVLNode* AVLTree::Create(const std::vector<int>& datas) {
	AVLNode* root = nullptr;
	for (const int d : datas) {
		root = Insert(d, root);
	}
	return root;
}

AVLTree::AVLNode* AVLTree::Search(const int val, AVLNode* root) {
	if (root == nullptr)
		return nullptr;

	AVLNode* result = nullptr;

	if (val == root->val_) {
		return root;
	}
	else if (val > root->val_) {
		result = Search(val, root->right_);
	}
	else if (val < root->val_) {
		result = Search(val, root->left_);
	}
	return result;
}

AVLTree::AVLNode* AVLTree::Insert(const int val, AVLNode* root) {
	if (root == nullptr)
		return new_node(val);
	if (val > root->val_) {
		root->right_ = Insert(val, root->right_);
		update_height(root);
		if (get_balance_factor(root) == -2) {
			if (get_balance_factor(root->right_) == -1) {
				root = LeftRotation(root);
			}
			else if (get_balance_factor(root->right_) == 1) {
				root->right_ = RightRotation(root->right_);
				root = LeftRotation(root);
			}
		}
	} else {
		root->left_ = Insert(val, root->left_);
		update_height(root);
		if (get_balance_factor(root) == 2) {
			if (get_balance_factor(root->left_) == 1) {
				root = RightRotation(root);
			}	else if (get_balance_factor(root->left_) == -1) {
				root->left_ = LeftRotation(root->left_);
				root = RightRotation(root);
			}
		}
	}
	return root;
}

void AVLTree::Show(const AVLNode* root) const{
	if (root == nullptr)
		return;

	Show(root, 0);
}

void AVLTree::Show(const AVLNode* root, const int level) const {
	for (int i = 0; i < level; ++i) {
		std::cout << "->";
	}
	std::cout << root->val_ << std::endl;
	if (root->left_ != nullptr)
		Show(root->left_, level + 1);
	if (root->right_ != nullptr)
		Show(root->right_, level + 1);
}

AVLTree::AVLNode* AVLTree::LeftRotation(AVLNode* root) {
	if (root == nullptr || root->right_ == nullptr)
		return nullptr;
	AVLNode* tmp = root->right_;
	root->right_ = tmp->left_;
	tmp->left_ = root;
	return tmp;
}

AVLTree::AVLNode* AVLTree::RightRotation(AVLNode* root) {
	if (root == nullptr || root->left_ == nullptr)
		return nullptr;
	AVLNode* tmp = root->left_;
	root->left_ = tmp->right_;
	tmp->right_ = root;
	return tmp;
}

}
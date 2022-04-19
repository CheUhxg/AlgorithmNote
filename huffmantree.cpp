#include "huffmantree.h"
#include <queue>
#include <iostream>

namespace myalgorithm {

HuffmanTree::HuffmanTree(const std::vector<int>& weights) 
	: p_tree_head_(InitTree(weights)),
		sum_(0) {

}

HuffmanTree::~HuffmanTree() {
	DeleteTree(p_tree_head_);
}

bool 
HuffmanTree::CompareNode::operator()(const HuffmanNode* lfs, 
																					const HuffmanNode* rfs) {
	return lfs->val_ > rfs->val_;
}

HuffmanTree::HuffmanNode* 
HuffmanTree::InitTree(const std::vector<int>& weights, 
											const std::vector<char>& alphas) {
	if (weights.empty())
		return nullptr;

	std::vector<HuffmanNode*> nodes;
	for (int i = 0; i < weights.size(); ++i) {
		HuffmanNode* new_end_node = nullptr;
		if (alphas.empty())
			new_end_node = new HuffmanNode(weights[i], '*');
		else
			new_end_node = new HuffmanNode(weights[i], alphas[i]);
		nodes.push_back(new_end_node);
	}

	std::priority_queue<HuffmanNode*, 
											std::vector<HuffmanNode*>, 
											CompareNode> queue_node(nodes.begin(), nodes.end());
	while (queue_node.size() >= 2) {
		HuffmanNode* left_node = queue_node.top();
		queue_node.pop();
		HuffmanNode* right_node = queue_node.top();
		queue_node.pop();

		HuffmanNode* new_mid_node = new HuffmanNode(left_node->val_ + right_node->val_, 
																								'.', 
																								left_node, 
																								right_node);
		queue_node.push(new_mid_node);
		sum_ += new_mid_node->val_;
	}
	return queue_node.top();
}

void HuffmanTree::DeleteTree(HuffmanNode* root) {
	if (root == nullptr)
		return;
	DeleteTree(root->left_);
	DeleteTree(root->right_);
	delete root;
}

int HuffmanTree::sum() const {
	return sum_;
}

void HuffmanTree::Show() const {
	if (p_tree_head_ == nullptr)
		return;

	std::queue<HuffmanNode*> queue_node;
	queue_node.push(p_tree_head_);
	while (!queue_node.empty()) {
		size_t queue_size = queue_node.size();
		for (int i = 0; i < queue_size; ++i) {
			HuffmanNode* tmp = queue_node.front();
			queue_node.pop();

			if (tmp == nullptr) {
				std::cout << ". ";
				continue;
			}
			std::cout << tmp->val_ << " ";
			queue_node.push(tmp->left_);
			queue_node.push(tmp->right_);
		}
		std::cout << std::endl;
	}
}

std::string HuffmanTree::Encode(const std::string& origin_str) {
	std::unordered_map<char, int> hash_map_weight;
	for (const auto& c : origin_str) {
		++hash_map_weight[c];
	}

	std::vector<int> weights(hash_map_weight.size());
	std::vector<char> alphas(hash_map_weight.size());
	size_t index = 0;
	for (const auto& iter : hash_map_weight) {
		alphas[index] = iter.first;
		weights[index++] = iter.second;
	}

	DeleteTree(p_tree_head_);
	p_tree_head_ = InitTree(weights, alphas);

	hash_map_code.clear();
	std::string now_code;
	GetHash(p_tree_head_, now_code);

	std::string ret_str;
	for (const auto& c : origin_str) {
		ret_str.append(hash_map_code[c]);
	}
	return ret_str;
}

std::string HuffmanTree::Decode(const std::string& origin_str) {
	std::unordered_map<std::string, char> hash_map_code_reverse;
	for (const auto& iter : hash_map_code) {
		hash_map_code_reverse[iter.second] = iter.first;
	}

	std::string ret_str;
	size_t index_high = 1, index_low = 0;
	while (index_high <= origin_str.size()) {
		std::string test_key(origin_str.substr(index_low, index_high - index_low));
		if (hash_map_code_reverse.count(test_key) > 0) {
			ret_str.push_back(hash_map_code_reverse[test_key]);
			index_low = index_high;
		}
		++index_high;
	}
	return ret_str;
}

void HuffmanTree::GetHash(const HuffmanNode* root, std::string& now_code) {
	if (root == nullptr)
		return;
	if (root->key_ == '.') {
		now_code.push_back('0');
		GetHash(root->left_, now_code);
		now_code.pop_back();
		now_code.push_back('1');
		GetHash(root->right_, now_code);
		now_code.pop_back();
		return;
	}
	hash_map_code[root->key_] = now_code;
}

}
#ifndef HUFFMAN_TREE_H_
#define HUFFMAN_TREE_H_

#include <string>
#include <vector>
#include <unordered_map>

namespace myalgorithm {
class HuffmanTree
{
private:
	int sum_;
	std::unordered_map<char, std::string> hash_map_code;
	struct HuffmanNode
	{
		int val_;
		char key_;
		HuffmanNode* left_, * right_;
		explicit HuffmanNode(const int val, const char key)
				: val_(val),
					key_(key),
					left_(nullptr),
					right_(nullptr) {}
		explicit HuffmanNode(const int val, const char key, 
												 HuffmanNode* left, HuffmanNode* right)
			: val_(val),
				key_(key),
				left_(left),
				right_(right) {}
	}*p_tree_head_;

	struct CompareNode {
		bool operator()(const HuffmanNode* lfs, const HuffmanNode* rfs);
	};

	HuffmanNode* InitTree(const std::vector<int>& weights, 
												const std::vector<char>& = std::vector<char>());
	void DeleteTree(HuffmanNode* root);
	void GetHash(const HuffmanNode* root, std::string& now_code);
public:
	explicit HuffmanTree(const std::vector<int>& weights);
	~HuffmanTree();

	int sum() const;
	void Show() const;

	std::string Encode(const std::string& origin_str);
	std::string Decode(const std::string& origin_str);
};	//	class HuffmanTree
}	//	namespace myalgorithm


#endif	//	HUFFMAN_TREE_H_
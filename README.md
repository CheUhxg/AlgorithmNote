# AlgorithmNote

## AVLTree

> 平衡二叉树

* **Data**

```c++
struct AVLNode
{
int val_, height_;
AVLNode* left_, * right_;

explicit AVLNode(const int val);
};
```

* **public function**

```c++
AVLNode* Create(const std::vector<int>& datas);
AVLNode* Search(const int val, AVLNode* root);
AVLNode* Insert(const int val, AVLNode* root);
void Delete(AVLNode* root);
void Show(const AVLNode* root);
```

* **private function**

```c++
AVLNode* new_node(const int val);

int get_height(AVLNode* root);
int get_balance_factor(AVLNode* root);
void update_height(AVLNode* root);

AVLNode* LeftRotation(AVLNode* root);
AVLNode* RightRotation(AVLNode* root);
```

## DisJointSet

> 并查集

* **Data**

```c++
std::vector<int> father;
```

* **public function**

```c++
explicit DisJointSet(const int set_size);

const int FindFather(int child_index);
void Union(const int primary_child, const int secondary_child);
```

## Heap

> 堆

* **Data**

```C++
using size_t = unsigned int;

std::vector<int> heap_;
size_t tail_index_;
bool big_heap_;
```

* **public function**

```c++
explicit Heap(const std::vector<int>& heap, const bool isBigHeap = true);

void Pop();
void Push(const int val);
void Sort();
void Show() const;
```

* **private function**

```c++
void MakeHeap();
void DownAdjust(const int begin_index, const int end_index);
void UpAdjust(const int begin_index, const int end_index);
bool JudgeForOrder(const int left_value, const int right_value) const;
```

# HuffmanTree

> 哈夫曼树

* **Data**

```C++
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
```

* **public function**

```C++
explicit HuffmanTree(const std::vector<int>& weights);
~HuffmanTree();

int sum() const;
void Show() const;

std::string Encode(const std::string& origin_str);
std::string Decode(const std::string& origin_str);
```

* **private function**

```C++
struct CompareNode {
    bool operator()(const HuffmanNode* lfs, const HuffmanNode* rfs);
};

HuffmanNode* InitTree(const std::vector<int>& weights, 
                      const std::vector<char>& = std::vector<char>());
void DeleteTree(HuffmanNode* root);
void GetHash(const HuffmanNode* root, std::string& now_code);
```


#ifndef BUCKET_SORT_H_
#define BUCKET_SORT_H_

#include <vector>
#include <random>

namespace myalgorithm {

class BucketSort {
private:
	static const int default_size_ = 500;
	int bucket_size_;
	struct Bucket
	{
		int value;
		Bucket* next;
		Bucket(const int v = 0, Bucket* n = nullptr)
			: value(v), next(n) {}
	};

	void Insert(std::vector<Bucket*>& buckets, const int num) const;
	void Combine(std::vector<Bucket*>& buckets, 
							 std::vector<int>& origin) const;

public:
	explicit BucketSort(const int size = default_size_);

	void Sort(std::vector<int>& origin) const;
};	//	class BucketSort

}	//	namespace myalgorithm

#endif	//	BUCKET_SORT_H_
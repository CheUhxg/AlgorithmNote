#include "bucketsort.h"

namespace myalgorithm {

BucketSort::BucketSort(const int size)
	: bucket_size_(default_size_) {}

void BucketSort::Sort(std::vector<int>& origin) const {
	int max_item = *(std::max_element(origin.begin(), origin.end()));
	std::vector<Bucket*> buckets(max_item / bucket_size_ + 1, nullptr);

	for (const int num : origin) {
		Insert(buckets, num);
	}

	Combine(buckets, origin);
}

void BucketSort::Insert(std::vector<Bucket*>& buckets, 
												const int num) const {
	int index = num / bucket_size_;
	if (buckets[index] == nullptr) {
		buckets[index] = new Bucket;
	}

	Bucket* pre = buckets[index];
	Bucket*cur = pre->next;

	while (cur) {
		if (cur->value > num) {
			break;
		}
		pre = cur;
		cur = cur->next;
	}
	cur = new Bucket(num, cur);
	pre->next = cur;
}

void BucketSort::Combine(std::vector<Bucket*>& buckets,
												 std::vector<int>& origin) const {
	int index = 0;
	for (Bucket* bucket : buckets) {
		if (bucket != nullptr) {
			bucket = bucket->next;
			while (bucket) {
				origin[index++] = bucket->value;
				bucket = bucket->next;
			}
		}
	}
}

}
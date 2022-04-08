#ifndef DISJOINT_SET_H_
#define DISJOINT_SET_H_

#include <vector>

namespace myalgorithm {
class DisJointSet
{
private:
	std::vector<int> father_;

public:
	explicit DisJointSet(const int set_size);

	const int FindFather(int child_index);
	void Union(const int primary_child, const int secondary_child);
};	//	class DisJointSet
}	//	namespace myalgorithm

#endif	//	DISJOINT_SET_H_
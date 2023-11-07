#ifndef SORTING_ALGORITHMS_MERGESORT_H
#define SORTING_ALGORITHMS_MERGESORT_H

#include <vector>
#include <iterator>
#include <algorithm>

template<typename It, typename Compare = std::less<typename It::value_type>>
void custom_merge(It start, It mid, It end, Compare compare = Compare())
{
	std::vector<typename std::iterator_traits<It>::value_type> merged;
	auto left = start;
	auto right = mid;
	while(left != mid && right != end)
	{
		if(compare(*left, *right))
		{
			merged.push_back(*left);
			++left;
		}else
		{
			merged.push_back(*right);
			++right;
		}
	}
	while (left != mid) {
		merged.push_back(*left);
		++left;
	}
	while (right != end) {
		merged.push_back(*right);
		++right;
	}
	std::copy(merged.begin(), merged.end(), start);
}


template<typename Iterator, typename Compare = std::less<typename Iterator::value_type>>
void mergesort(Iterator left, Iterator right, Compare compare = Compare())
{
	if(std::distance(left, right) <= 1) return;
	auto mid = std::next(left, std::distance(left, right) / 2);
	mergesort(left, mid, compare);
	mergesort(mid, right, compare);
	custom_merge(left, mid, right, compare);
}

#endif //SORTING_ALGORITHMS_MERGESORT_H

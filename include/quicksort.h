#ifndef SORTING_ALGORITHMS_QUICKSORT_H
#define SORTING_ALGORITHMS_QUICKSORT_H

#include <iterator>
#include <algorithm>


template<typename Iterator>
Iterator getPivot(Iterator left, Iterator right)
{
	Iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2);
	Iterator last = std::prev(right);

	if (*mid < *left) {
		std::iter_swap(mid, left);
	}
	if (*last < *mid) {
		std::iter_swap(last, mid);
	}
	if (*last < *left) {
		std::iter_swap(last, left);
	}

	return mid;
}


template<typename Iterator, typename Compare>
std::pair<Iterator, Iterator> custom_partition(Iterator left, Iterator right, Compare compare)
{
	auto head = left, bend = std::prev(right), tail = bend, pivot = getPivot(left, right);
	auto pivot_val = *pivot;
	while (head <= tail) {
		while (compare(*head, pivot_val)) ++head;
		while (compare(pivot_val, *tail)) --tail;
		if (head <= tail) {
			std::iter_swap(head, tail);
			if(head < bend) ++head;
			if(tail > left)--tail;
		}
	}
	return {head, tail};
}


template<typename Iterator, typename Compare = std::less<typename Iterator::value_type>>
void quicksort(Iterator left, Iterator right, Compare compare = Compare())
{
	if(std::distance(left, right) <= 1) return;
	auto [head, tail] = custom_partition(left, right, compare);
	if (left < tail) {
		quicksort(left, std::next(tail));
	}
	if (head < std::prev(right)) {
		quicksort(head, right);
	}
}
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertService.tpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:36:28 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 22:04:13 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_INSERT_SERVICE_TPP
#define MERGE_INSERT_SERVICE_TPP

#include <algorithm>
#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename Container>
MergeInsertService<Container>::MergeInsertService(
    const MergeInsertService& /*unused*/) {}

template <typename Container>
MergeInsertService<Container>::~MergeInsertService() {}

template <typename Container>
MergeInsertService<Container>& MergeInsertService<Container>::operator=(
    const MergeInsertService& /*unused*/) {
  throw std::runtime_error("MergeInsertService assignment is not allowed");
}

template <typename Container>
void MergeInsertService<Container>::sort(Container& container) {
  size_t containerSize = container.size();
  if (containerSize <= 1) {
    return;
  }

  createPairs(container);

  Container larger;
  for (size_t i = 0; i < containerSize; i += 2) {
    larger.push_back(container[i]);
  }

  sortRecursive(larger);

  Container smaller;
  for (size_t i = 1; i < containerSize; i += 2) {
    smaller.push_back(container[i]);
  }

  insertSmaller(larger, smaller.size(), smaller);
  container = larger;
}

template <typename Container>
void MergeInsertService<Container>::createPairs(Container& container) {
  size_t containerSize = container.size();
  for (size_t i = 0; i + 1 < containerSize; i += 2) {
    if (container[i] > container[i + 1]) {
      std::swap(container[i], container[i + 1]);
    }
  }
}

template <typename Container>
void MergeInsertService<Container>::sortRecursive(Container& larger) {
  size_t largeSize = larger.size();
  if (largeSize <= 1) {
    return;
  }

  createPairs(larger);

  Container subLarger;
  for (size_t i = 0; i < largeSize; i += 2) {
    subLarger.push_back(larger[i]);
  }
  sortRecursive(subLarger);
  Container subSmaller;
  for (size_t i = 1; i < largeSize; i += 2) {
    subSmaller.push_back(larger[i]);
  }
  insertSmaller(subLarger, subSmaller.size(), subSmaller);
  larger = subLarger;
}

template <typename Container>
void MergeInsertService<Container>::insertSmaller(Container& larger,
                                                  size_t smallerSize,
                                                  Container& smaller) {
  if (smallerSize == 0) {
    return;
  }

  int value = smaller[0];
  typename Container::iterator pos =
      binarySearchPosition(larger.begin(), larger.end(), value);
  larger.insert(pos, value);

  if (smallerSize == 1) {
    return;
  }

  std::vector<size_t> order = generateInsertionSequence(smallerSize);
  for (size_t i = 0; i < order.size(); ++i) {
    value = smaller[order[i]];
    pos = binarySearchPosition(larger.begin(), larger.end(), value);
    larger.insert(pos, value);
  }
}

template <typename Container>
typename Container::iterator
MergeInsertService<Container>::binarySearchPosition(
    typename Container::iterator begin, typename Container::iterator end,
    int value) {
  typename Container::iterator left = begin;
  typename Container::iterator right = end;

  while (left < right) {
    typename Container::iterator mid =
        left + (static_cast<size_t>(right - left) / 2);
    if (*mid < value) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  return left;
}

template <typename Container>
std::vector<size_t> MergeInsertService<Container>::generateInsertionSequence(
    size_t numElements) {
  if (numElements <= 1) {
    return std::vector<size_t>();
  }

  std::vector<size_t> insertionOrder;
  insertionOrder.reserve(numElements - 1);

  size_t previousJacobBoundary = 1;
  size_t currentJacobIndex = 2;

  while (previousJacobBoundary < numElements) {
    size_t currentJacobBoundary = computeJacobsthalNumber(currentJacobIndex);

    currentJacobBoundary = std::min(currentJacobBoundary, numElements);
    for (int i = static_cast<int>(currentJacobBoundary);
         i > static_cast<int>(previousJacobBoundary); --i) {
      insertionOrder.push_back(static_cast<size_t>(i - 1));
    }

    previousJacobBoundary = currentJacobBoundary;
    ++currentJacobIndex;
  }

  return insertionOrder;
}

template <typename Container>
size_t MergeInsertService<Container>::computeJacobsthalNumber(size_t index) {
  if (index == 0) {
    return 1;
  }
  if (index == 1) {
    return 1;
  }

  size_t jacobMinusTwo = 1;
  size_t jacobMinusOne = 1;

  for (size_t iteration = 2; iteration <= index; ++iteration) {
    size_t jacobCurrent = jacobMinusOne + (2 * jacobMinusTwo);
    jacobMinusTwo = jacobMinusOne;
    jacobMinusOne = jacobCurrent;
  }

  return jacobMinusOne;
}

#endif  // MERGE_INSERT_SERVICE_TPP

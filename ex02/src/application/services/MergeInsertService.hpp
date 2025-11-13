/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MergeInsertService.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 17:27:26 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 21:05:29 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MERGE_INSERT_SERVICE_HPP
#define MERGE_INSERT_SERVICE_HPP

#include <cstddef>
#include <vector>

template <typename Container>
class MergeInsertService {
 public:
  static void sort(Container& container);

 private:
  MergeInsertService(const MergeInsertService& /*unused*/);
  ~MergeInsertService();

  MergeInsertService& operator=(const MergeInsertService& /*unused*/);

  static void createPairs(Container& container);
  static void sortRecursive(Container& larger);
  static void insertSmaller(Container& larger, size_t smallerSize, Container& smaller);
  static typename Container::iterator binarySearchPosition(
      typename Container::iterator begin, typename Container::iterator end,
      int value);
  static std::vector<size_t> generateInsertionSequence(size_t numElements);
  static size_t computeJacobsthalNumber(size_t index);
};

#include "application/services/MergeInsertService.tpp"

#endif  // MERGE_INSERT_SERVICE_HPP

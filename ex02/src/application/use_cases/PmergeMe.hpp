/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:23:56 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 15:53:10 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include "domain/entities/IntegerSequence.hpp"
#include "domain/repositories/ISequenceRepository.hpp"

#include <vector>

class PmergeMe {
 public:
  PmergeMe();
  PmergeMe(const PmergeMe& other);
  ~PmergeMe();

  PmergeMe& operator=(const PmergeMe& other);

  template <typename Container>
  void execute(const IntegerSequence& sequence,
               ISequenceRepository<Container>& repository);

 private:
  struct SortResult {
    std::vector<int> sorted;
    double elapsedTime;
    std::string containerName;
  };

  std::vector<SortResult> m_results;
};

#include "application/use_cases/PmergeMe.tpp"

#endif  // PMERGEME_HPP

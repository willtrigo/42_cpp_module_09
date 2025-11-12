/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:36:30 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 15:58:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_TPP
#define PMERGEME_TPP

template <typename Container>
void PmergeMe::execute(const IntegerSequence& sequence, ISequenceRepository<Container>& repository) {
  repository.load(sequence.getData());
  repository.sort();

  SortResult result;
  result.sorted = repository.retrieve();
  result.elapsedTime = repository.getElapsedTime();
  result.containerName = repository.getContainerName();

  this->m_results.push_back(result);
}

#endif  // PMERGEME_TPP

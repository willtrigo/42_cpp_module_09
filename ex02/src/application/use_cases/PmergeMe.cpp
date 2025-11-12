/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:34:17 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 16:32:24 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/use_cases/PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : m_results(other.m_results) {}

PmergeMe::~PmergeMe() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
  if (this != &other) {
    this->m_results = other.m_results;
  }
  return *this;
}

const std::vector<PmergeMe::SortResult>& PmergeMe::getResult() const {
  return this->m_results;
}

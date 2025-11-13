/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeAdapter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:14:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 21:17:01 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/MergeInsertService.hpp"
#include "infrastructure/adapters/DequeAdapter.hpp"

#include <cstddef>

DequeAdapter::DequeAdapter() {}

DequeAdapter::DequeAdapter(const DequeAdapter& other)
    : m_container(other.m_container), m_timer(other.m_timer) {}

DequeAdapter::~DequeAdapter() {}

DequeAdapter& DequeAdapter::operator=(const DequeAdapter& other) {
  if (this != &other) {
    this->m_container = other.m_container;
    this->m_timer = other.m_timer;
  }
  return *this;
}

void DequeAdapter::load(const std::vector<int>& data) {
  for (size_t i = 0; i < data.size(); ++i) {
    this->m_container.push_back(data.at(i));
  }
}

void DequeAdapter::sort() {
  this->m_timer.start();
  MergeInsertService<std::deque<int> >::sort(this->m_container);
  this->m_timer.stop();
}

std::vector<int> DequeAdapter::retrieve() const {
  std::vector<int> result;
  for (size_t i = 0; i < this->m_container.size(); ++i) {
    result.push_back(this->m_container.at(i));
  }
  return result;
}

double DequeAdapter::getElapsedTime() const {
  return this->m_timer.getElapsedMicroseconds();
}

std::string DequeAdapter::getContainerName() const {
  return "std::deque<int>";
}

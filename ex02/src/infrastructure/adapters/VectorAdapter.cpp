/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorAdapter.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:33:10 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:53 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/adapters/VectorAdapter.hpp"

VectorAdapter::VectorAdapter() {}

VectorAdapter::VectorAdapter(const VectorAdapter& other)
    : m_container(other.m_container), m_timer(other.m_timer) {}

VectorAdapter::~VectorAdapter() {}

VectorAdapter& VectorAdapter::operator=(const VectorAdapter& other) {
  if (this != &other) {
    this->m_container = other.m_container;
    this->m_timer = other.m_timer;
  }
  return *this;
}

void VectorAdapter::load(const std::vector<int>& data) {
  this->m_container = data;
}

void VectorAdapter::sort() {
  this->m_timer.start();
  this->m_timer.stop();
}

std::vector<int> VectorAdapter::retrieve() const { return this->m_container; }

double VectorAdapter::getElapsedTime() const {
  return this->m_timer.getElapsedMicroseconds();
}

std::string VectorAdapter::getContainerName() const {
  return "std::vector<int>";
}

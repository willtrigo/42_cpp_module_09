/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackAdapter.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:05:14 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 15:11:26 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/adapters/StackAdapter.hpp"

#include <cstddef>
#include <stdexcept>

StackAdapter::StackAdapter() {}

StackAdapter::StackAdapter(const StackAdapter& other)
    : m_stack(other.m_stack) {}

StackAdapter::~StackAdapter() {}

StackAdapter& StackAdapter::operator=(const StackAdapter& other) {
  if (this != &other) {
    this->m_stack = other.m_stack;
  }
  return *this;
}

void StackAdapter::push(double value) { this->m_stack.push(value); }

double StackAdapter::pop() {
  if (this->m_stack.empty()) {
    throw std::runtime_error("stack underflow");
  }
  double value = this->m_stack.top();
  this->m_stack.pop();
  return value;
}

double StackAdapter::top() const {
  if (this->m_stack.empty()) {
    throw std::runtime_error("empty stack");
  }
  return this->m_stack.top();
}

bool StackAdapter::empty() const { return this->m_stack.empty(); }

size_t StackAdapter::size() const { return this->m_stack.size(); }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StackAdapter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:01:00 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 15:04:57 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_ADAPTER_HPP
#define STACK_ADAPTER_HPP

#include "domain/repository/IRpnStack.hpp"

#include <cstddef>
#include <stack>

class StackAdapter : public IRpnStack {
 public:
  StackAdapter();
  StackAdapter(const StackAdapter& other);
  virtual ~StackAdapter();

  StackAdapter& operator=(const StackAdapter& other);

  virtual void push(double value);
  virtual double pop();
  virtual double top() const;
  virtual bool empty() const;
  virtual size_t size() const;

 private:
  std::stack<double> m_stack;
};

#endif  // STACK_ADAPTER_HPP

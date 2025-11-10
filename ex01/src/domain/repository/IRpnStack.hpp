/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IRpnStack.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:58:04 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 15:00:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IRPN_STACK_HPP
#define IRPN_STACK_HPP

#include <cstddef>

class IRpnStack {
 public:
  virtual ~IRpnStack() {}

  virtual void push(double value) = 0;
  virtual double pop() = 0;
  virtual double top() const = 0;
  virtual bool empty() const = 0;
  virtual size_t size() const = 0;
};

#endif  // IRPN_STACK_HPP

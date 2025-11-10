/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RpnCalculator.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:12:52 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 16:41:54 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_CALCULATOR_HPP
#define RPN_CALCULATOR_HPP

#include "domain/repository/IRpnStack.hpp"

#include <string>

class RpnCalculator {
 public:
  explicit RpnCalculator(IRpnStack& stack);
  RpnCalculator(const RpnCalculator& other);
  ~RpnCalculator();

  RpnCalculator& operator=(const RpnCalculator& other);

  void processToken(const std::string& token);
  double getResult();

 private:
  IRpnStack& m_stack;

  static const int K_MIN_STACK_SIZE = 2;

  static bool isOperator(const std::string& token);
  static double stringToDouble(const std::string& str);
  static double applyOperation(const std::string& operation, double leftSide,
                        double rightSide);
};

#endif  // RPN_CALCULATOR_HPP

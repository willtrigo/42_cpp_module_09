/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rpn.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 15:32:55 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 14:26:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <list>
#include <string>

class Rpn {
 public:
  explicit Rpn(const std::string& expression);
  Rpn(const Rpn& other);
  ~Rpn();

  Rpn& operator=(const Rpn& other);

  const std::list<std::string>& getTokens() const;
  bool isValid() const;

private:
  std::list<std::string> m_tokens;

  static const int K_MIN_RANGE = 0;
  static const int K_MAX_RANGE = 10;
  static const int K_MIN_OPERAND_COUNT = 2;
  static const int K_VALID_OPERAND_COUNT = 1;

  void tokenize(const std::string& expression);
  static bool isOperator(const std::string& token);
  static bool isNumber(const std::string& token);
};

#endif  // RPN_EXPRESSION_HPP

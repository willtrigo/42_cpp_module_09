/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvaluateRpnUseCase.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:09:21 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 17:15:23 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/use_cases/EvaluateRpnUsecase.hpp"
#include "application/services/RpnCalculator.hpp"

EvaluateRpnUsecase::EvaluateRpnUsecase(RpnCalculator& calculator) : m_calculator(calculator) {}

EvaluateRpnUsecase::EvaluateRpnUsecase(const EvaluateRpnUsecase& other) : m_calculator(other.m_calculator) {}

EvaluateRpnUsecase::~EvaluateRpnUsecase() {}

EvaluateRpnUsecase& EvaluateRpnUsecase::operator=(const EvaluateRpnUsecase& other) {
  if (this != &other) {
    m_calculator = other.m_calculator;
  }
  return *this;
}

double EvaluateRpnUsecase::execute(const Rpn& expression) {
  const std::list<std::string>& tokens = expression.getTokens();

  for (std::list<std::string>::const_iterator it = tokens.begin(); it != tokens.end(); ++it) {
    this->m_calculator.processToken(*it);
  }

  return this->m_calculator.getResult();
}

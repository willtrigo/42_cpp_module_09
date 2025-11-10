/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EvaluateRpnUsecase.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 17:01:00 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 17:15:37 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVALUATE_RPN_USE_CASE_HPP
#define EVALUATE_RPN_USE_CASE_HPP

#include "application/services/RpnCalculator.hpp"
#include "domain/entities/Rpn.hpp"

class EvaluateRpnUsecase {
 public:
  explicit EvaluateRpnUsecase(RpnCalculator& calculator);
  EvaluateRpnUsecase(const EvaluateRpnUsecase& other);
  ~EvaluateRpnUsecase();

  EvaluateRpnUsecase& operator=(const EvaluateRpnUsecase& other);

  double execute(const Rpn& expression);

private:
  RpnCalculator& m_calculator;
};

#endif  // EVALUATE_RPN_USE_CASE_HPP

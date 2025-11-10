/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliController.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:24:40 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 17:17:42 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/RpnCalculator.hpp"
#include "application/use_cases/EvaluateRpnUsecase.hpp"
#include "domain/entities/Rpn.hpp"
#include "infrastructure/adapters/StackAdapter.hpp"
#include "presentation/cli/CliController.hpp"
#include "presentation/cli/CliView.hpp"

#include <stdexcept>
#include <string>

CliController::CliController(CliView& view) : m_view(view) {}

CliController::CliController(const CliController& other)
    : m_view(other.m_view) {}

CliController::~CliController() {}

CliController& CliController::operator=(const CliController& other) {
  if (this == &other) {
    return *this;
  }
  throw std::runtime_error("CliController assignment is not allowed");
}

bool CliController::run(int argc, char** argv) {
  if (argc != MAX_SIZE_ARGS) {
    this->m_view.displayUsage(std::string(argv[NAME_PROGRAM]));
    return false;
  }

  try {
    Rpn expression((std::string(argv[LITERAL_ARGUMENT_INDEX])));
    StackAdapter stack;
    RpnCalculator calculator(stack);
    EvaluateRpnUsecase useCase(calculator);

    double result = useCase.execute(expression);
    this->m_view.displayResult(result);
  } catch (const std::exception& exception) {
    this->m_view.displayError(exception.what());
    return false;
  }
  return true;
}

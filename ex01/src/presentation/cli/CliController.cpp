/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliControllerConstructor.cpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:24:40 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/09 16:38:21 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presentation/cli/CliController.hpp"
#include "presentation/cli/CliView.hpp"

#include <stdexcept>

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
  return true;
}

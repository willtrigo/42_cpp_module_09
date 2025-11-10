/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliController.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:38:25 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:52:51 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/ExchangeService.hpp"
#include "domain/use_cases/CalculateValueCase.hpp"
#include "infrastructure/adapters/CsvBitcoinRepository.hpp"
#include "presentation/cli/CliController.hpp"
#include "presentation/cli/CliView.hpp"

#include <fstream>
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
    this->m_view.displayError("could not open file.");
    return false;
  }
  try {
    CsvBitcoinRepository repository;
    ExchangeService service(repository);
    CalculateValueUseCase useCase(service);

    std::string inputFilePath = argv[LITERAL_ARGUMENT_INDEX];
    std::ifstream inputFile(inputFilePath.c_str());
    if (!inputFile.is_open()) {
      throw std::runtime_error("Could not open file");
    }

    std::string line;
    std::getline(inputFile, line);
    if (line != "date | value") {
      inputFile.close();
      throw std::runtime_error("Invalid header of data.csv");
    }

    while (std::getline(inputFile, line) != 0) {
      try {
        this->m_view.displayLine(useCase.parseAndProcessLine(line));
      } catch (const std::exception& exception) {
        this->m_view.displayError(exception.what());
      }
    }

    inputFile.close();
  } catch (const std::exception& exception) {
    this->m_view.displayError(exception.what());
    return false;
  }
  return true;
}

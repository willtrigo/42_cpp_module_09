/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliController.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:42:44 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 16:27:06 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/use_cases/PmergeMe.hpp"
#include "domain/entities/IntegerSequence.hpp"
#include "infrastructure/adapters/DequeAdapter.hpp"
#include "infrastructure/adapters/VectorAdapter.hpp"
#include "presentation/cli/CliController.hpp"
#include "presentation/cli/CliView.hpp"

#include <algorithm>
#include <cstdlib>
#include <limits>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

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
  IntegerSequence sequence;

  if (!parseArguments(argc, argv, sequence)) {
    return false;
  }

  try {
    VectorAdapter vectorAdapter;
    DequeAdapter dequeAdapter;

    PmergeMe useCase;
    useCase.execute(sequence, vectorAdapter);
    useCase.execute(sequence, dequeAdapter);

    this->m_view.displayResult(sequence, useCase);
  } catch (const std::exception& exception) {
    this->m_view.displayError(exception.what());
    return false;
  }
  return true;
}

bool CliController::parseArguments(int argc, char** argv,
                                   IntegerSequence& sequence) {
  if (argc < MAX_SIZE_ARGS) {
    this->m_view.displayUsage(std::string(argv[NAME_PROGRAM]));
    return false;
  }

  for (int i = LITERAL_ARGUMENT_INDEX; i < argc; ++i) {
    std::istringstream iss(argv[i]);
    long value;

    if (!(iss >> value) || !iss.eof()) {
      this->m_view.displayError("invalid input");
      return false;
    }

    if (value < 0) {
      this->m_view.displayError("negative value not allowed");
      return false;
    }

    if (value > std::numeric_limits<int>::max()) {
      this->m_view.displayError("value too large");
      return false;
    }

    sequence.add(static_cast<int>(value));

    if (hasDuplicates(sequence.getData())) {
      this->m_view.displayError("duplicate values detected");
      return false;
    }
  }

  return true;
}

bool CliController::hasDuplicates(const std::vector<int>& data) {
  if (data.size() <= 1) {
    return false;
  }

  std::vector<int> sorted(data);
  std::sort(sorted.begin(), sorted.end());

  for (size_t i = 1; i < sorted.size(); ++i) {
    if (sorted.at(i) == sorted.at(i - 1)) {
      return true;
    }
  }

  return false;
}

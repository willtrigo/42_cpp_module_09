/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliView.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:43:25 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 16:51:50 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/IStreamWriter.hpp"
#include "presentation/cli/CliView.hpp"
#include "presentation/utils/TerminalColor.hpp"

#include <iomanip>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

CliView::CliView(IStreamWriter& writer) : m_writer(writer) {}

CliView::CliView(const CliView& other) : m_writer(other.m_writer) {}

CliView::~CliView() {}

CliView& CliView::operator=(const CliView& other) {
  if (this != &other) {
    return *this;
  }
  throw std::runtime_error("CliView assignment is not allowed");
}

void CliView::displayUsage(const std::string& programName) const {
  this->m_writer.print(std::cerr,
                       TerminalColor::setColor(RED, "Usage: " + programName +
                                                        " <input_expressions>"),
                       true);
}

void CliView::displayError(const std::string& str) const {
  this->m_writer.print(std::cerr, TerminalColor::setColor(RED, "Error: " + str),
                       true);
}

void CliView::displayResult(const IntegerSequence& sequence,
                            const PmergeMe& useCase) const {
  displayOriginal(sequence.getData());
  displaySorted(useCase.getResult().at(0).sorted);

  for (size_t i = 0; i < useCase.getResult().size(); ++i) {
    displayTiming(useCase.getResult().at(i).containerName, sequence.size(),
                  useCase.getResult().at(i).elapsedTime);
  }
}

void CliView::displayOriginal(const std::vector<int>& sequence) const {
  this->m_writer.print(std::cout, TerminalColor::setColor(BLUE, "Before:  "),
                       false);

  for (size_t i = 0; i < sequence.size(); ++i) {
    if (i > 0) {
      this->m_writer.print(std::cout, " ", false);
    }
    std::ostringstream str;
    str << sequence.at(i);
    this->m_writer.print(std::cout, TerminalColor::setColor(BLUE, str.str()),
                         false);
  }
  this->m_writer.print(std::cout, "", true);
}

void CliView::displaySorted(const std::vector<int>& sequence) const {
  this->m_writer.print(std::cout, TerminalColor::setColor(GREEN, "After:   "),
                       false);

  for (size_t i = 0; i < sequence.size(); ++i) {
    if (i > 0) {
      this->m_writer.print(std::cout, " ", false);
    }
    std::ostringstream str;
    str << sequence.at(i);
    this->m_writer.print(std::cout, TerminalColor::setColor(GREEN, str.str()),
                         false);
  }
  this->m_writer.print(std::cout, "", true);
}

void CliView::displayTiming(const std::string& containerName, size_t count,
                            double time) const {
  std::ostringstream str;
  str << "Time to process a range of " << count << " elements with "
      << containerName << " : " << std::fixed
      << std::setprecision(K_PRECISION_TIME) << time << " us";
  this->m_writer.print(
      std::cout,
      TerminalColor::setColor(
          (containerName == "std::vector<int>" ? BG_ORANGE : BG_WHITE), BLACK,
          str.str()),
      true);
}

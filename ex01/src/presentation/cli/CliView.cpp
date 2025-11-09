/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliViewConstructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:26:02 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/09 16:39:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/IStreamWriter.hpp"
#include "presentation/cli/CliView.hpp"
#include "presentation/utils/TerminalColor.hpp"

#include <iostream>
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

void CliView::displaySeparator() const {
  this->m_writer.print(
      std::cout,
      TerminalColor::setColor(YELLOW, std::string(SEPARATOR_LENGTH, '-')),
      true);
}

void CliView::displayTitle(const std::string& str) const {
  this->m_writer.print(
      std::cout,
      TerminalColor::setColor(BLUE, std::string(TITLE_BORDER_LENGTH, '=')) +
          " " + TerminalColor::setColor(GREEN, str) + " " +
          TerminalColor::setColor(BLUE, std::string(TITLE_BORDER_LENGTH, '=')),
      true);
}

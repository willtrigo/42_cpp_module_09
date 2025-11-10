/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliView.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:25:43 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 13:45:19 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_VIEW_HPP
#define CLI_VIEW_HPP

#include "infrastructure/io/IStreamWriter.hpp"

#include <string>

class CliView {
 public:
  CliView(IStreamWriter& writer);
  ~CliView();

  void displayUsage(const std::string& programName) const;
  void displayError(const std::string& str) const;
  void displayResult(const std::string& str) const;

 private:
  CliView(const CliView& other);

  CliView& operator=(const CliView& other);

  void displaySeparator() const;
  void displayTitle(const std::string& str) const;

  IStreamWriter& m_writer;

  static const int SEPARATOR_LENGTH = 60;
  static const int TITLE_BORDER_LENGTH = 5;
};

#endif  // CLI_VIEW_HPP

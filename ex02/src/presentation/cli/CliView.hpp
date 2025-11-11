/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliView.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:43:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:43:53 by dande-je         ###   ########.fr       */
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
  void displayResult(const double& value) const;

 private:
  CliView(const CliView& other);

  CliView& operator=(const CliView& other);

  IStreamWriter& m_writer;
};

#endif  // CLI_VIEW_HPP

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliView.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:43:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 16:49:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_VIEW_HPP
#define CLI_VIEW_HPP

#include "application/use_cases/PmergeMe.hpp"
#include "domain/entities/IntegerSequence.hpp"
#include "infrastructure/io/IStreamWriter.hpp"

#include <string>

class CliView {
 public:
  CliView(IStreamWriter& writer);
  ~CliView();

  void displayUsage(const std::string& programName) const;
  void displayError(const std::string& str) const;
  void displayResult(const IntegerSequence& sequence, const PmergeMe& useCase) const;

 private:
  CliView(const CliView& other);

  CliView& operator=(const CliView& other);

  IStreamWriter& m_writer;

  static const int K_PRECISION_TIME = 5;

  void displayOriginal(const std::vector<int>& sequence) const;
  void displaySorted(const std::vector<int>& sequence) const;
  void displayTiming(const std::string& containerName, size_t count, double time) const;
};

#endif  // CLI_VIEW_HPP

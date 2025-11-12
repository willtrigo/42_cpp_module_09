/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliController.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:43:09 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 12:36:59 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLI_CONTRLLER_HPP
#define CLI_CONTRLLER_HPP

#include "domain/entities/IntegerSequence.hpp"
#include "presentation/cli/CliView.hpp"

class CliController {
 public:
  CliController(CliView& view);
  ~CliController();

  bool run(int argc, char** argv);

 private:
  CliController(const CliController&);

  CliController& operator=(const CliController& other);

  CliView& m_view;

  static const int MAX_SIZE_ARGS = 2;
  static const int NAME_PROGRAM = 0;
  static const int LITERAL_ARGUMENT_INDEX = 1;

  bool parseArguments(int argc, char** argv, IntegerSequence& sequence);
  static bool hasDuplicates(const std::vector<int>& data);
};

#endif  // CLI_CONTRLLER_HPP

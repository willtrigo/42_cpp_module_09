/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliControllerUtilities.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:40:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 16:15:35 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presentation/cli/CliController.hpp"

bool CliController::run(int argc, char** argv) {
  if (argc != MAX_SIZE_ARGS) {
    this->m_view.displayError("could not open file.");
    return false;
  }
  (void)argv;
  return true;
}

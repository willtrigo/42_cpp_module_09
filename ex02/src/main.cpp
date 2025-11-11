/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 18:41:56 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/10 18:42:07 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/StreamWriter.hpp"
#include "presentation/cli/CliController.hpp"
#include "presentation/cli/CliView.hpp"

#include <cstdlib>

int main(int argc, char** argv) {
  StreamWriter writer;

  CliView view(writer);
  CliController controller(view);
  
  return controller.run(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

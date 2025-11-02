/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamWriterUtilities.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:55:50 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 14:55:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/StreamWriter.hpp"

#include <iostream>
#include <ostream>

void StreamWriter::print(std::ostream& ostr, const std::string& str,
                         bool newLine) {
  ostr << str;
  if (newLine) {
    ostr << std::endl;
  }
}

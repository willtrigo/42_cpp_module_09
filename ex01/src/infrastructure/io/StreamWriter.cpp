/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   StreamWriterConstructor.cpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:28:53 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/09 16:40:02 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/StreamWriter.hpp"

#include <iostream>
#include <ostream>
#include <stdexcept>

StreamWriter::StreamWriter() {}

StreamWriter::StreamWriter(const StreamWriter& /*unused*/) {}

StreamWriter::~StreamWriter() {}

StreamWriter& StreamWriter::operator=(const StreamWriter& /*unused*/) {
  throw std::runtime_error("StreamWriter assignment is not allowed");
}

void StreamWriter::print(std::ostream& ostr, const std::string& str,
                         bool newLine) {
  ostr << str;
  if (newLine) {
    ostr << std::endl;
  }
}

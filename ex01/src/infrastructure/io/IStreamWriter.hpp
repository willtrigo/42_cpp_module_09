/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IStreamWriter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:28:07 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/05 19:28:16 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISTREAM_WRITER_HPP
#define ISTREAM_WRITER_HPP

#include <ostream>
#include <string>

class IStreamWriter {
 public:
  virtual ~IStreamWriter() {}
  virtual void print(std::ostream& ostr, const std::string& str,
                     bool newLine) = 0;
};

#endif  // ISTREAM_WRITER_HPP

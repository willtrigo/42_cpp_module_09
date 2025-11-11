/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IntegerSequence.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 20:21:58 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/11 20:41:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTEGER_SEQUENCE_HPP
#define INTEGER_SEQUENCE_HPP

#include <cstddef>
#include <exception>
#include <vector>

class IntegerSequence {
 public:
  IntegerSequence();
  IntegerSequence(const IntegerSequence& other);
  ~IntegerSequence();

  IntegerSequence& operator=(const IntegerSequence& other);

  void add(int value);
  const std::vector<int>& getData() const;
  size_t size() const;
  bool isEmpty() const;

  class InvalidValueException : public std::exception {
   public:
    virtual const char* what() const throw();
  };

 private:
  std::vector<int> m_data;
};

#endif  // INTEGER_SEQUENCE_HPP

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:50:03 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 22:57:18 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
#define BITCOIN_EXCHANGE_HPP

#include <string>

class BitcoinExchange {
 public:
  BitcoinExchange(const std::string& date, double value);
  BitcoinExchange(const BitcoinExchange& other);
  ~BitcoinExchange();

  BitcoinExchange& operator=(const BitcoinExchange& other);

  const std::string& getDate() const;
  double getValue() const;

  static bool isValidDate(const std::string& date);
  static bool isValidValue(double value);

 private:
  std::string m_date;
  double m_value;

  void validateDate();
  void validateValue();
};

#endif  // BITCOIN_EXCHANGE_HPP

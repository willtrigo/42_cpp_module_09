/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvBitcoinRepository.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:51:27 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 17:27:11 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CSV_BITCOIN_REPOSITORY_HPP
#define CSV_BITCOIN_REPOSITORY_HPP

#include "domain/repositories/IBitcoinRepository.hpp"

#include <map>
#include <string>

class CsvBitcoinRepository : public IBitcoinRepository {
 public:
  CsvBitcoinRepository();
  CsvBitcoinRepository(const CsvBitcoinRepository& other);
  ~CsvBitcoinRepository();

  CsvBitcoinRepository& operator=(const CsvBitcoinRepository& other);

  double getPrice(const std::string& date) const;

 private:
  std::map<std::string, double> m_price;

  static const std::string DEFAULT_DATABASE;

  void loadData();
  static std::pair<std::string, double> parseCsvLine(const std::string& line);
  static void strTrim(std::string& str);
};

#endif  // CSV_BITCOIN_REPOSITORY_HPP

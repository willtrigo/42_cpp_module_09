/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CsvBitcoinRepositoryConstructor.cpp                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 16:03:16 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 16:07:17 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/adapters/CsvBitcoinRepository.hpp"

CsvBitcoinRepository::CsvBitcoinRepository() { loadData(); }

CsvBitcoinRepository::CsvBitcoinRepository(const CsvBitcoinRepository& other)
    : m_price(other.m_price) {}

CsvBitcoinRepository::~CsvBitcoinRepository() {}

CsvBitcoinRepository& CsvBitcoinRepository::operator=(
    const CsvBitcoinRepository& other) {
  if (this != &other) {
    m_price = other.m_price;
  }
  return *this;
}

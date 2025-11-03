/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ExchangeServiceConstructor.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 22:24:34 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 22:27:15 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/ExchangeService.hpp"
#include "domain/repositories/IBitcoinRepository.hpp"

ExchangeService::ExchangeService(const IBitcoinRepository& repository)
    : m_repository(repository) {}

ExchangeService::ExchangeService(const ExchangeService& other)
    : m_repository(other.m_repository) {}

ExchangeService::~ExchangeService() {}

ExchangeService& ExchangeService::operator=(const ExchangeService& /*unused*/) {
  return *this;
}

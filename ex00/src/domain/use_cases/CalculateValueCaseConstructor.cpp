/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CalculateValueCaseConstructor.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 11:51:42 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/03 15:35:34 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "domain/use_cases/CalculateValueCase.hpp"
#include "application/services/ExchangeService.hpp"

CalculateValueUseCase::CalculateValueUseCase(const ExchangeService& service)
    : m_service(service) {}

CalculateValueUseCase::CalculateValueUseCase(const CalculateValueUseCase& other) : m_service(other.m_service) {}

CalculateValueUseCase::~CalculateValueUseCase() {}

CalculateValueUseCase& CalculateValueUseCase::operator=(const CalculateValueUseCase& other) {
  if (this != &other) {
    const_cast<ExchangeService&>(this->m_service) = other.m_service;
  }
  return *this;
}

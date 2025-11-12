/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimingService.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:09:32 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:38 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "application/services/TimingService.hpp"

const double TimingService::K_MICROSECONDS_PER_SECOND = 100000.0;

TimingService::TimingService() {}

TimingService::TimingService(const TimingService& other)
    : m_startTime(other.m_startTime),
      m_endTime(other.m_endTime),
      m_elapsedMicroseconds(other.m_elapsedMicroseconds) {}

TimingService::~TimingService() {}

TimingService& TimingService::operator=(const TimingService& other) {
  if (this != &other) {
    this->m_startTime = other.m_startTime;
    this->m_endTime = other.m_endTime;
    this->m_elapsedMicroseconds = other.m_elapsedMicroseconds;
  }
  return *this;
}

void TimingService::start() { this->m_startTime = clock(); }

void TimingService::stop() {
  this->m_endTime = clock();
  this->m_elapsedMicroseconds =
      (static_cast<double>(this->m_endTime - this->m_startTime) /
       CLOCKS_PER_SEC) *
      K_MICROSECONDS_PER_SECOND;
}

double TimingService::getElapsedMicroseconds() const {
  return this->m_elapsedMicroseconds;
}

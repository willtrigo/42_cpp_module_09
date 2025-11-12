/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TimingService.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 13:05:46 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:43 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMING_SERVICE_HPP
#define TIMING_SERVICE_HPP

#include <ctime>

class TimingService {
 public:
  TimingService();
  TimingService(const TimingService& other);
  ~TimingService();

  TimingService& operator=(const TimingService& other);

  void start();
  void stop();
  double getElapsedMicroseconds() const;

 private:
  clock_t m_startTime;
  clock_t m_endTime;
  double m_elapsedMicroseconds;

  static const double K_MICROSECONDS_PER_SECOND;
};

#endif  // TIMING_SERVICE_HPP

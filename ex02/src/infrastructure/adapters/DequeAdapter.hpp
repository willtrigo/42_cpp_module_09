/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DequeAdapter.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:19 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 15:08:08 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_ADAPTER_HPP
#define DEQUE_ADAPTER_HPP

#include "application/services/TimingService.hpp"
#include "domain/repositories/ISequenceRepository.hpp"

#include <deque>

class DequeAdapter : public ISequenceRepository<std::deque<int> > {
 public:
  DequeAdapter();
  DequeAdapter(const DequeAdapter& other);
  virtual ~DequeAdapter();

  DequeAdapter& operator=(const DequeAdapter& other);

  virtual void load(const std::vector<int>& data);
  virtual void sort();
  virtual std::vector<int> retrieve() const;
  virtual double getElapsedTime() const;
  virtual std::string getContainerName() const;

 private:
  std::deque<int> m_container;
  TimingService m_timer;
};

#endif  // DEQUE_ADAPTER_HPP

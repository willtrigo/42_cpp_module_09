/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectorAdapter.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:55:19 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 14:13:49 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_ADAPTER_HPP
#define VECTOR_ADAPTER_HPP

#include "application/services/TimingService.hpp"
#include "domain/repositories/ISequenceRepository.hpp"

#include <vector>

class VectorAdapter : public ISequenceRepository<std::vector<int> > {
 public:
  VectorAdapter();
  VectorAdapter(const VectorAdapter& other);
  virtual ~VectorAdapter();

  VectorAdapter& operator=(const VectorAdapter& other);

  virtual void load(const std::vector<int>& data);
  virtual void sort();
  virtual std::vector<int> retrieve() const;
  virtual double getElapsedTime() const;
  virtual std::string getContainerName() const;

 private:
  std::vector<int> m_container;
  TimingService m_timer;
};

#endif  // VECTOR_ADAPTER_HPP

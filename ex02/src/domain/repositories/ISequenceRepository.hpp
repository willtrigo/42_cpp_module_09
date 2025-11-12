/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ISequenceRepository.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:56:41 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/12 14:10:27 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ISEQUENCE_REPOSITORY_HPP
#define ISEQUENCE_REPOSITORY_HPP

#include <string>
#include <vector>

template <typename Container>
class ISequenceRepository {
 public:
  virtual ~ISequenceRepository() {}

  virtual void load(const std::vector<int>& data) = 0;
  virtual void sort() = 0;
  virtual std::vector<int> retrieve() const = 0;
  virtual double getElapsedTime() const = 0;
  virtual std::string getContainerName() const = 0;
};

#endif  // ISEQUENCE_REPOSITORY_HPP

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBitcoinRepository.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:52:35 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 15:54:58 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IBITCOIN_REPOSITORY_HPP
#define IBITCOIN_REPOSITORY_HPP

#include <string>

class IBitcoinRepository {
 public:
  virtual ~IBitcoinRepository() {}
  virtual double getPrice(const std::string& date) const = 0;
};

#endif  // IBITCOIN_REPOSITORY_HPP

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CliViewConstructor.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 14:42:55 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/02 14:43:04 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infrastructure/io/IStreamWriter.hpp"
#include "presentation/cli/CliView.hpp"

#include <stdexcept>

CliView::CliView(IStreamWriter& writer) : m_writer(writer) {}

CliView::CliView(const CliView& other) : m_writer(other.m_writer) {}

CliView::~CliView() {}

CliView& CliView::operator=(const CliView& other) {
  if (this != &other) {
    return *this;
  }
  throw std::runtime_error("CliView assignment is not allowed");
}

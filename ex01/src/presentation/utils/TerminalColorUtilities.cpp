/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TerminalColorUtilities.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dande-je <dande-je@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:27:25 by dande-je          #+#    #+#             */
/*   Updated: 2025/11/05 19:27:32 by dande-je         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presentation/utils/TerminalColor.hpp"

#include <string>

std::string TerminalColor::getColor(StrColor strColor) {
  return STR_COLOR_MAP[strColor].second;
}

std::string TerminalColor::getColor(BgColor bgColor) {
  return BG_COLOR_MAP[bgColor].second;
}

std::string TerminalColor::getColor(Style style) {
  return STYLE_MAP[style].second;
}

std::string TerminalColor::setColor(StrColor strColor, const std::string& str) {
  std::string result;

  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(BgColor bgColor, const std::string& str) {
  std::string result;

  result += BG_COLOR_MAP[bgColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(Style style, const std::string& str) {
  std::string result;

  result += STYLE_MAP[style].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(BgColor bgColor, StrColor strColor,
                                    const std::string& str) {
  std::string result;

  result += BG_COLOR_MAP[bgColor].second;
  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(StrColor strColor, Style style,
                                    const std::string& str) {
  std::string result;

  result += STYLE_MAP[style].second;
  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

std::string TerminalColor::setColor(BgColor bgColor, StrColor strColor,
                                    Style style, const std::string& str) {
  std::string result;

  result += STYLE_MAP[style].second;
  result += BG_COLOR_MAP[bgColor].second;
  result += STR_COLOR_MAP[strColor].second;
  result += str;
  result += STR_COLOR_MAP[RESET].second;
  return result;
}

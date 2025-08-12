#pragma once
#include <string>

class TextLine {
public:
  TextLine() = default;
  TextLine(std::string raw);

  const std::string &raw() const;
  std::size_t raw_size() const;

private:
  std::string m_raw;
};

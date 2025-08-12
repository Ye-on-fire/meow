#pragma once
#include <string>

class TextLine {
public:
  TextLine() = default;
  TextLine(std::string raw);

  const std::string &raw() const;
  int raw_size() const;

private:
  std::string m_raw;
};

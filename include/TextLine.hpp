#pragma once
#include <string>

class TextLine {
public:
  TextLine() = default;
  TextLine(std::string raw);

  const std::string &raw() const;
  std::size_t raw_size() const;

public:
  // this function can insert contents to TextLine
  void insert(std::size_t p, char ch);
  // this function can remove one char
  void remove(std::size_t p);

private:
  std::string m_raw;
};

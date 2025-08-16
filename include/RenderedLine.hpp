#pragma once
#include <string>

class RenderedLine {
public:
  const std::string &rendered() const;
  int rsize() const;

private:
  std::string m_rendered = "";
  std::size_t m_rsize = 0;
};

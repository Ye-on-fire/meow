#include "TextLine.hpp"

TextLine::TextLine(std::string raw) : m_raw(raw) {}

const std::string &TextLine::raw() const { return m_raw; }

int TextLine::raw_size() const { return m_raw.size(); }

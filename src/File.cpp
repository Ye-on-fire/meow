#include "File.hpp"
#include <utility>

File::File(std::string filename) : m_filename(std::move(filename)) {
  m_rows.emplace_back("Hello World");
  m_numrows = 1;
}

const std::vector<TextLine> &File::rows() const { return m_rows; }

const std::string &File::filename() const { return m_filename; }

std::size_t &File::numrows() { return m_numrows; }

const char *File::getCStrByRow(std::size_t numrow) const {
  return m_rows[numrow].raw().c_str();
}

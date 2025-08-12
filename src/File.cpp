#include "File.hpp"
#include <utility>

File::File(std::string filename, std::string text, int numrows)
    : m_filename(std::move(filename)), m_text(std::move(text)),
      m_numrows(numrows) {}

std::string &File::text() { return m_text; }

const std::string &File::text() const { return m_text; }

const std::string &File::filename() const { return m_filename; }

int &File::numrows() { return m_numrows; }

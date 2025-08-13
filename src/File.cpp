#include "File.hpp"
#include "TextLine.hpp"
#include <fstream>
#include <utility>

File::File(std::string filename) : m_filename(std::move(filename)) {
  loadFile();
}

const std::vector<std::unique_ptr<TextLine>> &File::rows() const {
  return m_rows;
}

const std::string &File::filename() const { return m_filename; }

int &File::numrows() { return m_numrows; }

const char *File::getCStrByRow(int numrow) const {
  return m_rows[numrow]->raw().c_str();
}

void File::loadFile() {
  // open file
  std::ifstream fs(m_filename);
  if (!fs.is_open() || fs.bad())
    throw "Failed to open file";
  // create lines into file
  std::string line;
  while (std::getline(fs, line)) {
    m_rows.emplace_back(std::make_unique<TextLine>(line));
    m_numrows++;
  }
  fs.close();
}

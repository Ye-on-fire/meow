#include "File.hpp"
#include "Logger.hpp"
#include "TextLine.hpp"
#include <fstream>
#include <utility>

File::File(std::string filename) { loadFile(std::move(filename)); }

const std::unique_ptr<TextLine> &File::row(std::size_t numrow) const {
  return m_rows[numrow];
}

const std::string &File::filename() const { return m_filename; }

std::size_t &File::numrows() { return m_numrows; }

int File::loadFile(std::string filename) {
  // open file
  std::ifstream fs(filename);
  if (!fs.is_open() || fs.bad()) {
    spdlog::error("Failed to open file \"{}\", please check if it exists",
                  filename);
    return 1;
  }
  // create lines into file
  std::string line;
  while (std::getline(fs, line)) {
    m_rows.emplace_back(std::make_unique<TextLine>(line));
    m_numrows++;
  }
  fs.close();
  m_filename = std::move(filename);
  spdlog::info("loaded file \"{}\", numrows: {}", m_filename, m_numrows);
  return 0;
}

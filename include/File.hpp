/*
 * this file manages flie open and attributes of text file
 */

#pragma once
#include "TextLine.hpp"
#include <cstddef>
#include <memory>
#include <string>
#include <vector>

#define DEFAULT_FILENAME "Untitled"

class File {
public:
  File() = default;
  File(std::string filename);
  File(const File &other) = default;
  File(File &&other) noexcept = default;
  File &operator=(const File &other) = default;
  File &operator=(File &&other) = default;

  ~File() = default;

public:
  // get row by row number
  const std::unique_ptr<TextLine> &row(std::size_t numrow) const;
  const std::string &filename() const;
  std::size_t &numrows();

  // loadfile by filename, return 0 success, return 1 fail
  int loadFile(std::string filename);

private:
  std::vector<std::unique_ptr<TextLine>> m_rows;
  std::string m_filename = DEFAULT_FILENAME;
  std::size_t m_numrows = 0;
};

/*
 * this file manages flie open and attributes of text file
 */

#pragma once
#include "TextLine.hpp"
#include <string>
#include <vector>

class File {
public:
  File() = delete;
  File(std::string filename);
  File(const File &other) = default;
  File(File &&other) noexcept = default;
  File &operator=(const File &other) = default;
  File &operator=(File &&other) = default;

  ~File() = default;

public:
  const std::vector<TextLine> &rows() const;
  const std::string &filename() const;
  std::size_t &numrows();

  // get the cstr of std::string by row to printout by tb_printf
  const char *getCStrByRow(std::size_t numrow) const;

private:
  std::vector<TextLine> m_rows;
  std::string m_filename = "Untitled";
  std::size_t m_numrows = 0;
};

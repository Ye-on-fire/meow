/*
 * this file manages flie open and attributes of text file
 */

#pragma once
#include "TextLine.hpp"
#include <memory>
#include <string>
#include <vector>

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
  const std::vector<std::unique_ptr<TextLine>> &rows() const;
  const std::string &filename() const;
  int &numrows();

  // get the cstr of std::string by row to printout by tb_printf
  const char *getCStrByRow(int numrow) const;

  void loadFile();

private:
  std::vector<std::unique_ptr<TextLine>> m_rows;
  std::string m_filename = "Untitled";
  int m_numrows = 0;
};

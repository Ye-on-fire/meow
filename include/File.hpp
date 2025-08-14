/*
 * this file manages flie open and attributes of text file
 */

#pragma once
#include "TextLine.hpp"
#include <cstddef>
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
  std::size_t &numrows();

  void loadFile();

private:
  std::vector<std::unique_ptr<TextLine>> m_rows;
  std::string m_filename = "Untitled";
  std::size_t m_numrows = 0;
};

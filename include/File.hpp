/*
 * this file manages flie open and attributes of text file
 */

#pragma once

#include <string>
class File {
public:
  File() = delete;
  File(std::string filename, std::string text, int numrows);
  File(const File &other) = default;
  File(File &&other) noexcept = default;
  File &operator=(const File &other) = default;
  File &operator=(File &&other) = default;

  ~File() = default;

public:
  std::string &text();
  const std::string &text() const;
  const std::string &filename() const;
  int &numrows();

private:
  std::string m_filename = "Untitled";
  std::string m_text;
  int m_numrows = 0;
};

// this file manages the attributes of the editor interface

#pragma once
#include "Cursor.hpp"
#include "File.hpp"
#include <memory>
#include <termbox2.h>

class Editor {
public:
  Editor() = default;

  ~Editor();

public:
  tb_event event;
  int width() const;
  int height() const;
  int rowoffset() const;
  int coloffset() const;

  // program lifetime control
  void editorInit();
  void editorUpdate();
  void editorExit();

  // event handle
  void handleEvents();
  void handleKeyEvents();
  void handleResizeEvents();

  // scroll
  void editorScroll();

  void editorLoadFile(std::string filename);

private:
  std::unique_ptr<Cursor> m_cursor = std::make_unique<Cursor>();
  std::unique_ptr<File> m_file = std::make_unique<File>();
  int m_width = 0;
  int m_height = 0;
  int m_rowoffset = 0;
  int m_coloffset = 0;
};

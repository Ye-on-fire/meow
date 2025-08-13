// this file manages the attributes of the editor interface

#pragma once
#include "Cursor.hpp"
#include "File.hpp"
#include <termbox2.h>

class Editor {
public:
  Editor() = default;

  ~Editor();

public:
  tb_event event;
  const int width() const;
  const int height() const;

  // program lifetime control
  void editorInit();
  void editorUpdate();
  void editorExit();

  // event handle
  void handleEvents();
  void handleKeyEvents();
  void handleResizeEvents();

private:
  Cursor m_cursor;
  File m_file{"build.ninja"};
  int m_width = 0;
  int m_height = 0;
};

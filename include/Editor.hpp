// this file manages the attributes of the editor interface

#pragma once
#include "Cursor.hpp"
#include <termbox2.h>

class Editor {
public:
  Editor() = default;

  ~Editor();

public:
  tb_event event;
  void editorInit();
  void editorUpdate();
  void editorExit();

  void processKeyPress();

private:
  Cursor m_cursor = Cursor();
};

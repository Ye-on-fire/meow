// this file manages the attributes of the editor interface

#pragma once
#include <termbox2.h>

class Editor {
public:
  Editor() = default;

public:
  tb_event ev;
  void editorInit();
  void editorUpdate();
};

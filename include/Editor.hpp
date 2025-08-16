// this file manages the attributes of the editor interface

#pragma once
#include "Cursor.hpp"
#include "File.hpp"
#include <memory>
#include <termbox2.h>

enum class EditorMode {
  NORMAL,
  INSERT,
  VIUSAL,
};

class Editor {
public:
  Editor() = default;
  Editor(const Editor &other) = delete;
  Editor &operator=(const Editor &other) = delete;

  ~Editor();

public:
  tb_event event;
  int width() const;
  int height() const;
  int rowoffset() const;
  int coloffset() const;
  int cursorx() const;
  int cursory() const;

  EditorMode getMode() const;
  void setMode(EditorMode mode);

  // program lifetime control
  void editorInit();
  void editorUpdate();
  void editorExit();

  // event handle
  void handleEvents();

  void handleKeyEvents();
  void handleKeyEventsNormal();
  void handleKeyEventsInsert();
  void handleKeyEventsCommon();

  void handleResizeEvents();

  // scroll
  void editorScroll();

  // editor cursor movement, Up and Down restricted by max_y of the file, while
  // right considering max_x;
  void editorMoveCursorDown(int max_y);
  void editorMoveCursorUp();
  void editorMoveCursorRight(int max_x);
  void editorMoveCursorLeft();

  void editorLoadFile(std::string filename);

private:
  std::unique_ptr<Cursor> m_cursor = std::make_unique<Cursor>();
  std::unique_ptr<File> m_file = std::make_unique<File>();
  int m_width = 0;
  int m_height = 0;
  int m_rowoffset = 0;
  int m_coloffset = 0;
  EditorMode m_mode = EditorMode::NORMAL;
};

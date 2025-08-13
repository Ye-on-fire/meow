#include "Editor.hpp"
#include <termbox2.h>

// exit when editor exit
Editor::~Editor() { editorExit(); }

const int Editor::width() const { return m_width; }
const int Editor::height() const { return m_height; }

void Editor::handleEvents() {
  tb_peek_event(&event, 100);
  handleKeyEvents();
  handleResizeEvents();
}

void Editor::handleResizeEvents() {
  if (event.type == TB_EVENT_RESIZE) {
    m_width = tb_width();
    m_height = tb_height();
  }
}

// init the editor
void Editor::editorInit() {
  tb_init();
  m_width = tb_width();
  m_height = tb_height();
}

// what to do in the main loop
void Editor::editorUpdate() {
  handleEvents();
  for (int y = 0; y < m_height; y++) {
    tb_printf(0, y, 0, 0, m_file.getCStrByRow(y));
  }
  tb_present();
}

// do something when quiting the editor, called automatically in destructor
void Editor::editorExit() { tb_shutdown(); }

void Editor::handleKeyEvents() {
  if (event.type == TB_EVENT_KEY) {
    if (event.key == 0) {
      switch (event.ch) {
      case 'h':
        m_cursor.moveToOffset(-1, 0);
        break;
      case 'l':
        m_cursor.moveToOffset(1, 0);
        break;
      case 'j':
        m_cursor.moveToOffset(0, 1);
        break;
      case 'k':
        m_cursor.moveToOffset(0, -1);
        break;
      }
    } else if (event.key == TB_KEY_CTRL_Q) {
      editorExit();
      exit(0);
    }
  }
}

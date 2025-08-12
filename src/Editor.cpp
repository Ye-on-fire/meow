#include "Editor.hpp"
#include <termbox2.h>

// exit when editor exit
Editor::~Editor() { editorExit(); }

// init the editor
void Editor::editorInit() { tb_init(); }

// what to do in the main loop
void Editor::editorUpdate() {
  processKeyPress();
  for (std::size_t y = 0; y < m_file.numrows(); y++) {
    tb_printf(0, y, 0, 0, m_file.rows()[y].raw().c_str());
  }
  tb_present();
}

// do something when quiting the editor, called automatically in destructor
void Editor::editorExit() { tb_shutdown(); }

void Editor::processKeyPress() {
  tb_peek_event(&event, 100);
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

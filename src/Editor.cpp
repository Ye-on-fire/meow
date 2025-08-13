#include "Editor.hpp"
#include <termbox2.h>

// exit when editor exit
Editor::~Editor() { editorExit(); }

int Editor::width() const { return m_width; }
int Editor::height() const { return m_height; }
int Editor::rowoffset() const { return m_rowoffset; }
int Editor::coloffset() const { return m_coloffset; }

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
  tb_clear();
  handleEvents();
  editorScroll();
  m_cursor->renderCursor(m_width, m_height, m_rowoffset, m_coloffset);
  for (int y = 0; y < m_height; y++) {
    int filerow = y + m_rowoffset;
    if (filerow < m_file->numrows()) {
      tb_printf(0, y, 0, 0, m_file->getCStrByRow(filerow));
    } else {
      tb_printf(0, y, TB_BLUE, 0, "~");
    }
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
        m_cursor->moveOffset(-1, 0);
        break;
      case 'l':
        m_cursor->moveOffset(1, 0);
        break;
      case 'j':
        m_cursor->moveOffset(0, 1);
        break;
      case 'k':
        m_cursor->moveOffset(0, -1);
        break;
      }
    } else if (event.key == TB_KEY_CTRL_Q) {
      editorExit();
      exit(0);
    } else if (event.key == TB_KEY_ARROW_LEFT) {
      m_cursor->moveOffset(-1, 0);
    } else if (event.key == TB_KEY_ARROW_RIGHT) {
      m_cursor->moveOffset(1, 0);
    } else if (event.key == TB_KEY_ARROW_DOWN) {
      m_cursor->moveOffset(0, 1);
    } else if (event.key == TB_KEY_ARROW_UP) {
      m_cursor->moveOffset(0, -1);
    }
  }
}

void Editor::editorScroll() {
  // check border of cursor
  if (m_cursor->cx() < 0)
    m_cursor->moveTo(0, m_cursor->cy());
  if (m_cursor->cy() < 0)
    m_cursor->moveTo(m_cursor->cx(), 0);

  // check rowoffset of cursor
  if (m_cursor->cy() < m_rowoffset) {
    m_rowoffset = m_cursor->cy();
  }
  if (m_cursor->cy() >= m_height + m_rowoffset) {
    m_rowoffset = m_cursor->cy() - m_height + 1;
  }
}

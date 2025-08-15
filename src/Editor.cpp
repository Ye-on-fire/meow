#include "Editor.hpp"
#include "Logger.hpp"
#include <cstddef>
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
  spdlog::info("editor init");
}

// what to do in the main loop
void Editor::editorUpdate() {
  tb_clear();
  handleEvents();
  editorScroll();
  m_cursor->renderCursor(m_width, m_height, m_rowoffset, m_coloffset);
  for (int y = 0; y < m_height; y++) {
    std::size_t filerow = y + m_rowoffset;
    if (filerow < m_file->numrows()) {
      std::size_t len = m_file->row(filerow)->raw_size();
      std::size_t start = m_coloffset;
      if (start < len) {
        tb_printf(0, y, 0, 0, &m_file->row(filerow)->raw().c_str()[start]);
      }
    } else {
      tb_printf(0, y, TB_BLUE, 0, "~");
    }
  }
  tb_present();
}

// do something when quiting the editor, called automatically in destructor
void Editor::editorExit() {
  tb_shutdown();
  spdlog::info("termbox2 shutdown");
}

void Editor::editorMoveCursorDown(int max_y) {
  if (m_cursor->cy() < max_y) {
    m_cursor->moveOffset(0, 1);
    const int max_x_below_line =
        m_cursor->cy() < max_y ? m_file->row(m_cursor->cy())->raw_size() : 0;
    if (m_cursor->cx() > max_x_below_line) {
      m_cursor->moveTo(max_x_below_line, m_cursor->cy());
    }
  }
}

void Editor::editorMoveCursorRight(int max_x) {
  if (m_cursor->cx() < max_x) {
    m_cursor->moveOffset(1, 0);
  }
}

void Editor::editorMoveCursorUp() {
  if (m_cursor->cy() > 0) {
    m_cursor->moveOffset(0, -1);
    const int max_x_above_line =
        m_cursor->cy() > 0 ? m_file->row(m_cursor->cy())->raw_size() : 0;
    if (m_cursor->cx() > max_x_above_line) {
      m_cursor->moveTo(max_x_above_line, m_cursor->cy());
    }
  }
}

void Editor::editorMoveCursorLeft() {
  if (m_cursor->cx() > 0) {
    m_cursor->moveOffset(-1, 0);
  }
}

void Editor::handleKeyEvents() {
  const int max_y = m_file->numrows();
  const int max_x =
      m_cursor->cy() < max_y ? m_file->row(m_cursor->cy())->raw_size() : 0;
  if (event.type == TB_EVENT_KEY) {
    if (event.key == 0) {
      switch (event.ch) {
      case 'h':
        editorMoveCursorLeft();
        break;
      case 'l':
        editorMoveCursorRight(max_x);
        break;
      case 'j':
        editorMoveCursorDown(max_y);
        break;
      case 'k':
        editorMoveCursorUp();
        break;
      }
    } else if (event.key == TB_KEY_CTRL_Q) {
      editorExit();
      exit(0);
    } else if (event.key == TB_KEY_ARROW_LEFT) {
      editorMoveCursorLeft();
    } else if (event.key == TB_KEY_ARROW_RIGHT) {
      editorMoveCursorRight(max_x);
    } else if (event.key == TB_KEY_ARROW_DOWN) {
      editorMoveCursorDown(max_y);
    } else if (event.key == TB_KEY_ARROW_UP) {
      editorMoveCursorUp();
    }
  }
}

void Editor::editorScroll() {
  // check border of cursor
  // if (m_cursor->cx() < 0)
  //   m_cursor->moveTo(0, m_cursor->cy());
  // if (m_cursor->cy() < 0)
  //   m_cursor->moveTo(m_cursor->cx(), 0);

  /// check rowoffset of cursor
  // scroll up, if pos is above visable screen, then scroll up
  if (m_cursor->cy() < m_rowoffset) {
    m_rowoffset = m_cursor->cy();
  }
  // scroll down, if pos is below visable screen, then scroll down
  // why +1? because m_height starts from 1, but cy starts from 0
  if (m_cursor->cy() >= m_height + m_rowoffset) {
    m_rowoffset = m_cursor->cy() - m_height + 1;
  }
  if (m_cursor->cx() < m_coloffset) {
    m_coloffset = m_cursor->cx();
  }
  if (m_cursor->cx() >= m_width + m_coloffset) {
    m_coloffset = m_cursor->cx() - m_width + 1;
  }
}

void Editor::editorLoadFile(std::string filename) {
  m_file->loadFile(std::move(filename));
}

#include "Cursor.hpp"
#include <termbox2.h>

Cursor::Cursor(int cx, int cy) { moveTo(cx, cy); }
Cursor::Cursor() { tb_set_cursor(0, 0); }

int Cursor::cx() const { return m_cx; }
int Cursor::cy() const { return m_cy; }

// move cursor to position
void Cursor::moveTo(int x, int y) {
  m_cx = x;
  m_cy = y;
  tb_set_cursor(x, y);
  // tb_present();
}

void Cursor::moveToOffset(int offx, int offy) {
  m_cx += offx;
  m_cy += offy;
  tb_set_cursor(m_cx, m_cy);
  // tb_present();
}

void Cursor::hide() const { tb_hide_cursor(); }

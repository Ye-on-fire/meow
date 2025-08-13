#include "Cursor.hpp"
#include <termbox2.h>

Cursor::Cursor(int cx, int cy) : m_cx(cx), m_cy(cy) {}
Cursor::Cursor() : m_cx(0), m_cy(0) {}

int Cursor::cx() const { return m_cx; }
int Cursor::cy() const { return m_cy; }
int Cursor::rx() const { return m_rx; }
int Cursor::ry() const { return m_ry; }

// move cursor to position
void Cursor::moveTo(int x, int y) {
  m_cx = x;
  m_cy = y;
}

void Cursor::moveOffset(int offx, int offy) {
  m_cx += offx;
  m_cy += offy;
}

void Cursor::renderCursor(int t_width, int t_height, int rowoff, int coloff) {
  m_ry = m_cy - rowoff;
  tb_set_cursor(m_cx, m_ry);
}

void Cursor::hide() const { tb_hide_cursor(); }

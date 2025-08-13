#pragma once

class Cursor {
public:
  Cursor();
  Cursor(int cx, int cy);

  ~Cursor() = default;

  int cx() const;
  int cy() const;
  int rx() const;
  int ry() const;
  void moveTo(int x, int y);
  void moveOffset(int offx, int offy);
  // calculates the render position and set cursor
  void renderCursor(int t_width, int t_height, int rowoff, int coloff);
  void hide() const;

private:
  // actual position
  int m_cx = 0;
  int m_cy = 0;
  // render position, literally < terminal size
  int m_rx = 0;
  int m_ry = 0;
};

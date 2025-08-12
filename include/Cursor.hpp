#pragma once

class Cursor {
public:
  Cursor();
  Cursor(int cx, int cy);

  ~Cursor() = default;

  int cx() const;
  int cy() const;
  void moveTo(int x, int y);
  void moveToOffset(int offx, int offy);
  void hide() const;

private:
  int m_cx = 0;
  int m_cy = 0;
};

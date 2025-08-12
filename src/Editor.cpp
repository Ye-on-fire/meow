#include "Editor.hpp"
#include <termbox2.h>

void Editor::editorInit() { tb_init(); }

void Editor::editorUpdate() {
  tb_printf(0, 1, TB_BLUE, 0, "Hello World");
  tb_set_cursor(1, 3);
  tb_present();
  tb_poll_event(&ev);

  tb_shutdown();
}

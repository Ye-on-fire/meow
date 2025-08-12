#include "Editor.hpp"
#include <termbox2.h>

// exit when editor exit
Editor::~Editor() { editorExit(); }

// init the editor
void Editor::editorInit() { tb_init(); }

// what to do in the main loop
void Editor::editorUpdate() {
  tb_printf(0, 1, TB_BLUE, 0, "Hello World");
  tb_present();
  tb_poll_event(&event);
}

// do something when quiting the editor, called automatically in destructor
void Editor::editorExit() { tb_shutdown(); }

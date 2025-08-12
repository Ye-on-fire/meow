#include "Editor.hpp"
#include <memory>

#define PROJECT_NAME kilocpp
#define VERSION 0.0.1

int main() {
  auto editor = std::make_unique<Editor>();
  editor->editorInit();
  for (;;) {
    editor->editorUpdate();
  }
  return 0;
}

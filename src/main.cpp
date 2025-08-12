#include "Editor.hpp"
#include <memory>

int main() {
  auto editor = std::make_unique<Editor>();
  editor->editorInit();
  editor->editorUpdate();
  return 0;
}

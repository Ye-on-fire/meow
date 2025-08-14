#include "Editor.hpp"
#include "Logger.hpp"
#include <memory>

#define PROJECT_NAME meow
#define VERSION 0.0.1

int main() {
  Logger::Init();
  spdlog::info("Meow launched");
  auto editor = std::make_unique<Editor>();
  editor->editorInit();
  for (;;) {
    editor->editorUpdate();
  }
  return 0;
}

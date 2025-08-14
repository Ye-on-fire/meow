#include "Editor.hpp"
#include "Logger.hpp"
#include <memory>

#define PROJECT_NAME meow
#define VERSION 0.0.1

int main(int argc, char **argv) {
  Logger::Init();
  spdlog::info("Meow launched");
  auto editor = std::make_unique<Editor>();
  if (argc >= 2) {
    editor->editorLoadFile(argv[1]);
  }
  editor->editorInit();
  for (;;) {
    editor->editorUpdate();
  }
  spdlog::info("program exited");
  return 0;
}

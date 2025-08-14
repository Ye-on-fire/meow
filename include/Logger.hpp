#pragma once
#include <iostream>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

namespace Logger {
inline void Init() {
  try {
    auto logger = spdlog::rotating_logger_mt("main_logger", "logs/log.txt",
                                             1024 * 1024 * 5, 3);
    spdlog::set_default_logger(logger);
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%t] %v");
    spdlog::set_level(spdlog::level::debug);
  } catch (const spdlog::spdlog_ex &ex) {
    std::cerr << "Log init failed: " << ex.what() << std::endl;
  }
}
} // namespace Logger

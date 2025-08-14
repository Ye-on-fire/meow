#pragma once
#include <iostream>
#include <spdlog/sinks/rotating_file_sink.h> // 滚动日志接收器
#include <spdlog/spdlog.h>

namespace Logger {
inline void Init() {
  try {
    auto logger = spdlog::rotating_logger_mt("main_logger", "logs/app.log",
                                             1024 * 1024 * 5, 3);
    spdlog::set_default_logger(logger); // 设为全局默认
    spdlog::set_pattern("[%Y-%m-%d %H:%M:%S.%e] [%^%l%$] [%t] %v");
    spdlog::set_level(spdlog::level::debug);
  } catch (const spdlog::spdlog_ex &ex) {
    std::cerr << "Log init failed: " << ex.what() << std::endl;
  }
}
} // namespace Logger

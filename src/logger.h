#pragma once

#include <mutex>
#include <optional>

#include "spdlog/async_logger.h"

class Logger
{
public:
    Logger(const std::string &service_name, spdlog::level::level_enum l, int max_files,
           int max_file_size, const char *log_file);
    bool Enabled(spdlog::level::level_enum l) const;
    void Log(spdlog::level::level_enum l, const std::string &message) const;
    void Trace(const std::string &message) const;
    void Debug(const std::string &message) const;
    void Info(const std::string &message) const;
    void Warn(const std::string &message) const;
    void Error(const std::string &message) const;
    void Critical(const std::string &message) const;
    static void Reset();

private:
    std::optional<spdlog::sink_ptr> sink;
    spdlog::level::level_enum log_level;
    // std::shared_ptr<spdlog::async_logger> logger;
    std::shared_ptr<spdlog::logger> logger;
};

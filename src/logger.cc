#include "logger.h"

#include <iomanip>
#include <iostream>

#include "spdlog/spdlog.h"
#include "spdlog/async.h"
#include "spdlog/sinks/rotating_file_sink.h"

Logger::Logger(const std::string &service_name, spdlog::level::level_enum l,
               int max_files, int max_file_size, const char *log_file)
{
    std::string level_name = spdlog::level::to_string_view(l).data();

    sink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>(
        log_file, max_file_size, max_files);
    spdlog::init_thread_pool(spdlog::details::default_async_q_size, 1U);

    auto tp = spdlog::thread_pool();
    logger = std::make_shared<spdlog::async_logger>(
        service_name, sink.value(), tp,
        spdlog::async_overflow_policy::overrun_oldest);

    spdlog::initialize_logger(logger);
    logger->set_pattern("[%Y-%m-%d %T.%e %z] [%^%l%$] [%n] %v");
    logger->set_level(l);
    // spdlog::flush_every(std::chrono::seconds(5));
    Info("logger init successful. log_level = " + level_name);
}

bool Logger::Enabled(spdlog::level::level_enum l) const { return l >= log_level; }
void Logger::Log(spdlog::level::level_enum l, const std::string &message) const
{
    logger->log(l, message);
}
void Logger::Trace(const std::string &message) const
{
    logger->trace(message);
}
void Logger::Debug(const std::string &message) const
{
    logger->debug(message);
}
void Logger::Info(const std::string &message) const
{
    logger->info(message);
}
void Logger::Warn(const std::string &message) const
{
    logger->warn(message);
}
void Logger::Error(const std::string &message) const
{
    logger->error(message);
}
void Logger::Critical(const std::string &message) const
{
    logger->critical(message);
}

void Logger::Reset()
{
    spdlog::details::registry::instance().flush_all();
    spdlog::drop_all();
}

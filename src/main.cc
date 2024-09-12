#include <iostream>
#include <chrono>
#include <thread>
#include "logger.h"

int main()
{
    std::cout << "Hellow world!\n";
    std::string name = "jacob-test";

    Logger logger(name, spdlog::level::level_enum::info, 3, 1024000, "/Users/test/Projects/cppapp/app.log");

    int i = 0;
    while (true)
    {
        logger.Info("Number of sleep cycles: " + std::to_string(i++));
        std::this_thread::sleep_for(std::chrono::milliseconds(10000));
    }
}
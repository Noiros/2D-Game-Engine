#include "Logger.h"
#include <iostream>

void Logger::Log(std::string msg)
{
    LogEntry logEntry;
    logEntry.type = LogType::info;
    logEntry.msg = msg;

    messages.push_back(logEntry);

    std::cout << ANSI_COLOR_GREEN << "LOG " << logEntry.msg << ANSI_RESET << std::endl;
}

void Logger::Err(std::string msg)
{
    LogEntry logEntry;
    logEntry.type = LogType::error;
    logEntry.msg = msg;

    messages.push_back(logEntry);

    std::cout << ANSI_COLOR_RED << "LOG " << logEntry.msg << ANSI_RESET << std::endl;
}

#pragma once
#include "Logger.h"

namespace DVLib
{
    class LoggerManager
    {
    private:
        static Logger* m_logger;
    public:
        static void Register(Logger& logger);

        static void Log(const std::wstring& message);
    };
}
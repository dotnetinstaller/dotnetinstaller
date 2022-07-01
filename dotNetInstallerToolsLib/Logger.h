#pragma once
#include <string>

namespace DVLib
{
    class Logger
    {
    public:
        virtual ~Logger() {}
        virtual void Log(const std::wstring& message) = 0;
    };
}
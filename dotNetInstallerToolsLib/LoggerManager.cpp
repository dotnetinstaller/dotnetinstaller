#pragma once
#include "stdafx.h"
#include "Logger.h"
#include "LoggerManager.h"

void DVLib::LoggerManager::Register(Logger& logger)
{
    m_logger = &logger;
}

void DVLib::LoggerManager::Log(const std::wstring& message)
{
    if (m_logger != 0)
    {
        m_logger->Log(message);
    }
}

DVLib::Logger* DVLib::LoggerManager::m_logger = NULL;
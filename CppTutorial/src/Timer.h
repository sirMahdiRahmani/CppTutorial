#pragma once
#include "pch.h"

struct Timer
{
    std::string JobName;
    std::chrono::time_point<std::chrono::steady_clock> startPoint, endPoint;

    Timer(const char* jobname);

    ~Timer();
};
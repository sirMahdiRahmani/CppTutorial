#pragma once
#include "pch.h"

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> startPoint, endPoint;

    Timer();

    ~Timer();
};
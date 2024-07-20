#pragma once
#include "pch.h"

struct Timer
{
    std::chrono::time_point<std::chrono::steady_clock> start, end;
    std::chrono::duration<float> duration;

    Timer();

    ~Timer();
};
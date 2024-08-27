#pragma once

#include <iostream>
#include <vector>
//#include <array>
#include <string>
#include <map>
#include <set>
#include <tuple>
#include <thread>
#include <utility>
#include <functional>
#include <algorithm>
#include <memory>
#include <chrono>
#include <fstream>
#include <optional>
#include <cstdio>
#include <variant>
#include <future>
#include "Timer.h"
#include "Instrumentor.h"
#include "AllocationMetrics.h"
#include "Array.h"

#define PROFILING 1

#if PROFILING

#define PROFILE_SCOPE(name) InstrumentationTimer timer ##__LINE__(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)

#else

#define PROFILE_SCOPE(name)
#define PROFILE_FUNCTION() PROFILE_SCOPE(__FUNCTION__)

#endif

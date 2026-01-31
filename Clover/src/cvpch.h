#pragma once

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>

#include <string>
#include <sstream>
#include <ostream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Clover/Core/Log.h"

#include "Clover/Debug/Instrumentor.h"

#ifdef CLOVER_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
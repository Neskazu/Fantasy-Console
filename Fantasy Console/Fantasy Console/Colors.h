#pragma once

#include "raylib.h"

namespace Colors {
    // Base colors
    static const Color baseColors[] = {
        LIGHTGRAY, GRAY, DARKGRAY, YELLOW,
        GOLD, ORANGE, PINK, RED, MAROON,
        GREEN, LIME, DARKGREEN, SKYBLUE,
        BLUE, DARKBLUE, PURPLE
    };
    static const int numBaseColors = sizeof(baseColors) / sizeof(baseColors[0]);
}
 
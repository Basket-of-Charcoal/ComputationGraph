#pragma once

#include <cmath>

#define EPS_FLOAT 1e-6

bool float_equals(float a, float b)
{
    return abs(a - b) < EPS_FLOAT;
}
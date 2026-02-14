#include "math_utils.h"

// static ensures internal linkage so only accessible to current translation units
static int hidden = 42;

int global_val = 100;

int add(int a, int b)
{
    return a + b + hidden;
}
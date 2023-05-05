#include "pch.h"

#include <cmath>
#include "cubic.h"

double APIENTRY cubic(double d)
{
  if (d < 0)
  {
    return -1;
  }
  return pow(d, 3);
}

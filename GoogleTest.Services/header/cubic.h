
#ifndef CUBIC_H
#define CUBIC_H

#ifdef GOOGLETESTSERVICES_EXPORTS
#define GOOGLETESTSERVICES_API __declspec(dllexport)
#else
#define GOOGLETESTSERVICES_API __declspec(dllimport)
#endif

GOOGLETESTSERVICES_API double cubic(double d);

#endif // CUBIC_H

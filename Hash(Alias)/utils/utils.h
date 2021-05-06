#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>

typedef unsigned long long llu;

/*
 * Given an integer returns true if it is a prime and false if not
 */
bool __isPrime(llu current);

/*
 * Iteratively checks the numbers greater than or equal to input
 * for the smallest prime
 */
llu nextPrime(llu current);

#endif

#include "utils.h"

/*
 * We manually decide outputs for numbers from 0 to 5
 * We then iterate through numbers starting from input till we find a prime
 * we use the knowledge that multiples of 2 and 3 are not primes
 * i.e. we check all numbers of the form
 * 6 * k + {1, 5}
 * We use XOR to switch between adding 2 and 4 to current numbers
 * 2 xor 6 = 4 and 4 xor 6 = 2
 * usage of this bit operation speeds up computation
 * as opposed to using the % operator for the incrementing variable
 */

llu nextPrime(llu input) {
  if (input < 0)
    return -1;

  switch (input) {
  case 0:
  case 1:
  case 2:
    return 2;
  case 3:
    return 3;
  case 4:
  case 5:
    return 5;
  }

  llu i = input % 6;
  llu x = i < 2 ? 1 : 5;
  input = 6 * (input / 6) + x;
  for (i = (3 + x) / 2; !__isPrime(input); input += i)
    i ^= 6;

  return input;
}

bool __isPrime(llu input) {
  llu x = 4;
  for (llu i = 5; true; i += x) {
    if (input % i == 0)
      return false;
    llu q = input / i;
    if (q < i)
      return true;
    x ^= 6;
  }
  return true;
}

// Write a pseudo-code by commenting in the file then implement a program in to
// enter a natural number n and verify whether n is sphenic. Calculate the complexity
// of your program.
// Note: A sphenic number is a product of p*q*r where p, q, and r are three distinct
// prime numbers. Example: 30 = 2 * 3* 5; 42 = 2*3*7; 66 = 2*3*11

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void primeNum(int primes[], int length);
bool checkIfSphenic(int primes[], int length, int input);

void main() {
  for (int i=3; i<100; i++) {
    int length = (int) (i/((int) log(i)));
    int primes[length];
    primeNum(primes, length);
    if (checkIfSphenic(primes, length, i)) {
      printf("%d ", i);
    }
  }
}

void primeNum(int primes[], int length) {
  primes[0] = 2;
  int temp = 2;
  for (int i = 1; i < length; i++) {
    bool found = false;
    temp++;
    for (int j = 0; j < i; j++) {
      if ((temp % primes[j]) == 0)
        break;
      if ((j+1)==i) {
        primes[i] = temp;
        found = true;
        break;
      }
    }
    if (!found) 
      i--;
  }
}

bool checkIfSphenic(int primes[], int length, int input) {
  int count = 0;
  for (int i = 0; i<length; i++) {
    if (input % primes[i] == 0) {
      input /= primes[i];
      count++;
      if (count > 3) return false;
      if (input == 1 && count == 3) {
        return true;
      }
    }
  }
  return false;
}
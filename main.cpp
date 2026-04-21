#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

long long computePrimeLike(int n) {
  long long sum = 0;

  for (int i = 2; i <= n; i++) {
    bool isPrime = true;

    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }

    if (isPrime) sum += i;
  }

  return sum;
}

int fib(int n) {
  if (n <= 1) return n;
  return fib(n - 1) + fib(n - 2);
}

int randomWork(int seed) {
  srand(seed);

  int total = 0;
  for (int i = 0; i < 10000; i++) {
    int r = rand() % 100;

    if (r % 2 == 0)
      total += r;
    else
      total -= r;
  }

  return total;
}

void mixedWorkload(int n) {
  cout << "Prime-like sum: " << computePrimeLike(n) << endl;
  cout << "Fib result: " << fib(20) << endl;
  cout << "Random work: " << randomWork(n) << endl;
}

void heavyTask(int mode) {
  if (mode % 3 == 0) {
    mixedWorkload(500);
  } else if (mode % 3 == 1) {
    mixedWorkload(700);
  } else {
    mixedWorkload(900);
  }
}

int main() {
  cout << "Starting gprof demo..." << endl;

  for (int i = 1; i <= 5; i++) {
    heavyTask(i);
  }

  cout << "Done." << endl;
  return 0;
}
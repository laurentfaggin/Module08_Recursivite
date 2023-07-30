#include "fibonacci.h"

int suiteDeFibonacci_rec(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		return suiteDeFibonacci_rec(n - 1) + suiteDeFibonacci_rec(n - 2);
	}
}

int suiteDeFibonacci(int n) {
	if (n <= 0) {
		return 0;
	}
	else {
		return suiteDeFibonacci_rec(n);
	}
}
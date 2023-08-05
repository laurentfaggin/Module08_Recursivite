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

int suiteDeFibonacciUpgrade_rec(int n, int* p_valeursDejaCalculees) {
	if (n == 0 || n == 1) {
		return n;
	}
	else {
		if (p_valeursDejaCalculees[n] != n) {
			p_valeursDejaCalculees[n] = suiteDeFibonacciUpgrade_rec(n-1, p_valeursDejaCalculees) + suiteDeFibonacciUpgrade_rec(n-2, p_valeursDejaCalculees);
		}
		return p_valeursDejaCalculees[n];
	}
}

int suiteDeFibonacciUpgrade(int n) {
	int* valeursDejaCalculees = new int[n+1];
	if (n <= 0) {
		return 0;
	}
	else {
		return suiteDeFibonacciUpgrade_rec(n, valeursDejaCalculees);
	}
}
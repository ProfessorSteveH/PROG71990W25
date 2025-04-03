#include <stdio.h>

// prog71990-w25 - steveh - week12

// recursion - solve a problem by breaking it down into 
// smaller, similar subproblems until a base case (a 
// condition that stops the recursion) is reached.

// a useful programming construct, but *in C* we should only
// use recursion when absolutely required (use a loop as often 
// as possible)

//	base/exit case - how will i know when i am done
//  step function - repeatable function per iteration 

// let's consider the math function 'factorial'

//	     4!
//			0! = 1 

//		4! = 4 * 3 * 2 * 1 * (0 replaced by 1)
//		4! = 4 * 3!
//               3! = 3 * 2!
//                        2! = 2 * 1!
//                                 1! = 1 * 0!
//                                 0

int rFactorial(int n) {
	if (n == 0)				//base case (or exit)
		return 1;
	else {
		return (n * rFactorial(n - 1));
	}
}

int factorial(int n) {
	unsigned long long total = 1;
	for (int i = 1; i <= n; i++)
		total *= i;

	return total;
}

int main(void) {
	printf("%d\n", rFactorial(4));

	return 0;
}
#define MAX_SIZE 31

int fib_memo[MAX_SIZE];

int fib(int n) {
		// subproblem already solved
		if(n == 1 || n == 2) {
				fib_memo[n] = 1;
				return fib_memo[n];
		}

		if(fib_memo[n] == 0 && n != 0)
				fib_memo[n] = fib(n - 1) + fib(n - 2);
	
		return fib_memo[n];
}



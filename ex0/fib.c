long fibvals[1000];             // Array declaration.

long fib(long m)                // Calculate the mth digit in the Fibonacci sequence.
{
    long f1 = 0, f2 = 1;        // Initialise variables f1 & f2 as the first digits in the sequence.
    for(int i = 0; i < m; i++)  // Create a variable i with value 0. Loop m times. After each loop, add 1 to i.
    {
        fibvals[i] = f1 + f2;   // The ith digit of the sequence is equal to f1 + f2.
        f1 = f2;                // Move f1 to the next digit in the sequence.
        f2 = fibvals[i];        // Move f2 to the next digit in the sequence.
    }
    return f2;                  // After we have calculated the whole sequence up until the mth digit, we return the mth digit.
}
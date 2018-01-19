long fib(long m)
{
    long f1 = 0, f2 = 1, temp;
    while(m > 1)
    {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    return f2;
}
long fib(long m)
{
    long f1 = 0, f2 = 1, temp;
    for(int i = 0; i < m; i++)
    {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    return f2;
}
// Computes modulo 2
int mod2(int a)
{
	return a%2;
}

// Fills a matrix of size n x n with random bits
void fill(int* p, int n)
{
	int i;	
	for (i = 0; i < n; ++i)
    p[i] = mod2(rand()); 
}


// Prints a matrix of size n x n
void print(int* p, int n)
{
	int i,j;
  	for (i = 0; i < n; ++i)
  	{
		for (j = 0; j < n; ++j)
			printf("%d \t", p[i*n+j]);
		printf("\n");
	}		
}



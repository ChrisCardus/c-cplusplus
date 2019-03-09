#include<stdio.h>
#include<stdlib.h>

#include "cpucycles.c"
#include "helper_functions.c"
#include "matmul_reference.c"
#include "matmul_optimized.c"


int main(){
	int i, j;
	int n = 2048;	// Number of rows or columns in the square matrices
	int *A, *B;		// Input matrices
	int *C1, *C2;	// Output matrices from the reference and optimized implementations

	// Performance and correctness measurement declarations
	long int CLOCK_start, CLOCK_end, CLOCK_total, CLOCK_ref, CLOCK_opt;
	long int COUNTER, REPEAT=5;
	int difference;
	float speedup;

	// Allocate memory for the matrices
	A = malloc(n*n*sizeof(int));
	B = malloc(n*n*sizeof(int));
	C1 = malloc(n*n*sizeof(int));
	C2 = malloc(n*n*sizeof(int));

	// Fill bits in A, B, C1		
	fill(A, n*n);
	fill(B, n*n);
	fill(C1, n*n);

	// Initialize C2 = C1
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			C2[i*n+j] = C1[i*n+j];

	
	// Measure performance of the reference implementation
	CLOCK_total=0;
	for(COUNTER=0; COUNTER<REPEAT; COUNTER++)
	{
		CLOCK_start = cpucycles();
		matmul_reference(n, A, B, C1);
		CLOCK_end = cpucycles();
		CLOCK_total = CLOCK_total + CLOCK_end - CLOCK_start;
	}
	CLOCK_ref = CLOCK_total/REPEAT;
	printf("n=%d Avg cycle count for reference implementation = %ld\n", n, CLOCK_ref);
	
	// Measure performance of the optimized implementation
	CLOCK_total=0;
	for(COUNTER=0; COUNTER<REPEAT; COUNTER++)
	{
		CLOCK_start = cpucycles();
		matmul_optimized(n, A, B, C2);
		CLOCK_end = cpucycles();	
		CLOCK_total = CLOCK_total + CLOCK_end - CLOCK_start;
	}
	CLOCK_opt = CLOCK_total/REPEAT;
	printf("n=%d Avg cycle count for optimized implementation = %ld\n", n, CLOCK_opt);
	
	speedup = (float) CLOCK_ref/(float) CLOCK_opt;
 	
	// Check correctness by comparing C1 and C2
	difference = 0;		
	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			difference = difference + C1[i*n+j] - C2[i*n+j];

	if(difference==0) printf("Speedup factor = %.2f\n", speedup);
	if(difference!=0) printf("Reference and optimized implementations do not match\n");
	
	//print(C2, n);	
	
	free(A);
	free(B);
	free(C1);
	free(C2);
	return 0;
}

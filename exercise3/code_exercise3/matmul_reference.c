/* This routine performs a matrix multiplication operation
 * C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. 
*/    
void matmul_reference(int n, int* A, int* B, int* C)
{
	int i, j, k;
	int cij;
  	for(i=0; i < n; ++i)
	{
    	for(j=0; j < n; ++j) 
    	{
		  	cij = C[i+j*n];
		  	for(k=0; k<n; ++k)
			{
				cij += A[i+k*n]*B[k+j*n];
			}
		  	C[i+j*n] = mod2(cij);
    	}
	}
}

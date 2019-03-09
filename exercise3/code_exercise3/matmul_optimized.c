/* Optimized implementation of matrix multiplication 
 * This routine performs a matrix multiplication operation
 * C := C + A * B
 * where A, B, and C are n-by-n matrices stored in column-major format.
 * On exit, A and B maintain their input values. 
 * DO NOT change the API of the function matmul_optimized()	
*/    
void matmul_optimized(int n, int* A, int* B, int* C)
{

	// Replace code here 
	matmul_reference(n, A, B, C);
	// with your optimized code
}

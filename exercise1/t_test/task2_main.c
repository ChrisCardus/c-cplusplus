#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "task2.c"

int main()
{
	int i, size1, size2;

	// reading the number of measurements in group1 
	scanf("%d", &size1);		
	float *measurements1 = malloc(size1*sizeof(float));
	// reading the measurements in group1 	
	for(i=0; i<size1; i++)
	scanf("%f", measurements1+i);

	// reading the number of measurements in group2 
	scanf("%d", &size2);		
	float *measurements2 = malloc(size2*sizeof(float));
	// reading the measurements in group1 	
	for(i=0; i<size2; i++)
	scanf("%f", measurements2+i);

	float t = t_test(measurements1, size1, measurements2, size2);
	printf("t=%f\n", t);

	if(t<4.5) printf("Two groups are not significantly different\n");
	else printf("Two groups are significantly different\n");

	printf("Correct t value will be 14.106547\n"); 
	free(measurements1);
	free(measurements2);
	return 0;
}

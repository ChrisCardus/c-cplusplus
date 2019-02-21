#include<stdio.h>
#include<stdlib.h>
#include "task1.c"

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



	float median1 = sort_and_find_median(measurements1, size1);
	int new_size1;
	float *measurements1_wo_outliers = discard_outliers(measurements1, size1, median1, &new_size1);

	float median2 = sort_and_find_median(measurements2, size2);
	int new_size2;
	float *measurements2_wo_outliers = discard_outliers(measurements2, size2, median2, &new_size2);

	// writing measurements for group1 after discarding the outliers
	printf("%d\n", new_size1);
	for(i=0; i<new_size1; i++)
	printf("%.2f\n", measurements1_wo_outliers[i]);

	printf("\n");
	// writing measurements for group2 after discarding the outliers
	printf("%d\n", new_size2);
	for(i=0; i<new_size2; i++)
	printf("%.2f\n", measurements2_wo_outliers[i]);


	free(measurements1);
	free(measurements2);
	free(measurements1_wo_outliers);
	free(measurements2_wo_outliers);
	return 0;
}

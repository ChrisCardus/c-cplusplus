#include "task1.c"
#include <math.h>

// Function for computing mean and variance
// The mean is stored in *mean and the variance is stored in *variance 
void mean_variance(float *measurements, int size, float *mean, float *variance)
{
	int i;
	float sum=0;

    //  Compute  mean	
    for (i = 0; i < size; i++)
    {
        sum = sum + measurements[i];
    }
    *mean = sum /size;

    //  Compute  variance
	sum = 0;	
    for (i = 0; i < size; i++)
    {
        sum = sum + (measurements[i]-*mean)*(measurements[i]-*mean);
    }
    *variance = sum /(size-1);
}

//For squaring floats
float squarer(float number)
{
    return (number * number);
}

//Function for computing the Standard Deviation of a list using recursion
float standard_deviation_helper(float *list, int size, float mean, int count)
{
    float total = 0;
    int i = count + 1;
    if(count < size)
    {
        total = squarer(list[count] - mean) + standard_deviation_helper(list, size, mean, i);
    }
    return total;
}

// Function for computing the t-static
// For computing square-root of a float data 'a' use b = sqrt(a) where type of b is also float.
float t_test(float *measurements1, int size1, float *measurements2, int size2)
{
	float t=0;
    int *new_size1 = malloc(sizeof(int));
    int *new_size2 = malloc(sizeof(int));

    float *measurements1_wo_outliers = discard_outliers(measurements1, size1, sort_and_find_median(measurements1, size1), new_size1);
    float *measurements2_wo_outliers = discard_outliers(measurements2, size2, sort_and_find_median(measurements2, size2), new_size2);

    float mean1 = 0;
    float mean2 = 0;

    float sd1 = 0;
    float sd2 = 0;

    float S = 0;

    //Calculate the mean for measurements1_wo_outliers
    for(int i = 0; i < *new_size1; i++)
    {
        mean1 += measurements1_wo_outliers[i];
    }

    mean1 = mean1 / *new_size1;

    //Calculate the mean for measurements2_wo_outliers
    for(int i = 0; i < *new_size2; i++)
    {
        mean2 += measurements2_wo_outliers[i];
    }

    mean2 = mean2 / *new_size2;

    //Calculate the standard deviation for both of the new lists
    sd1 = standard_deviation_helper(measurements1_wo_outliers, *new_size1, mean1, 0) / (*new_size1-1);
    sd2 = standard_deviation_helper(measurements2_wo_outliers, *new_size2, mean2, 0) / (*new_size2-1);

    S = sqrt((sd1 / *new_size1) + (sd2 / *new_size2));

    t = (mean1 - mean2) / S;

    free(new_size1);
    free(new_size2);
    free(measurements1_wo_outliers);
    free(measurements2_wo_outliers);

	return t;
}


// function to sort the array in ascending order
float sort_and_find_median(float *measurements , int size)
{ 

    int i=0 , j=0;
    float temp=0;

    for(i=0 ; i<size ; i++)
    {
        for(j=0 ; j<size-1 ; j++)
        {
            if(measurements[j]>measurements[j+1])
            {
                temp        = measurements[j];
                measurements[j]    = measurements[j+1];
                measurements[j+1]  = temp;
            }
        }
    }
	
	return measurements[size/2];
}

float *discard_outliers(float *measurements, int size, float median, int *new_size)
{
    float lowerBound = 0.5 * median;
	float upperBound = 1.5 * median;
    int outliers = 0;
    int j = 0;
    
    //Loop through the array to count the number of outliers.
    for(int i = 0; i < size; i++)
    {
        if(measurements[i] < lowerBound || measurements[i] > upperBound)
        {
            outliers++;
        }
    }

    //Set new_size based on number of outliers.
    *new_size = size - outliers;

    //Create and allocate memory for the array without outliers.
    float *measurements_wo_outliers = malloc((*new_size) * sizeof(float));

    //Loop through the measurements array to copy only those values which are not outliers.
    for(int i = 0; i < size; i++)
    {
        if(measurements[i] >= lowerBound && measurements[i] <= upperBound)
        {
            measurements_wo_outliers[j] = measurements[i];
            j++;
        }
    }
    
    return measurements_wo_outliers;
}
/*
Given An Array of Elements, Finding out Two Sum
Based on Given Target Sum. Print Set of Indexes of Matched
Two Sum's Two Paired Value From the Array with Value of Indexes.
*/

#include<stdio.h>

int main ()
{
    int i, j;
    int counter = 0, previousCounter = 0;
    int numberArray;

    printf("How many Elements to Store in Array: ");
    scanf("%d", &numberArray);

    int arr[numberArray];

    printf("Input Elements:\n");

    for(int i = 0; i < numberArray; i++)
    {
        scanf("%d", &arr[i]);
    }

    int target;

    printf("Target Two Sum: ");
    scanf("%d", &target);

    printf("\nTwo Sum Target's Matched Indexes & values :\n");

    printf("[");

    for(i = 0; i < numberArray; i++)
    {
        previousCounter = counter;

        for(j = i+1; j < numberArray; j++)
        {
            if(i == j)
            {
                continue;
            }
            
            if(arr[i] + arr[j] == target)
            {
                counter ++;

                if(counter != 0 && previousCounter < counter)
                {
                    printf("\n [ %d -> %d, %d -> %d ]\n", i, arr[i], j, arr[j]);
                }
            }
        }
    }

    if(counter == 0)
    {
        printf("No Possible Solution Available");
    }

    printf("]\n");

    return 0;
}

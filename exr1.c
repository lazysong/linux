#include <stdio.h>
#include <stdlib.h>

/*
A solution of challenge in leetcode

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?

link:https://leetcode.com/problems/single-number-iii/
*/
int *single_number(int nums[], int nums_size, int *return_size);

int main()
{
	int nums[] = {0, 1, 1, 2};
	int return_size;
	int *result = single_number(nums, 4, &return_size);
	int i;	
	for (i = 0; i < return_size; i++)
	{
		printf("result[%d] = %d\n", i, result[i]);
	}
	return 0;
}

int *single_number(int nums[], int nums_size, int *return_size)
{
	int i, j, temp, equals;
	*return_size = 0;
	const TEMP_SIZE = 100;
	int *temp_result = (int *)malloc(sizeof(int) * TEMP_SIZE);
	for (i = 0; i < nums_size; i++)
	{
		equals = 0;
		for (j = nums_size - 1; i < j; j--)
		{
			if (nums[i] == nums[j])
			{
				temp = nums[i+1];
				nums[i+1] = nums[j];
				nums[j] = temp;
				i++;
				equals = 1;
				break;	
			}
		}
		if (i == j && !equals)
			temp_result[(*return_size)++] = nums[i];
	}
	int *result = (int *)malloc(sizeof(int) * (*return_size));
	for (i = 0; i < *return_size; i++)
	{
		result[i] = temp_result[i];
	}
	free(temp_result);
	return result;
}

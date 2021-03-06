#include <iostream>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define LINE_MAX 17000
static int vv[LINE_MAX] = {0};
static void dfs(int *nums, int numsSize, int *path, int **result, int idx, int *reIndex, int *returnColumnSizes)
{
	if (idx >= numsSize)
	{
		result[*reIndex] = (int *)malloc(sizeof(int) * numsSize);
		int j = 0;
		for (int i = 0; i < numsSize; i++)
		{
			if (vv[i] == 1)
			{
				result[*reIndex][j] = nums[i];
				printf(" %d ", nums[i]);
				j++;
			}
		}
		returnColumnSizes[*reIndex] = j;
		printf("\n");
		*reIndex = *reIndex + 1;
		return;
	}

	vv[idx] = 1;
	dfs(nums, numsSize, path, result, idx + 1, reIndex, returnColumnSizes);
	vv[idx] = 0;
	dfs(nums, numsSize, path, result, idx + 1, reIndex, returnColumnSizes);

	return;
}

int **subsetsWithDup(int *nums, int numsSize, int *returnSize, int **returnColumnSizes)
{
	for (int i = 0; i < numsSize; i++){
		for (int j = i; j < numsSize; j++){
			if (nums[i] > nums[j]){
				int tmp = nums[i];
				nums[i] = nums[j];
				nums[j] = tmp;
			}
		}
	}
	int **result = (int **)malloc(LINE_MAX * sizeof(int *));
	int reIndex = 0;
	int path[LINE_MAX];

	*returnColumnSizes = (int *)malloc(sizeof(int) * LINE_MAX);
	memset(*returnColumnSizes, 0, sizeof(int) * LINE_MAX);

	dfs(nums, numsSize, path, result, 0, &reIndex, *returnColumnSizes);
	*returnSize = reIndex;

	//for (int i = 0; i < reIndex; i++)
	//{
	//	(*returnColumnSizes)[i] = numsSize;
	//}

	return result;
}

void subsets_ii_90()
{
	int p = 0;
	int *pp = NULL;
	int **ppp = NULL;
	int height[] = {1, 3, 2};
	ppp = subsetsWithDup(height, sizeof(height) / sizeof(int), &p, &pp);
	return;
}
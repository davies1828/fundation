#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <criterion/criterion.h>

int *left_rotate(int arr_size, int *arr, int round)
{
	int i, idx = round;
	int *ans = (int *)malloc(sizeof(int) * arr_size);

	if (arr_size == round) {
		ans = arr;
		return ans;
	}

	for (i = 0; i < arr_size; i++) {
		ans[i] = arr[idx];
		if (idx == (arr_size - 1))
			idx = 0;
		else
			idx++;
	}

	for(i = 0; i < arr_size; i++)
		printf("%d ", ans[i]);

	printf("\n");

	return ans;
}


Test(basicTests, should_pass_all_the_tests_provided) {

	int array1[] = { 1, 2, 3, 4, 5 };
	int ans1[] = { 5, 1, 2, 3, 4 };
	int i, arr1_size = 5, rnd1 = 4;
	int *sum1 = left_rotate(arr1_size, array1, rnd1);
	for (i = 0; i < arr1_size; i++) {
		cr_expect_eq(ans1[i], sum1[i], "Index : '%d' Expected: '%d' But actual: '%d'", i, ans1[i], sum1[i]);
	}

	int array2[] = { 1, 2, 3, 4, 5 };
	int ans2[] = { 1, 2, 3, 4, 5 };
	int arr2_size = 5, rnd2 = 5;
	int *sum2 = left_rotate(arr2_size, array1, rnd2);
	for (i = 0; i < arr2_size; i++) {
		cr_expect_eq(ans2[i], sum2[i], "Index : '%d' Expected: '%d' But actual: '%d'", i, ans2[i], sum2[i]);
	}

	int array3[] = { 1, 2, 3, 4, 5 };
	int ans3[] = { 2, 3, 4, 5, 1 };
	int arr3_size = 5, rnd3 = 1;
	int *sum3 = left_rotate(arr3_size, array1, rnd3);
	for (i = 0; i < arr3_size; i++) {
		cr_expect_eq(ans3[i], sum3[i], "Index : '%d' Expected: '%d' But actual: '%d'", i, ans3[i], sum3[i]);
	}	

}


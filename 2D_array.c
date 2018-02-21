#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>
#include <criterion/criterion.h>

int hourglass_sum(int *arr)
{
	int i, j, index;
	int sum, max = -63;

	for (i = 7; i < 31; i = i + 6) {
		for (j = 0; j < 4; j++) {
			sum = arr[i-7+j] + arr[i-6+j] + arr[i-5+j] + arr[i+j] + arr[i+5+j] + arr[i+6+j] + arr[i+7+j];	
		
			if (sum > max) {
				max = sum;
				printf("i=%d, j=%d, sum = %d, max=%d\n", i, j, sum, max);
			}
		}
	}
	printf("\n");
	return max;
}

#if 1
Test(basicTests, should_pass_all_the_tests_provided) {
/*
	int array1[] = { 1,1,1,0,0,0,
			 0,1,0,0,0,0,
			 1,1,1,0,0,0,
			 0,0,2,4,4,0,
			 0,0,0,2,0,0,
			 0,0,1,2,4,0 };
	int ans1 = 19;
	int sum1 = hourglass_sum(array1);
	cr_expect_eq(ans1, sum1, "Expected: '%d' But actual: '%d'", ans1, sum1);

	int array2[] = { 1,1,1,0,0,0,
			 0,1,0,0,0,0,
			 1,1,1,0,0,0,
			 0,0,0,0,0,0,
			 0,0,0,0,0,0,
			 0,0,0,0,0,0 };
	int ans2 = 7;
	int sum2 = hourglass_sum(array2);
	cr_expect_eq(ans2, sum2, "Expected: '%d' But actual: '%d'", ans2, sum2);

	int array3[] = {1,1,1,0,0,0,
			0,1,0,0,0,0,
			1,1,1,0,0,0,
			0,9,2,-4,-4,0,
			0,0,0,-2,0,0,
			0,0,-1,-2,-4,0,1};
	int ans3 = 13;
	int sum3 = hourglass_sum(array3);
	cr_expect_eq(ans3, sum3, "Expected: '%d' But actual: '%d'", ans3, sum3);
*/
	int array4[] = { 0, -4, -6, 0, -7, -6,
			-1, -2, -6, -8, -3, -1,
			-8, -4, -2, -8, -8,-6,
			-3, -1, -2, -5, -7, -4,
			-3, -5, -3, -6, -6, -6,
			-3, -6, 0, -8, -6, -7 };
	int ans4 = -19;
	int sum4 = hourglass_sum(array4);
	cr_expect_eq(ans4, sum4, "Expected: '%d' But actual: '%d'", ans4, sum4);

	int array5[] = { -1, -1, 0, -9, -2, -2,
			-2, -1, -6, -8, -2, -5,
			-1, -1, -1, -2, -3, -4,
			-1, -9, -2, -4, -4, -5,
			-7, -3, -3, -2, -9, -9,
			-1, -3, -1, -2, -4, -5 };
	int ans5 = -6;
	int sum5 = hourglass_sum(array5);
	cr_expect_eq(ans5, sum5, "Expected: '%d' But actual: '%d'", ans5, sum5);
}
#endif 
#if 0
int main()
{
	int arr[6][6] = {     1,1,1,0,0,0,
			  0,1,0,0,0,0,
			  1,1,1,0,0,0,
			  0,0,2,4,4,0,
			  0,0,0,2,0,0,
			  0,0,1,2,4,0 };
	int i, j;	
/*
	for (arr_i = 0; arr_i < 6; arr_i++) {
		for (j = 0; j < 6; j++) {         
			scanf("%d",&arr[i][j]);
		}
	}
*/
	i = hourglass_sum(arr);
	printf("%d\n", i);


	return 0;
}
#endif 

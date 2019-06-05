#include<stdio.h>
#include <assert.h>
#include <memory.h>


#define POCET 10000

void BubbleSort(int, int);
void BubbleSortOpt(int, int);
void ShakeSort(int, int);
void QuickSort(int, int, int, int);
int Partition(int, int, int, int);


main()
{
	srand(time(0));

	int *A = (int *)malloc(POCET * sizeof(int));
	int *B = (int *)malloc(POCET * sizeof(int));
	int *C = (int *)malloc(POCET * sizeof(int));
	int *D = (int *)malloc(POCET * sizeof(int));
	int times[4];
	times[3] = 0;

	for (int i = 0; i <= POCET-1; i++)
	{
		A[i] = (rand() << 15) + rand();
		B[i] = A[i];
		C[i] = A[i];
		D[i] = A[i];
	}
	printf("\t\t pocet srovnani     %%\n", times[0]);
	printf("---------------------------------------\n");

	BubbleSort(A, times);
	printf("Bubble Sort \t %i\n", times[0]);
	for (int k = 0; k < POCET - 2; ++k) assert(A[k] <= A[k + 1]);


	BubbleSortOpt(D, times);
	printf("BubbleSortOpt \t %i \t %2.5g\n", times[1], (((float)times[1] / (float)times[0]) * 100));
	assert(memcmp(A, D, POCET * sizeof(int)) == 0);
	for (int k = 0; k < POCET - 2; ++k) assert(D[k] <= D[k + 1]);

	ShakeSort(B,times);
	printf("ShakeSort \t %i \t %2.5g\n",times[2], (((float)times[2] / (float)times[0]) * 100));
	assert(memcmp(A, B, POCET * sizeof(int)) == 0);
	for (int k = 0; k < POCET - 2; ++k) assert(B[k] <= B[k + 1]);

	QuickSort(C, 0, POCET - 1, times);
	printf("QuickSort \t %i \t %1.3g\n", times[3], (((float)times[3] / (float)times[0]) * 100));
	assert(memcmp(A, C, POCET * sizeof(int)) == 0);
	for (int k = 0; k < POCET - 2; ++k) assert(C[k] <= C[k + 1]);

	printf("\n%i \t %i \t %i \t %i \t %i \t", A[POCET - 5], A[POCET - 4], A[POCET - 3], A[POCET - 2], A[POCET - 1] );

	return 0;
}


void  BubbleSort(int *A, int *times)
{
	int temp;
	int p = 0;
	for (int  i = 0; i < POCET - 1; i++)
	{
		for (int j = POCET - 1; j >= i+1; j--)
		{
			if (++p, A[j] < A[j - 1])
			{
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
			}
		}
	}
	times[0] = p;
}

void  BubbleSortOpt(int *A, int *times)
{
	int temp;
	int p = 0;
	int swapped = 1;
	for (int i = 0;i < POCET - 1; i++)
	{
		swapped = 0;
		for (int j = POCET - 1; j >= i + 1; j--)
		{
			if (++p, A[j] < A[j - 1])
			{
				temp = A[j];
				A[j] = A[j - 1];
				A[j - 1] = temp;
				swapped = 1;
			}
		}

		if (swapped == 0)
			break;
	}
	times[1] = p;
}

void  ShakeSort(int *B, int *times)
{
	int swapped = 0;
	int start = 0;
	int end = POCET - 1;
	int p = 0;
	int temp;

	do 
	{

		for (int i = 0; i < end; ++i)
		{
			if (++p, B[i] > B[i + 1])
			{
				temp = B[i];
				B[i] = B[i + 1];
				B[i + 1] = temp;
				swapped = 1;
			}
		}

		if (swapped != 1)
		{
			break;

		}

		swapped = 0;
		--end;
		for (int j = end - 1; j >= start; --j)
		{
			if (++p, B[j] > B[j + 1])
			{
				temp = B[j];
				B[j] = B[j + 1];
				B[j + 1] = temp;
				swapped = 1;
			}
		}

		++start;

	} while (swapped == 1);
	times[2] = p;
}

void QuickSort(int *A, int p, int r, int *times)
{
	int q = 0;
	//zde si nejsem uplnì jistý
	if (times[3] += 1, p < r) 
	{
		q = Partition(A, p, r, times);
		QuickSort(A, p, q - 1, times);
		QuickSort(A, q + 1, r, times);
	}
}

int Partition(int *A, int p, int r, int *times)
{
	int x = A[r];
	int i = p - 1;
	int temp;

	for (int j = p; j < r; j++)
	{
		if (times[3] += 1, A[j] <= x)
		{
			i++;
			temp = A[i];
			A[i] = A[j];
			A[j] = temp;
		}
	}
	temp = A[i + 1];
	A[i + 1] = A[r];
	A[r] = temp;

	return i + 1;
}

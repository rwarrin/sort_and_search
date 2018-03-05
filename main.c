/**
 * This program reads a list of N numbers and searches for a value I. Returns
 * the array index of I if I is Min(list) <= I <= Max(list), otherwise returns
 * -1.
 *
 * Implements a simple Insertion sort algorithm to ensure the list of N numbers
 * is sorted in ascending order before searching.
 *
 * Implements a basic Binary search algorithm to find the the target value I
 * within the list of N numbers.
 **/

#include <stdio.h>
#include <stdlib.h>

#define Assert(Condition) if(!(Condition)) { *((int *)0) = 0; }

static inline void
InsertionSort(int *Array, int Size)
{
	Assert(Array != NULL);
	Assert(Size >= 0);

	for(int SortedIndex = 1; SortedIndex < Size; ++SortedIndex)
	{
		for(int SortIndex = SortedIndex;
			((SortIndex > 0) && (Array[SortIndex] < Array[SortIndex - 1]));
			--SortIndex)
		{
			Assert((SortIndex > 0) && (SortIndex < Size));

			int Temp = Array[SortIndex];
			Array[SortIndex] = Array[SortIndex - 1];
			Array[SortIndex - 1] = Temp;
		}
	}
}

static inline int
BinarySearch(int *Array, int Size, int Target)
{
	Assert(Array != NULL);
	int Result = -1;

	int Lower = 0;
	int Upper = Size - 1;
	while(Upper > Lower)
	{
		int Middle = (Lower + Upper) / 2;
		if(Array[Middle] == Target)
		{
			Result = Middle;
			break;
		}
		else if(Target < Array[Middle])
		{
			Upper = Middle - 1;
		}
		else  // (Target > Array[Middle]
		{
			Lower = Middle + 1;
		}
	}

	return(Result);
}

static inline int
Sorted(int *Array, int Size)
{
	Assert(Array != NULL);
	Assert(Size >= 0);

	int Result = 0;
	for(int Index = 0; Index < Size-1; ++Index)
	{
		if(Array[Index] < Array[Index + 1])
		{
			Result = 1;
			break;
		}
	}
	return(Result);
}

int main(void)
{
	int Size = 0;
	scanf("%d", &Size);
	if(Size <= 0)
	{
		fprintf(stderr, "Enter a valid array size greater than zero.\n");
		return 1;
	}

	int Find = 0;
	scanf("%d", &Find);
	
	int *Array = (int *)malloc(sizeof(int) * Size);
	if(Array == NULL)
	{
		fprintf(stderr, "Not enough memory");
		return 2;
	}

	int ReadCount = 0;
	int ReadNumber = 0;
	while(scanf("%d", &ReadNumber) != EOF)
	{
		Array[ReadCount++] = ReadNumber;
	}

	InsertionSort(Array, ReadCount);
	Assert(Sorted(Array, ReadCount));

	int FoundPosition = BinarySearch(Array, Size, Find);
	if(FoundPosition >= 0)
	{
		printf("Target %d found at index %d.\n", Array[FoundPosition], FoundPosition);
	}
	else
	{
		printf("Target %d not found.\n", Find);
	}

	free(Array);
	return FoundPosition;
}

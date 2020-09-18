/*
This program was written for CSC 382 Algorithms class at College of Staten Island (CUNY)

The program implements Insertion Sort and Merge Sort Algorithms and checks their efficiency for arrays of size N = 100, 200, 300, 400, 500, 1000, 4000, 10000
for the following test cases:
	- Sorted Array
	- Reversed Array
	- Random Permunation of 1 to N Array
	- 50 Random Instances of 1 to N (calculates average)

Efficiency is measured by execution time and the number of steps it took to sort the array
User see the results of the sorting in a table format


Author: Konstantin Novichenko
*/


#include <iostream>
#include <chrono>
#include <time.h>
#include <stdlib.h>
#include <iomanip>

using std::cout;

// Function prototypes
void insertionSort(int A[], int n, int& counter);
void sortArraysOfSizeN(int n);
void mergeSort(int A[], int begin, int end, int& counter);
void merge(int A[], int begin, int mid, int end, int& counter);
void printArray(int A[], int n);

// Main function
int main() 
{
	srand(clock()); // set seed

	// Call sorting for N = 100, 200, 300, 400, 500, 1000, 4000, 10000
	sortArraysOfSizeN(100);
	sortArraysOfSizeN(200);
	sortArraysOfSizeN(300);
	sortArraysOfSizeN(400);
	sortArraysOfSizeN(500);
	sortArraysOfSizeN(1000);
	sortArraysOfSizeN(4000);
	sortArraysOfSizeN(10000);	

	system("pause");
	return 0;
}

// Function that processes sorting for arrays of size N
// Generates pairs of identical arrays which are being used in insertion sort and merge sort
// Types of pairs: Sorted, Reversed, Random Permunation of N, 50 Random Instances of 1 to N
void sortArraysOfSizeN(int n) 
{
	// Initialize dynamic arrays of size N
	int* alreadySortedArray1 = new int[n];
	int* alreadySortedArray2 = new int[n];
	int* reversedArray1 = new int[n];
	int* reversedArray2 = new int[n];
	int* randomArray1 = new int[n];
	int* randomArray2 = new int[n];

	// Inititalize time points
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	// Initialize step counter
	int counter = 0;

	// Initialize average step and time counters (used for 50 random arrays)
	long long averageTime1 = 0;
	long long averageSteps1 = 0;
	long long averageTime2 = 0;
	long long averageSteps2 = 0;

	// Loops that generates Sorted, Reversed, Random Permunation of N arrays
	for (int i = 0; i < n; i++)
	{
		// Sorted
		alreadySortedArray1[i] = i + 1;
		alreadySortedArray2[i] = i + 1;

		// Reversed
		reversedArray1[i] = n - i;
		reversedArray2[i] = n - i;

		bool uniqueRandomNumber = false; // Used to check if the number is unique and should be included in array
		int randNum = 0; // Temp value of the currebt random number

		while (!uniqueRandomNumber) // Run until unique number is found
		{
			randNum = rand() % n + 1; // Get Random number
			uniqueRandomNumber = true;
			if (i != 0) // First number is unique, so skip the check
			{
				for (int j = 0; j < i; j++)
				{
					if (randNum == randomArray1[j] || randNum == randomArray2[j]) // If found, that means that number is not unique
					{
						uniqueRandomNumber = false; 
					}
				}
			}
		}

		// Random permutations
		randomArray1[i] = randNum;
		randomArray2[i] = randNum;
	}

	// ***************************************Sorted Array***********************************************

	cout << std::setfill('-') << std::setw(100) << "-"  << std::setfill(' ') << std::endl; // Formating lines	
	
	start = std::chrono::steady_clock::now(); // Set timer
	insertionSort(alreadySortedArray1, n, counter); // Insertion Sort
	end = std::chrono::steady_clock::now();	// Stop timer

	// Output
	cout << "\nSORTED SEQUENCE ARRAY (N = " << n << ")\n\n";
	cout << std::setw(30) << "INSERTION SORT " << std::setw(19) << "|"<< std::setw(34) << "MERGE SORT" << "\n";

	cout << "Number of operations" << "\tExecution Time (ns)\t|" << "\tNumber of operations" << "\tExecution Time (ns) " << "\n";

	cout << std::setw(20) << counter;
	cout << " " << std::setw(22) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\t|\t";
	
	// Reset steps counter
	counter = 0;	

	start = std::chrono::steady_clock::now(); // Set timer
	mergeSort(alreadySortedArray2, 0, n - 1, counter); // Merge Sort
	end = std::chrono::steady_clock::now(); // Stop timer

	// Output 
	cout << std::setw(20) << counter;
	cout << " " << std::setw(22) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\n";
	
	// Reset steps counter
	counter = 0;

	// ***************************************Reversed Array***********************************************

	start = std::chrono::steady_clock::now(); // Set timer
	insertionSort(reversedArray1, n, counter); // Insertion Sort
	end = std::chrono::steady_clock::now(); // Stop timer

	// Output
	cout << "\n\nREVERSED SEQUENCE ARRAY (N = " << n << ")\n\n";
	cout << std::setw(30) << "INSERTION SORT " << std::setw(19) << "|" << std::setw(34) << "MERGE SORT" << "\n";

	cout << "Number of operations" << "\tExecution Time (ns)\t|" << "\tNumber of operations" << "\tExecution Time (ns) " << "\n";

	cout << std::setw(20) << counter;
	cout << " " << std::setw(22) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\t|\t";

	// Reset steps counter
	counter = 0;

	start = std::chrono::steady_clock::now(); // Set timer
	mergeSort(reversedArray2, 0, n - 1, counter); // Merge Sort
	end = std::chrono::steady_clock::now(); // Stop timer

	// Output 
	cout << std::setw(20) << counter;
	cout << " " << std::setw(22) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\n";

	// Reset steps counter
	counter = 0;

	// ***************************************Random Permutations Array***********************************************

	start = std::chrono::steady_clock::now(); // Set timer
	insertionSort(randomArray1, n, counter); // Insertion Sort
	end = std::chrono::steady_clock::now(); // Stop timer

	// Output
	cout << "\n\nRANDOM ITERATIONS SEQUENCE ARRAY (N = " << n << ")\n\n";
	cout << std::setw(30) << "INSERTION SORT " << std::setw(19) << "|" << std::setw(34) << "MERGE SORT" << "\n";

	cout << "Number of operations" << "\tExecution Time (ns)\t|" << "\tNumber of operations" << "\tExecution Time (ns) " << "\n";

	cout << std::setw(20) << counter;
	cout << " " << std::setw(22) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\t|\t";

	// Reset steps counter
	counter = 0;

	start = std::chrono::steady_clock::now(); // Set timer
	mergeSort(randomArray2, 0, n - 1, counter); // Merge Sort
	end = std::chrono::steady_clock::now(); // Stop timer

	// Output 
	cout << std::setw(20) << counter;
	cout << " " << std::setw(22) << std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() << "\n";

	// Reset steps counter
	counter = 0;

	// ***************************************50 Random Instances***********************************************

	for (int i = 0; i < 50; i++) // 50 pairs of random arrays
	{
		for (int j = 0; j < n; j++) // Populate the current pair with random numbers in range from 1 to N
		{
			int randomNumberTemp = rand() % n + 1;
			randomArray1[j] = randomNumberTemp;
			randomArray2[j] = randomNumberTemp;
		}		

		start = std::chrono::steady_clock::now(); // Set timer
		insertionSort(randomArray1, n, counter); // Insertion Sort
		end = std::chrono::steady_clock::now(); // Stop timer

		// Increment the average values of time and steps for insertion sort, then reset step counter
		averageTime1 += (long long)(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
		averageSteps1 += (long long)counter;
		counter = 0;

		start = std::chrono::steady_clock::now(); // Set timer
		mergeSort(randomArray2, 0, n - 1, counter); // Merge Sort
		end = std::chrono::steady_clock::now(); // Stop timer

		// Increment the average values of time and steps for merge sort, then reset step counter
		averageTime2 += (long long)(std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count());
		averageSteps2 += (long long)counter;
		counter = 0;			
	}

	// Output 
	cout << "\n\nAVERAGE OF 50 ARRAYS OF RANDOM NUMBERS (N = " << n << ")\n\n";
	cout << std::setw(30) << "INSERTION SORT " << std::setw(19) << "|" << std::setw(34) << "MERGE SORT" << "\n";

	cout << "Number of operations" << "\tExecution Time (ns)\t|" << "\tNumber of operations" << "\tExecution Time (ns) " << "\n";

	cout << std::setw(20) << averageSteps1/50;
	cout << " " << std::setw(22) << averageTime1/50 << "\t|\t";
	cout << std::setw(20) << averageSteps2 / 50;
	cout << " " << std::setw(22) << averageTime2 / 50 << "\n\n";

	cout << std::setfill('-') << std::setw(100) << "-" << std::setfill(' ') << std::endl; // Formating lines	

	// Release data from the main memory
	delete[] reversedArray1;
	delete[] alreadySortedArray1;
	delete[] randomArray1;
	delete[] reversedArray2;
	delete[] alreadySortedArray2;
	delete[] randomArray2;
	alreadySortedArray1 = nullptr;
	reversedArray1 = nullptr;
	randomArray1 = nullptr;
	alreadySortedArray2 = nullptr;
	reversedArray2 = nullptr;
	randomArray2 = nullptr;
}

// Print the content of the array (Used for testing purposes; currently deprecated)
void printArray(int A[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
	cout << "\n";
}

// Performs the insertion sort algorithm
void insertionSort(int A[], int n, int& counter) {
	
	counter ++;	// count int i = 1
	for (int i = 1; i < n; i++) 
	{
		int key = A[i];
		int j = i - 1;
		
		while (j >= 0 && key < A[j])
		{
			A[j + 1] = A[j];
			j--;
			counter += 4; // count j >= 0, key < A[j], A[j + 1] = A[j], j--;
		}

		A[j + 1] = key;
		counter += 7; // count i < n, int key = A[i], int j = i - 1, j >= 0, key < A[j], A[j + 1] = key, i++
	}	
	counter++; // count last i < n
}

// Performs the Merge sort algorithm
void mergeSort(int A[], int begin, int end, int& counter)
{	
	if (begin < end)
	{
		int mid = (begin + end) / 2; // find the middle index
		mergeSort(A, begin, mid, counter); // merge sort on the left side
		mergeSort(A, mid + 1, end, counter); // merge sort on the right side
		merge(A, begin, mid, end, counter); // merge back
		counter += 4; // count (begin + end) / 2, mergeSort(A, begin, mid, counter), mergeSort(A, mid + 1, end, counter), merge(A, begin, mid, end, counter)

	}
	counter++; // count begin < end
}

// Performs merging parts back
void merge(int A[], int begin, int mid, int end, int& counter)
{
	// Initialize indices of divided sides
	int leftBound = mid - begin + 1;
	int rightBound = end - mid;

	// Inititalize temp arrays for left side and right side of division
	int* leftSide = new int[leftBound];
	int* rightSide = new int [rightBound];

	counter += 5; // count initialization and int i = 0

	// Copy data to temp arrays leftSide and rightSide
	for (int i = 0; i < leftBound; i++)
	{
		leftSide[i] = A[begin + i];
		counter += 3; // count  i < leftBound, leftSide[i] = A[begin + i], i++
	}

	counter += 2; // count last i < leftBound and int i = 0 for the new loop
		
	for (int i = 0; i < rightBound; i++)
	{
		rightSide[i] = A[mid + 1 + i];
		counter += 3; // count i < rightBound, rightSide[i] = A[mid + 1 + i], i++
	}
		
	counter++; // count last i++

	// Initialize values used for merge the temp arrays back
	int i = 0; // Initial index of first subarray 
	int j = 0; // Initial index of second subarray 
	int k = begin; // Initial index of merged subarray 

	counter += 5; // count initilization of i, j, k and i < leftBound, j < rightBound
	
	while (i < leftBound && j < rightBound) 
	{
		if (leftSide[i] <= rightSide[j]) 
		{
			A[k] = leftSide[i];
			i++;
			counter += 2; // count A[k] = leftSide[i] and i++;
		}
		else 
		{
			A[k] = rightSide[j];
			j++;
			counter += 2; // count A[k] = rightSide[j] and j++;
		}
		k++;
		counter += 4; // count 'if' statement condition, k++, i < leftBound, j < rightBound
	}

	// Copy the remaining elements of leftSide array

	counter++; //count i < leftBound

	while (i < leftBound) 
	{
		A[k] = leftSide[i];
		i++;
		k++;
		counter += 4; // count A[k] = leftSide[i], i++, k++, i < leftBound
	}

	// Copy the remaining elements of rightSide array

	counter++; // count j < rightBound

	while (j < rightBound) 
	{
		A[k] = rightSide[j];
		j++;
		k++;
		counter += 4; // count A[k] = rightSide[j], j++, k++, i < rightBound
	}

	// Release data from the main memory
	delete[] leftSide;
	delete[] rightSide;
	leftSide = nullptr;
	rightSide = nullptr;

	counter += 4; // count the release of data
}

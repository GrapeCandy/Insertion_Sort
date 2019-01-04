#include <iostream>
#include <time.h>
#include <chrono>
#define size_of_array 5										//Size of array

using namespace std;

void insertion_sort(int arr[]);									//Insertion sort function
void Make_aver(int arr[], int arr1[]);							//Make average case array
void Make_worst(int arr[], int arr2[]);							//Make worst case array

void main(void)
{						
	int arr[size_of_array] = { 0, };							//Array that store Original array (Best case)
	int arr1[size_of_array] = { 0, };							//Array that store Average case array
	int arr2[size_of_array] = { 0, };							//Array that store worst case array


	for (int a = 1; a <= size_of_array; a++) { arr[a - 1] = a; }		//Input number into array in order

	Make_aver(arr, arr1);										//Call Make_aver function
	Make_worst(arr, arr2);										//Call Make_worst function

	/*Print original array*/
	cout << "--Original array_Best--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr[a] << " ";									//Print best case array
	}
	cout << endl << endl;										//Change line two times

	cout << "--Original array_Average--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr1[a] << " ";									//Print array
	}
	cout << endl << endl;										//Change line two times

	cout << "--Original array_Worst--\n";
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr2[a] << " ";									//Print array
	}
	cout << endl << endl;										//Change line two times

	cout << "--Simulation_Best--\n";
	clock_t start = clock();									//Check start time in sec
	auto st = chrono::high_resolution_clock::now();				//check start time in ns
	insertion_sort(arr);										//Call insertion sort
	clock_t end = clock();										//Check end time in sec
	auto et = chrono::high_resolution_clock::now();				//Check end time in ns
	cout << "\nRunning time of Insertion Sort: " << (double)(end - start) / CLOCKS_PER_SEC << " sec" << endl;										//Print sorting time in sec
	cout << "Running time of Insertion Sort(ns): " << chrono::duration_cast<chrono::nanoseconds>(et - st).count() << " ns" << endl << endl;			//Print sorting time in ns	
	cout << endl;

	cout << "--Simulation_Average--\n";
	clock_t startt = clock();									//Check start time in sec
	auto stt = chrono::high_resolution_clock::now();			//check start time in ns
	insertion_sort(arr1);										//Call insertion sort
	clock_t endd = clock();										//Check end time in sec
	auto ett = chrono::high_resolution_clock::now();			//Check end time in ns
	cout << "\nRunning time of Insertion Sort: " << (double)(endd - startt) / CLOCKS_PER_SEC << " sec" << endl;										//Print sorting time in sec
	cout << "Running time of Insertion Sort(ns): " << chrono::duration_cast<chrono::nanoseconds>(ett - stt).count() << " ns" << endl << endl;		//Print sorting time in ns	
	cout << endl;

	cout << "--Simulation_Worst--\n";
	clock_t starttt = clock();									//Check start time in sec
	auto sts = chrono::high_resolution_clock::now();			//check start time in ns
	insertion_sort(arr2);										//Call insertion sort
	clock_t enddd = clock();									//Check end time in sec
	auto ete = chrono::high_resolution_clock::now();			//Check end time in ns
	cout << "\nRunning time of Insertion Sort: " << (double)(enddd - starttt) / CLOCKS_PER_SEC << " sec" << endl;										//Print sorting time in sec
	cout << "Running time of Insertion Sort(ns): " << chrono::duration_cast<chrono::nanoseconds>(ete - sts).count() << " ns" << endl << endl;			//Print sorting time in ns	
	cout << endl;

	/*Print Sorted array*/
	cout << "--Sorted array--\n";
	for (int a = 0; a < size_of_array; a++)							//While reach to end of array
	{
		cout << arr[a] << " ";										//Print array
	}
	cout << endl;													//Change  line
}


/*Best, Average, Worst case의 시간을 정확히 관찰하기 위해서는 cout 부분을 주석처리 해야함*/
void insertion_sort(int arr[])
{
	for (int a = 0; a < size_of_array; a++)						//While reach to end of array
	{
		cout << arr[a] << " ";									//Print array
	}
	cout << endl;

	for (int i = 1; i < size_of_array; i++)							//Comparing starts in the second value and ends just before the end of the array.
	{
		int k = arr[i];												//'k' is array's current value
		int before = i - 1;											//'before' is previous index of array

		while (before >= 0 && k < arr[before])						//Until previous index is bigger than 0 and current value is smaller than prevoius value
		{
			swap(arr[before], arr[before + 1]);						//Change between previous value and preprevious value
			before--;												//Move previous pointer to lower index

			for (int g = 0; g < size_of_array; g++)					//While reach to end of array
			{
				cout << arr[g] << " ";								//Print simulation
			}
			cout << endl;											//Change line
		}
	}
}

void Make_aver(int arr[], int arr1[])
{
	int arr_tmp[size_of_array] = { 0, };							//Array that store tempolary value
	int add = 0;													//start of original array
	int sub = size_of_array - 1;									//End of original array

	for (int g = (size_of_array / 2); g >= 0; g--)					//Begin the middle of array and End to first of array
	{
		arr_tmp[g] = arr[add];										//g'th arr_tmp value is equal to arr's add'th number
		add++;														//Move to next index
	}
	for (int r = (size_of_array / 2) + 1; r < size_of_array; r++)	//Begin the next of middle and End to end of array
	{
		arr_tmp[r] = arr[sub];										//arr_tmp's r'th value is equal to arr's sub'th value
		sub--;
	}
	for (int e = 0; e < size_of_array; e++)							//while reach to end of array
	{
		arr1[e] = arr_tmp[e];										//Copy arr_tmp's value to arr1 array
	}
}

void Make_worst(int arr[], int arr2[])
{
	int tmp_arr[size_of_array] = { 0, };							//Array that store temporal
	int subs = size_of_array - 1;									//End of array index

	for (int i = 0; i < size_of_array; i++)							//While reach to end of array
	{
		tmp_arr[i] = arr[subs];										//tmp_arr's i'th value is arr's subs'th value
		subs--;														//Move array pointer to front
	}

	for (int s = 0; s < size_of_array; s++)							//While reach to end of array
	{
		arr2[s] = tmp_arr[s];										//Copy tmp_arr's value to arr2
	}
}


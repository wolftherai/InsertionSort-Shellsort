#include <fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <algorithm>
#include <chrono> 
#include <iostream>

using namespace std;
using namespace std::chrono;

void InsertionSort(int length, int*& A, long long& steps)
{
	int j;
	for (int i = 1; i < length; i++) { // we are taking one item(number) at a time
		j = i;
		while (j > 0 && A[j - 1] > A[j]) // if while loop works, array values will be changed
		{
			swap(A[j], A[j - 1]);
			j -= 1; // decrease value for iterating items in while loop
			steps++;
		}
	}
}
/*
In ShellSort we are working with array's length.
Starting length is half array's size. After we finish work in this distance,
we divide by 2 again.
Repeat until length == 1 & weren't any swaps left
*/
void ShellSort(int length, int*& A, long long& steps)
{
	int j;
	for (int gap = length / 2; gap > 0; gap /= 2) // repeating until gap is not less than 1
	{
		for (int i = gap; i < length; i++)
		{
			for (j = i; j >= gap && A[j - gap] > A[j]; j -= gap)
			{
				swap(A[j], A[j - gap]); steps++;
			}

		}
	}
}
void ReadArray(int& size, int*& A)
{
	cout << "\nInput size of an array: ";
	cin >> size;
	A = new int[size];
	cout << "Insert elements of an array: ";

	for (int i = 0; i < size; i++)
		cin >> A[i]; // Values are saved to array
}
void PrintArray(int length, int*& A)
{
	cout << "\nArray:\n";
	for (int i = 0; i < length; i++)
		cout << A[i] << " ";
}
void shell_sort_time(int length, int*& A, double& time_ms, long long& steps)
{
	auto start = high_resolution_clock::now();
	// Call the function, here sort() 
	ShellSort(length, A, steps);
	// Get ending timepoint 
	auto stop = high_resolution_clock::now();
	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "Time taken by function: "
	//<< duration.count() << " microseconds | " << duration.count() / 1000000. << " seconds " << endl;
	time_ms = duration.count() / 1000000.;
}
void insert_sort_time(int length, int*& A, double& time_ms, long long& steps)
{
	auto start = high_resolution_clock::now();
	// Call the function, here sort() 
	InsertionSort(length, A, steps);
	// Get ending timepoint 
	auto stop = high_resolution_clock::now();
	// Get duration. Substart timepoints to  
	// get durarion. To cast it to proper unit 
	// use duration cast method 
	auto duration = duration_cast<microseconds>(stop - start);
	//cout << "Time taken by function: "
	//<< duration.count() << " microseconds | " << duration.count() / 1000000. << " seconds " << endl;
	time_ms = duration.count() / 1000000.;
}
//-------------------------------------------------------------------------------------
void insert_test_data(int size, int*& numbers) {
	int number;
	ofstream fr("test_data.txt");
	/* initialize random seed: */
	srand((unsigned int)time(NULL));
	numbers = new int[size];
	/* generate secret number between 1 and 10: */
	for (int i = 0; i < size; i++)
	{
		number = rand() % size + 1;
		fr << number << " "; // prints to test_data.txt
		numbers[i] = number; // saves random number in the array
	}
}
void sort_analysis(int begin, int end, int test_times)
{
	double sh_max = 0, sh_min = 999999, sh_avg = 0;
	double in_max = 0, in_min = 999999, in_avg = 0;
	int size = begin;
	double sh_time = 0, in_time = 0;


	for (int j = size; j <= end; j += ((end - size) / 10))
	{
		double sh_max = 0, sh_min = 999999, sh_avg = 0;
		double in_max = 0, in_min = 999999, in_avg = 0;
		long long sh_steps = 0, in_steps = 0,avg_sh_steps=0,avg_in_steps=0;
		int* in_elem = new int[j];//for insert sorting elem
		int* sh_elem = new int[j];//for shell sorting elem
		for (int i = 0; i < test_times; i++)
		{
			sh_steps = 0, in_steps = 0;
			insert_test_data(j, in_elem);
			insert_test_data(j, sh_elem);
			shell_sort_time(j, sh_elem, sh_time, sh_steps);//return shell sort time,steps
			insert_sort_time(j, in_elem, in_time, in_steps);//return nsertion sort time,steps
			cout << j << " size  : test times: " << i << " shell time: " << sh_time << " steps: " << sh_steps << "  |||||  insertion sort time: " << in_time << " steps: " << in_steps << endl;
			avg_in_steps += in_steps;
			avg_sh_steps += sh_steps;
			if (sh_max < sh_time)
			{
				sh_max = sh_time;
			}
			if (sh_min > sh_time)
			{
				sh_min = sh_time;
			}
			//---------------------
			if (in_max < in_time)
			{
				in_max = in_time;
			}
			if (in_min > in_time)
			{
				in_min = in_time;
			}
			in_avg += in_time;
			sh_avg += sh_time;
		}
		in_avg /= test_times;
		sh_avg /= test_times;
		
		//find min,max and average times
		cout << "---------------------------------------------------------------\n";
		cout << "shell     MAX= " << sh_max << " :: shell      MIN= " << sh_min << "  AVERAGE TIME: " << sh_avg << "avg steps: " << avg_sh_steps/(test_times*1.0) << endl;
		cout << "insertion MAX= " << in_max << " :: insertion  MIN= " << in_min << "  AVERAGE TIME: " << in_avg << "avg steps: " << avg_in_steps / (test_times * 1.0) << endl;
		cout << "efectivness insertion steps/sec : " << avg_sh_steps / (test_times * 1.0) / sh_avg << endl;
		cout << "efectivness shell     steps/sec : " << avg_in_steps / (test_times * 1.0) / in_avg << endl;
		// cout<<"efectivness steps shell/steps insert : "<<double(sh_steps)/(sh_steps*1.);
		// cout<<"efectivness steps insertion/steps insert : "<<double(in_steps)/(in_steps*1.);
		cout << "---------------------------------------------------------------\n";
		delete[] in_elem, sh_elem;

	}

	// Deallocates the memory block
}
int main()
{
	int size = 0, start, end, test_times; long long steps = 0;
	int option = 0, choice = 0; // n - array size, choice is for choosing Insertion Sort or ShellSort algortihms
	int* numbers = new int[size]; // Dynamic array size changed in ReadArray() function
	double time = 0;
	cout << "Insert the range of data in array you want to analize:" << endl;
	cout << "Range start: "; cin >> start;
	cout << "Range end (> start) :"; cin >> end;
	cout << "Now how precise you want to analize? Input how many times you want to test values in range: "; cin >> test_times;
	sort_analysis(start, end, test_times);
	cout << "### Insertion Sort & ShellSort ###\n\n#1. Generate random data \n#2. Insert by hand \n";
	while (true)
	{
		cin >> option;

		if (option == 1) {
			cout << "\nEnter the size of an array: ";
			cin >> size;
			insert_test_data(size, numbers);
			cout << "\nRandom data generated succesfully!!!\nYou can find it in test_data.txt\n";

			break;
		}
		else if (option == 2) {
			ReadArray(size, numbers);
			cout << "\nElments inserted succesfully!!!" << endl;
			break;
		}
		else
			cout << "Wrong! Try again.\n";
	}



	//---------------------------
	cout << "\n#1. Insertion Sort\n#2. ShellSort\n";
	while (true)
	{
		cin >> choice;

		if (choice == 1) {
			insert_sort_time(size, numbers, time, steps);
			cout << "Time taken by function insert_sort_time: "
				<< time << " microseconds | " << time << " seconds " << endl;

			break;
		}
		else if (choice == 2) {
			shell_sort_time(size, numbers, time, steps);
			cout << "Time taken by function: "
				<< time << " microseconds | " << time << " seconds " << endl;

			break;
		}
		else
			cout << "Wrong! Try again.\n";
	}

	cout << "Do you want to print sorted data?\n\n#1 YES\n#2 NO\n";
	while (true) {
		cin >> choice;
		if (choice == 1)
		{
			PrintArray(size, numbers);
			break;
		}
		else if (choice == 2)
		{
			cout << "Out of options\n";
			break;
		}
		else {
			cout << "Wrong number\n";
		}
	}

	delete[] numbers; // Deallocates the memory block

	return 0;
}

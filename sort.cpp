#include<fstream>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
#include <algorithm>
#include <chrono> 
#include <iostream>
using namespace std;
using namespace std::chrono; 
void InsertionSort(int length, int *&A)
{
  int j;
  for (int i = 1; i < length; i++) { // we are taking one item(number) at a time
    j = i;
    while (j > 0 && A[j - 1] > A[j]) // if while loop works, array values will be changed
    {
      swap(A[j], A[j - 1]);
      j -= 1; // decrease value for iterating items in while loop
    }
  }
}
/*
In ShellSort we are working with array's length.
Starting length is half array's size. After we finish work in this distance,
we divide by 2 again.
Repeat until length == 1 & weren't any swaps left
*/
void ShellSort(int length, int *&A)
{
  int j;
  for (int gap = length / 2; gap > 0; gap /= 2) // repeating until gap is not less than 1
  {
    for (int i = gap; i < length; i++)
    {
      for (j = i; j >= gap && A[j - gap] > A[j]; j -= gap)
        swap(A[j], A[j - gap]);
    }
  }
}
void ReadArray(int &size, int *&A)
{
  cout << "### Insertion Sort & ShellSort ###\nInput size of an array: ";
  cin >> size;
  A = new int[size];
  cout << "Insert elements of an array: ";

  for (int i = 0; i < size; i++)
    cin >> A[i]; // Values are saved to array
}
void PrintArray(int length, int *&A)
{
	cout << "\nArray:\n";
	for (int i = 0; i < length; i++)
    	cout << A[i] << " ";
}
//-------------------------------------------------------------------------------------
void insert_test_data(int size,int *&numbers){
    int number;
  ofstream fr("test_data.txt");
/* initialize random seed: */
  srand (time(NULL));
  numbers = new int[size];
  /* generate secret number between 1 and 10: */
  for(int i=0;i<size;i++)
  {
    number = rand() % size + 1;
    fr<<number<<" ";//prints to test_data.txt
    numbers[i]=number; //saves random number in the array
  }
  }
int main ()
{
  int size;
int option=0,choice = 0; // n - array size, choice is for choosing Insertion Sort or ShellSort algortihms
  int * numbers = new int[size]; // Dynamic array size changed in ReadArray() function

  cout << "\n#1. Generate random data \n#2. Insert by hand \n";
    while(option != 1 || option!= 2)
  {
  	cin >>option;

  	if (option== 1) {
      cout<<"### Insertion Sort & ShellSort ###\nEnter the size of an array: ";
      cin>>size;
  		insert_test_data(size,numbers);
      cout<<"\nRandom data generated succesfully!!!\nYou can find it in test_data.txt\n";
      
  		break;
  	}
  	else if (option == 2) {
      ReadArray(size, numbers);
      cout<<"\nElments inserted succesfully!!!"<<endl;
  		break;
  	}
  	else
  		cout << "Wrong! Try again.\n";
  }



//---------------------------
  cout << "\n#1. Insertion Sort\n#2. ShellSort\n";
  while(choice != 1 || choice != 2)
  {
  	cin >> choice;

  	if (choice == 1) {
        auto start = high_resolution_clock::now(); 
    // Call the function, here sort() 
  		InsertionSort(size, numbers);
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
  
  		break;
  	}
  	else if (choice == 2) {
              auto start = high_resolution_clock::now(); 
    // Call the function, here sort() 
  		ShellSort(size, numbers);
    // Get ending timepoint 
    auto stop = high_resolution_clock::now(); 
    // Get duration. Substart timepoints to  
    // get durarion. To cast it to proper unit 
    // use duration cast method 
    auto duration = duration_cast<microseconds>(stop - start); 
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl; 
  		
  		break;
  	}
  	else
  		cout << "Wrong! Try again.\n";
  }
  cout<<"Do you want to print sorted data?\n";
  cout<<"\n#1 YES\n";
  cout<<"\n#2 NO\n";
  cin>>choice;
if(choice != 1 || choice != 2)
  {

  	if (choice == 1) {
  		  PrintArray(size, numbers);
  	}
  	else {
  		cout<<"Out of options";
    }
  }
  delete [] numbers; // Deallocates the memory block



  return 0;
}

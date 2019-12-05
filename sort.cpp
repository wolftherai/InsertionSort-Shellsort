#include <iostream>
#include <algorithm> // for swap function

using namespace std;

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
void ShellSort(int length, int *&A)
{

}
void ReadArray(int &size, int *&A)
{
  cout << "### Insertion Sort & ShellSort ###\nInput size of an array: ";
  cin >> size;
  A = new int[size];
  cout << "Input elements of an array: ";

  for (int i = 0; i < size; i++)
    cin >> A[i]; // Values are saved to array
}
void PrintArray(int length, int *&A)
{
	cout << "\nSorted Array:\n";
	for (int i = 0; i < length; i++)
    	cout << A[i] << " ";
}
int main() {
  int n = 0, choice = 0; // n - array size, choice is for choosing Insertion Sort or ShellSort algortihms
  int * numbers = new int[n]; // Dynamic array size changed in ReadArray() function

  ReadArray(n, numbers);
  cout << "#1. Insertion Sort\n#2. ShellSort\n";
  while(choice != 1 || choice != 2)
  {
  	cin >> choice;

  	if (choice == 1) {
  		InsertionSort(n, numbers);
  		break;
  	}
  	else if (choice == 2) {
  		ShellSort(n, numbers);
  		break;
  	}
  	else
  		cout << "Wrong! Try again.\n";
  }
  PrintArray(n, numbers);

  delete [] numbers; // Deallocates the memory block
}

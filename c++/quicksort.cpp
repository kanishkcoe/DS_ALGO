#include <iostream>

using namespace std;


void printArray(int *array, int size)
{
  for(int i = 0; i < size; i++)
  {
    cout << array[i] << ", ";
  }

  cout << "!!!" << endl;
}


void quickSort(int *array, int start, int end);
int partition(int *array, int start, int end);
void swap(int &a, int &b)
{
  int temp;
  temp = a;
  a = b;
  b = temp;
}


int main()
{
  int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};

  printArray(array, 9);

  quickSort(array, 0, 8);

  printArray(array, 9);

  return 0;
}


void quickSort(int *array, int start, int end)
{
  if(start < end)
  {
    int partition_index = partition(array, start, end);
    quickSort(array, start, partition_index - 1);
    quickSort(array, partition_index + 1, end);
  }
}


int partition(int *array, int start, int end)
{
  int pivot = end;

  int i = start;
  int j = start;

  for(j = start; j < end; j++)
  {
    if(array[j] <= array[pivot])
    {
      swap(array[i], array[j]);
      i++;
    }
  }
  swap(array[i], array[pivot]);
  return i;
}

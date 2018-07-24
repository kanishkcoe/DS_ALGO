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


void merge(int *array, int start, int mid, int end)
{
  //temporary arrays
  int n1 = mid - start + 1;
  int n2 = end - mid;
  int *L = new int[n1];
  int *R = new int[n2];

  for(int iter = 0; iter < n1; iter++)
  {
    L[iter] = array[start + iter];
  }

  for(int iter = 0; iter < n2; iter++)
  {
    R[iter] = array[mid + iter + 1];
  }

  printArray(L, mid - start + 1);
  printArray(R, end - mid);
  int i = 0;
  int j = 0;
  int k = start;

  while(i < n1 && j < n2)
  {
    if(L[i] <= R[j])
    {
      array[k] = L[i];
      i++;
    }
    else
    {
      array[k] = R[j];
      j++;
    }
    k++;
  }

  while(i < n1)
  {
    array[k] = L[i];
    i++;
    k++;
  }

  while(j < n2)
  {
    array[k] = R[j];
    j++;
    k++;
  }
}


void mergeSort(int *array, int low, int high)
{
  int mid;

  if(low < high)
  {
    mid = (low + high) / 2;

    mergeSort(array, low, mid);
    mergeSort(array, mid+1, high);
    merge(array, low, mid, high);
  }
}


int main()
{
  int array[] = {5, 4, 8, 9, 6, 4, 7, 5, 1, 3, 5, 4, 2};
  int size = sizeof(array) / sizeof(array[0]);
  cout << size << endl;
  int a[] = {1, 3, 5, 7, 9, 2, 4, 6, 8};

  printArray(array, size);

  mergeSort(array, 0, size - 1);

  printArray(array, size);

  merge(a, 0, 4, 8);

  printArray(a, 9);

  return 0;
}

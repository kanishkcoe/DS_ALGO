#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int numbers[] {46, 5, 8, 76, 5, 1, 36, 75, 4};
  for(int number : numbers)
  {
    cout << number << endl;
  }
  return 0;
}

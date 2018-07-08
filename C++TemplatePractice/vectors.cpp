#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<int> vector1;
  vector<int> vector2;

  int temporary_holder;

  cin >> temporary_holder;
  vector1.push_back(temporary_holder);
  cin>> temporary_holder;
  vector1.push_back(temporary_holder);

  cout << "Elements in the first vector are : " << endl;
  cout << vector1.at(0) << endl;
  cout << vector1.at(1) << endl;
  cout << "Size of the vector is : " << vector1.size() << endl;

  cin >> temporary_holder;
  vector2.push_back(temporary_holder);
  cin>> temporary_holder;
  vector2.push_back(temporary_holder);

  cout << "Elements in the second vector are : " << endl;
  cout << vector2.at(0) << endl;
  cout << vector2.at(1) << endl;
  cout << "Size of the vector is : " << vector1.size() << endl;

  vector< vector<int> > vector_2d;

  vector_2d.push_back(vector1);
  vector_2d.push_back(vector2);

  cout << "Elements in the 2d vector are : " << endl;
  cout << vector_2d.at(0).at(0) << '\t';
  cout << vector_2d.at(0).at(1) << endl;
  cout << vector_2d.at(1).at(0) << '\t';
  cout << vector_2d.at(1).at(1) << endl;
  cout << "Size of the vector is : " << vector_2d.size() << endl;

  vector1.at(0) = 1000;
  cout << "Elements in the 2d vector are : " << endl;
  cout << vector_2d.at(0).at(0) << '\t';
  cout << vector_2d.at(0).at(1) << endl;
  cout << vector_2d.at(1).at(0) << '\t';
  cout << vector_2d.at(1).at(1) << endl;

  cout << "Elements in the first vector are : " << endl;
  cout << vector1.at(0) << endl;
  cout << vector1.at(1) << endl;
  return 0;
}

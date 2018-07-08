#include <iostream>
#include <vector>
#include <math.h>

using namespace std;


long phi(long num)
{
  vector<long> factors;
  long i = 2;
  long temp = num;

  while(temp != 1)
  {
    if(temp % i == 0)
    {
      temp /= i;
      factors.push_back(i);
    }
    else
    {
      i++;
    }
  }

  float value = num;
  for(int j = 0; j < factors.size(); j++)
  {
    if(j < factors.size() - 1)
    {
      if(factors.at(j) != factors.at(j + 1))
      {
        value = (value * factors.at(j) - value) / factors.at(j);
      }
    }
    else if(j == factors.size() - 1)
    {
      value = (value * factors.at(j) - value) / factors.at(j);
    }
  }
  return value;
}


long totient(long number)
{
  vector<long> chain;
  if(number > 1)
    chain.push_back(number);
  long p;
  while(phi(number) != 1)
  {
    p = phi(number);
    chain.push_back(p);
    number = p;
  }
  chain.push_back(1);
  return chain.size();
}


bool isPrime(long num)
{
  for(int i = 2; i <= num / 2; i++)
  {
    if(num % i == 0)
      return false;
  }
  return true;
}


bool inList(vector <long> divisor, long number)
{
  for(int i = 0; i < divisor.size(); i++)
  {
    if(divisor.at(i) == number)
    {
      return true;
    }
  }
  return false;
}

bool factor(long number, vector<long> divisor, long exponent)
{
  if(number == 1)
    return true;

  long temp = number;
  long i = 2;
  long max_exponent = 0;
  while(temp != 1)
  {
    if(temp % i == 0 && (max_exponent <= exponent) && inList(divisor, i))
    {
      temp /= i;
      max_exponent++;
      if(max_exponent > exponent)
      {
        return false;
      }
    }
    else if(temp % i == 0 && !inList(divisor, i))
    {
      return false;
    }
    else
    {
      max_exponent = 0;
      i++;
    }
  }
  return true;
}


void formSet(int n, int a, int number_of_k)
{
  vector<long> p;

  long num = 2;
  while(p.size() != n)
  {
    if(isPrime(num))
    {
      p.push_back(num);
    }
    num++;
  }

  vector<long> set;

  long max = 1;

  for(int i = 0; i < n; i++)
  {
    max *= pow(p.at(i), a);
  }

  for(int i = 1; i <= max; i++)
  {
    if(factor(i, p, a))
    {
      set.push_back(i);
    }
  }

  for(int i = 0; i < set.size(); i++)
  {
    set.at(i) = totient(set.at(i));
  }

  long k;
  long count = 0;
  for(int i = 0; i < number_of_k; i++)
  {
    cin >> k;
    count = 0;
    for(int j = 0; j < set.size(); j++)
    {
      if((int)set.at(j) == k)
      {
        count++;
      }
    }
    cout << count % 1004535809 << endl;
  }
}

int main()
{
  long n, a, number_of_k;
  cin >> n >> a >> number_of_k;
  formSet(n, a, number_of_k);
  return 0;
}

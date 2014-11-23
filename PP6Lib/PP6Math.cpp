#include "PP6Math.hpp"
#include "FileReader.hpp"

#include <iostream>
#include <limits>
#include <cmath>

double add(double a, double b){
       return a+b;
}

double subtract(double a, double b){
       return a-b;
}

double multiply(double a, double b){
       return a*b;
}

double divide(double a, double b){
       return a/b;
}

double intercept(double m, double c){
       return divide(-c, m);
}

double quadratic(double a, double b, double c, bool positiveRoot){
       double t(sqrt(pow(b, 2) - 4 * a * c));
       double res(0);
       if (positiveRoot){
          res = (-b + t) / (2 * a);
       } else {
          res = (-b - t) / (2 * a);
       }
       return res;
}

double length(double x, double y, double z){
        return sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2));
}

double length(double t, double x, double y, double z){
       return sqrt(pow(t, 2) - pow(length(x, y, z), 2));
}

double inv_mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2){
       double tot_e(e1 + e2);
       double tot_px(px1 + px2);
       double tot_py(py1 + py2);
       double tot_pz(pz1 + pz2);
       return length(tot_e, tot_px, tot_py, tot_pz);
}

double getNumber(){
       double res(0);
       std::cin >> res;
       while (!std::cin){
             std::cout << "Error in input. Please re-enter." << std::endl;
             // clear the buffer
             std::cin.clear();
             std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
             // retry
             std::cin >> res;
       }
       return res;
}

int swap(double& a, double& b)
{
  double tmp(a);
  a = b;
  b = tmp;
  return 0;
}

int swap(int& a, int& b)
{
  int tmp(a);
  a = b;
  b = tmp;
  return 0;
}

int basic_sort(double *arr, int size)
{
  // Perform a bubble sort on the given array
  bool done(true);

  while (true)
  {
    done = true;

    for (int i = 0; i < size-1; ++i)
    {
      if (arr[i] < arr[i+1])
      {
        swap(arr[i], arr[i+1]);
        done = false;
      }
    }

    if (done)
    {
      break;
    }
  }
  return 0;
}

int associative_sort(double *arr, int *index, int size)
{
  // create a temporary array to sort on so we only change the index array
  double *arr_t = new double[size];
  for (int i(0); i < size; i++)
  {
    arr_t[i] = arr[i];
  }

  // Perform a bubble sort on the given array
  bool done(true);

  while (true)
  {
    done = true;

    for (int i(0); i < size-1; ++i)
    {
      if (arr_t[i] < arr_t[i+1])
      {
        swap(index[i], index[i+1]);
        swap(arr_t[i], arr_t[i+1]);
        done = false;
      }
    }
    if (done)
    {
      break;
    }
  }

  // delete temporary array, then return success
  delete [] arr_t;
  return 0;
}
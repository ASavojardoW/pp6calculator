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

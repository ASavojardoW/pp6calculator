/// Declaration for PP6Math Functions
#ifndef PP6CALCULATOR_PP6MATH_HH
#define PP6CALCULATOR_PP6MATH_HH

// - Arithmetic
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);

// - Solvers
double intercept(double m, double q);
double quadratic(double a, double b, double c, bool answer);
double length(double x, double y, double z);
double length(double t, double x, double y, double z);
double inv_mass(double e1, double px1, double py1, double pz1, double e2, double px2, double py2, double pz2);
double getNumber();

// - Utility
int swap(double &a, double &b);
int swap(int &a, int &b);
int basic_sort(double *arr, int size);
int associative_sort(double *arr, int *indices, int size);

#endif // PP6CALCULATOR_PP6MATH_HH

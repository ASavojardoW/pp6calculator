// - FourVectorOld.cpp
#include <sstream>
#include <string>
#include "FourVectorOld.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

//FourVector::FourVector() {t=0; x=0; y=0, z=0;}

FourVectorOld::FourVectorOld(const double& t_, const double& x_, const double& y_, const double& z_)
    : t(t_), x(x_), y(y_), z(z_)
{}

FourVectorOld::FourVectorOld(const FourVectorOld& other)
    : t(other.t), x(other.x), y(other.y), z(other.z)
{}

double FourVectorOld::interval(){
       double s = pow(t,2) - pow(x,2) - pow(y,2) - pow(z,2);
       return s;
}

double FourVectorOld::boost_z(double v){
       double beta, gamma;
       const double c = 3.e8;
       beta = v/c;
       gamma = 1/sqrt(1-pow(beta,2));
       t = gamma*(t - (v*x)/pow(c,2));
       z = gamma*(z - v*t);
       return 0;
}

double FourVectorOld::getT() const {  
    return t;
}

double FourVectorOld::getX() const {  
    return x;
}

double FourVectorOld::getY() const {  
    return y;
}

double FourVectorOld::getZ() const {  
    return z;
}

std::ostream& operator<<(std::ostream& stream, const FourVectorOld& v){
   stream << "[";
   stream << v.getT() << ", " << v.getX() << ", ";
   stream << v.getY() << ", " << v.getZ() << "]";
   return stream;
}
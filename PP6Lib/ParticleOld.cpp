// - ParticleOld.cpp
#include <sstream>
#include <string>
#include "PP6Math.hpp"
#include "ParticleOld.hpp"
#include <fstream>
#include <cmath>
#include <iostream>

ParticleOld::ParticleOld(const double& e_1_, const double& px_1_, const double& py_1_, const double& pz_1_, const double& e_2_, const double& px_2_, const double& py_2_, const double& pz_2_)
    :e_1(e_1_), px_1(px_1_), py_1(py_1_), pz_1(pz_1_), e_2(e_2_), px_2(px_2_), py_2(py_2_), pz_2(pz_2_)
{}

ParticleOld::ParticleOld(const ParticleOld& other)
    :e_1(other.e_1), px_1(other.px_1), py_1(other.py_1), pz_1(other.pz_1), e_2(other.e_2), px_2(other.px_2), py_2(other.py_2), pz_2(other.pz_2)
{}

double ParticleOld::inv_mass(){
       double tot_e(e_1 + e_2);
       double tot_px(px_1 + px_2);
       double tot_py(py_1 + py_2);
       double tot_pz(pz_1 + pz_2);
       return length(tot_e, tot_px, tot_py, tot_pz);
}



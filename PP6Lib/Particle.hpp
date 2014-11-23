#ifndef PARTICLE_HPP
#define PARTICLE_HPP
#include <fstream>
#include <cmath>

class Particle {
    public:
      Particle(const double& e_1_, const double& px_1_, const double& py_1_, const double& pz_1_, const double& e_2_, const double& px_2_, const double& py_2_, const double& pz_2_);

      Particle(const Particle& other);

      ~Particle(){};

      //member functions
      double inv_mass();

    private:
      //member variables
      double e_1;
      double px_1;
      double py_1;
      double pz_1;
      double e_2;
      double px_2;
      double py_2;
      double pz_2;
};

#endif // FOURVECTOR_HHP

#ifndef PP6CUT_HPP
#define PP6CUT_HPP

#include "PP6Particle.hpp"

class Cut {
  public:

    virtual ~Cut();

    virtual bool select(const Particle& selected) = 0;
    virtual std::vector<Particle> select(const Particle& selected) = 0;

};

#endif // PP6CUT_HPP 
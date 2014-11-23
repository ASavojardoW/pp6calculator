#include "PP6Day2Menu.hpp"

#include <iostream>
#include <limits>
#include <cmath>
#include <string>
#include <cstdlib>

#include "PP6Math.hpp"
#include "FileReader.hpp"

void pp6day2menu(){
    double res, res2;
    char op('\0');
    while(true){
      // Ask the user what they want to do
    std::cout << "Enter the operation you would like to perform:" << std::endl;
    std::cout << "1)  Generate 100 random energies and 3-momenta" << std::endl;
    std::cout << "2)  Analyse a data file " << std::endl;
    std::cout << "q)  Quit" << std::endl;
    std::cout << ">> ";
    
    std::cin >> op;
      
    // check for bad input
    if(!std::cin)
    {
      std::cerr << "[error] Error in input" << std::endl;
    
      // clear the buffer
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }

    // Handle menu operation
    if (op == 'q')
    {
      break;
    }
    
    else if (op == '1')
    {
      int i;
      double Energy[100],px,py,pz,m;
      double Mean_Energy, Standard_deviation;
      
      Mean_Energy=0;
      Standard_deviation=0;
 
      
      for(i=0;i<100;i++){
	
      
      px = double(rand()%100)/100; 
      py = double(rand()%100)/100;  
      pz = double(rand()%100)/100; 
      m = double(rand()%100)/100;  
      
      Energy[i] = m*m + length(px,py,pz)*length(px,py,pz); // Random number between 0-99
      
      
      Mean_Energy +=Energy[i]/100;
      
      }
      
      for(i=0;i<100;i++){
      
      
      Standard_deviation +=(Energy[i]-Mean_Energy)*(Energy[i]-Mean_Energy)/100;
      
      }

      res = Mean_Energy;
      res2 = sqrt(Standard_deviation);
      
    }
    else if (op == '2')
    {    
    FileReader f("/home/as/Desktop/C++/2/observedparticles.dat");
    // Only process if the file is open/valid
    double px_p[1000], py_p[1000], pz_p[1000];
    double px_m[1000], py_m[1000], pz_m[1000];
    int event_p[1000], event_m[1000];
    int ip = 0;
    int im = 0;
    if (f.isValid()) {
    // Loop until out of lines
       while (f.nextLine()) {
       // Fields in each line line are treated as whitespace separated
       // and counted from 1. Fields can be retrieved as one of four main
       // types

       // retrieve field 2 as a float
       std::string b = f.getFieldAsString(2);

       // retrieve field 6 as a string
       std::string g = f.getFieldAsString(6);

       if(g == "run4.dat"){
              if(b == "mu+" ){
                 px_p[ip] = f.getFieldAsDouble(3);
                 py_p[ip] = f.getFieldAsDouble(4);
                 pz_p[ip] = f.getFieldAsDouble(5);
                 event_p[ip] = f.getFieldAsInt(1);
                 std::cout << event_p[im] << "  " << g << "  " << b << "   px = " << px_p[ip] << " py= " << py_p[ip] << " pz = " << pz_p[ip] << std::endl;
                 ip++;
//                 std::cout << ip << std::endl;
              }
              if(b == "mu-" ){
                 px_m[im] = f.getFieldAsDouble(3);
                 py_m[im] = f.getFieldAsDouble(4);
                 pz_m[im] = f.getFieldAsDouble(5);
                 event_m[im] = f.getFieldAsInt(1);
                 std::cout << event_m[im] << "  " << g << "  " << b << "   px = " << px_m[im] << " py= " << py_m[im] << " pz = " << pz_m[im] << std::endl;
                 im++;
//                 std::cout << im << std::endl; 
              }
       }
       }
       // Check that input is o.k.
       if (f.inputFailed()) break;
       }

         double mu_mass = 1.;
         double p_p, p_m, E_p, E_m;
         for(int i = 0; i <= ip; i++){
            for(int j = 0; j <= im; j++){
                std::cout << "mu+ event: " << event_p[i] << "; mu- event: " << event_m[j] << std::endl;
                p_p = length(px_p[i], py_p[i], pz_p[i]);
                p_m = length(px_m[j], py_m[j], pz_m[j]);
                E_p = sqrt(pow(mu_mass,2) + pow(p_p,2));
                E_m = sqrt(pow(mu_mass,2) + pow(p_m,2));
                res = inv_mass(E_p, px_p[i], py_p[i], pz_p[i], E_m, px_m[j], py_m[j], pz_m[j]);
                std::cout << "The invariant mass is: m = " << res << std::endl;                
            }
         }   
      
      
    }
      
  
      
   // }
   
    
   

    else
    {
      std::cerr << "[error] Operation '" << op << "' not recognised."
                << std::endl;
      continue;
    }
      
    // print the result(s)
    if (op == '1')
    {
      std::cout << "[result]: mean energy: " << res << std::endl;
      std::cout << "[result]: standard deviation: " << res2 << std::endl;
  }
  }  

}
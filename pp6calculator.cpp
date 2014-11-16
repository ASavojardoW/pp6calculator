#include <iostream>
#include <limits>
#include <cmath>
#include <cstdlib>
#include "PP6Math.hpp"
#include "FileReader.hpp" 

//----------------------------------------------------------------------
// Main program
//
int main() 
{
  // Declare the variables
  double res(0), res2(0);
  char op('\0');
  char op_day('\0');
  
  
  
 while (true){
    // Ask the user what they want to do
    std::cout << "Enter the operation you would like to perform:" << std::endl;
    std::cout << "1)  Day 1" << std::endl;
    std::cout << "2)  Day 2" << std::endl;
    std::cout << "q)  Quit" << std::endl;

    std::cout << ">> ";
    
    std::cin >> op_day;
      
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
    if (op_day == 'q')
    {
      break;
    }
  
  
/*DAY 1*/
  
if (op_day == '1'){
  {
    // Ask the user what they want to do
    std::cout << "Enter the operation you would like to perform:" << std::endl;
    std::cout << "1)  Addition" << std::endl;
    std::cout << "2)  Subtraction" << std::endl;
    std::cout << "3)  Multiplication" << std::endl;
    std::cout << "4)  Division" << std::endl;
    std::cout << "5)  Intercept" << std::endl;
    std::cout << "6)  Quadratic Solver" << std::endl;
    std::cout << "7)  Length of 3-Vector" << std::endl;
    std::cout << "8)  Length of 4-Vector" << std::endl;
    std::cout << "9)  Invariant Mass of Two Particles" << std::endl;
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
    else if((op == '1') || (op == '2') || (op == '3') || (op == '4') )
    {
      // Arithmetic operations, so ask for two numbers from the user
      double a(0), b(0);
      std::cout << "Enter the first number: ";
      a = getNumber();
      std::cout << "Enter the second number: ";
      b = getNumber();
       
      // calculate the result
      if (op == '1')
      {
        res = add(a, b);
      }
      else if (op == '2')
      {
        res = subtract(a, b);
      }
      else if (op == '3')
      {
        res = multiply(a, b);
      }
      else if (op == '4')
      {
        if (b == 0)
        {
          std::cerr << "[error] Divide by zero error" << std::endl;
          continue;
        }
        else
        {
          res = divide(a, b);
        }
      }
    }
    else if (op == '5')
    {
      double m(0), c(0);

      // Ask for two numbers from the user
      std::cout << "Enter the gradient: ";
      m = getNumber();
      std::cout << "Enter the y intercept: ";
      c = getNumber();

      if (c==0)
      {
        std::cerr << "[error] Divide by zero error" << std::endl;
        continue;
      }
      else
      {
        res = intercept(m, c);
      }
    }
    else if (op == '6')
    {
      // Solve ax^2 + bx + c = 0
      double a(0), b(0), c(0);

      // Ask user for quadratic coefficients
      std::cout << "Enter the square coefficient: ";
      a = getNumber();
      std::cout << "Enter the linear coefficient: ";
      b = getNumber();
      std::cout << "Enter the constant coefficient: ";
      c = getNumber();

      if (pow(b, 2) < (4 * a * c))
      {
        std::cerr << "[error]: No solutions possible (b^2 < 4ac)" 
                  << std::endl;
        continue;
      }
      if (a == 0)
      {
        std::cerr << "[error]: Divide by zero error (a=0)" << std::endl;
        continue;
      }
      else
      {
        res = quadratic(a, b, c, true);
        res2 = quadratic(a, b, c, false);
      }
    }
    else if (op == '7')
    {
      // Calculate sqrt(x^2+y^2+z^2)
      double x(0), y(0), z(0);

      // Ask user for vector components
      std::cout << "Enter the x-component: ";
      x = getNumber();
      std::cout << "Enter the y-component: ";
      y = getNumber();
      std::cout << "Enter the z-component: ";
      z = getNumber();

      res = length(x, y, z);
    }
    else if (op == '8')
    {
      // Calculate sqrt(t^2 - (x^2+y^2+z^2))
      double x(0), y(0), z(0), t(0);

      // Ask user for vector components
      std::cout << "Enter the x-component: ";
      x = getNumber();
      std::cout << "Enter the y-component: ";
      y = getNumber();
      std::cout << "Enter the z-component: ";
      z = getNumber();
      std::cout << "Enter the t-component: ";
      t = getNumber();
  
      if (pow(t,2) < length(x, y, z))
      {
        std::cerr << "[error] Space-like component larger than Time-like"
                  << std::endl;
        continue;
      }

      res = length(t, x, y, z);
    }
    else if (op == '9')
	  {
      double e1(0), px1(0), py1(0), pz1(0), e2(0), px2(0), py2(0), pz2(0);

      // Ask for eight numbers from the user
      std::cout << "Enter the px value for the first particle: ";
      px1 = getNumber();
      std::cout << "Enter the py value for the first particle: ";
      py1 = getNumber();
      std::cout << "Enter the pz value for the first particle: ";
      pz1 = getNumber();
      std::cout << "Enter the e value for the first particle: ";
      e1 = getNumber();
      std::cout << "Enter the px value for the second particle: ";
      px2 = getNumber();
      std::cout << "Enter the py value for the second particle: ";
      py2 = getNumber();
      std::cout << "Enter the pz value for the second particle: ";
      pz2 = getNumber();
      std::cout << "Enter the e value for the second particle: ";
      e2 = getNumber();

      if (pow(e1, 2) < length(px1, py1, pz1))
      {
        std::cerr << "[error]: Space-like component larger than Time-like for first particle" << std::endl;
        continue;
      }

      if (pow(e2, 2) < length(px2, py2, pz2))
      {
        std::cerr << "[error]: Space-like component larger than Time-like for second particle" << std::endl;
        continue;
      }

      res = inv_mass(e1, px1, py1, pz1, e1, px1, py1, pz1 );
    }

    else
    {
      std::cerr << "[error] Operation '" << op << "' not recognised."
                << std::endl;
      continue;
    }
      
    // print the result(s)
    if (op == '6')
    {
      std::cout << "[result]: positive_root: " << res << std::endl;
      std::cout << "[result]: negative_root: " << res2 << std::endl;
    }
    else
    {
      std::cout << "[result]: " << res << std::endl;
    }
  }
  

}
  
/*DAY 2*/

if (op_day == '2'){
  {
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
      
      Energy[i] = m*m + length(px,py,pz); // Random number between 0-99
      
      
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
    FileReader f("/home/as/Desktop/C++/2/observedparticles.dat"); //CAMBIA IL PATH
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
         for(int i = 0; i <= 3; i++){
            for(int j = 0; j <= 3; j++){
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
}
  
  std::cout << "Thank you for using pp6calculator!" << std::endl;
  return 0;
}

 

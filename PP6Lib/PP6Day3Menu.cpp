#include "PP6Math.hpp"
#include "PP6Day3Menu.hpp"
#include "FourVector.hpp"
#include "Particle.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <fstream>

#include "FileReader.hpp"

void pp6day3menu(){
     double res;
     char op('\0');
     while(true){
        // Ask the user what they want to do
        std::cout << "Enter the operation you would like to perform:" << std::endl;
        std::cout << "1) Boost a 4-Vector Along z" << std::endl;
        std::cout << "2) Calculate 4-Vector Length" << std::endl;
        std::cout << "3) Analyse a data file " << std::endl;
        std::cout << "q) Quit" << std::endl;
        std::cout << ">> ";
        std::cin >> op;
     // check for bad input
     if(!std::cin){
        std::cerr << "[error] Error in input" << std::endl;
        // clear the buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        continue;
     } 
     if (op == 'q'){
        break;
     }

     else if(op == '1'){
          double time, cx, cy, cz, v;
          std::cout << "Enter the 4-Vector components: " << std::endl;
          time = getNumber();
          cx = getNumber();
          cy = getNumber();
          cz = getNumber();
          std::cout << "Enter the velocity: " << std::endl;
          v = getNumber();
          FourVector q(time, cx, cy, cz);
          q.boost_z(v);
          std::cout << "New vector: {" << q.getT() << "," << q.getX() << "," << q.getY() << "," << q.getZ() << "}" << std::endl;
     }

     else if(op == '2'){
          double time, cx, cy, cz, v;
          std::cout << "Enter the 4-Vector components: " << std::endl;
          time = getNumber();
          cx = getNumber();
          cy = getNumber();
          cz = getNumber();
          std::cout << "4-Vector: {" << time << "," << cx << "," << cy << "," << cz << "}" << std::endl;
          FourVector q(time, cx, cy, cz);
          q.interval();
          std::cout << "Interval s = " << q.interval() << std::endl;          
     }
     else if(op == '3'){
      std::string path;
      std::cout << "Give the file path" << std::endl;
      std::cin >> path;
      FileReader f(path);
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
       double *muonEnergy(new double[ip*im]), *antimuonEnergy(new double[ip*im]);
       double *muonPx(new double[ip*im]), *muonPy(new double[ip*im]), *muonPz(new double[ip*im]);
       double *antimuonPx(new double[ip*im]), *antimuonPy(new double[ip*im]), *antimuonPz(new double[ip*im]);
       double *result(new double[ip*im]);
       int *event_muon(new int[ip*im]), *event_antimuon(new int[ip*im]), *event_index(new int[ip*im]);
       for(int i = 0; i < im; i++){
          for(int j = 0; j < ip; j++){
              std::cout << "mu+ event: " << event_p[i] << "; mu- event: " << event_m[j] << std::endl;
              p_p = length(px_p[j], py_p[j], pz_p[j]);
              p_m = length(px_m[i], py_m[i], pz_m[i]);
              E_p = sqrt(pow(mu_mass,2) + pow(p_p,2));
              E_m = sqrt(pow(mu_mass,2) + pow(p_m,2));
              muonPx[i*ip+j] = px_p[j];
              muonPy[i*ip+j] = py_p[j];
              muonPz[i*ip+j] = pz_p[j];
	      muonEnergy[i*ip+j] = E_p;
              antimuonPx[i*ip+j] = px_m[i];
              antimuonPy[i*ip+j] = py_m[i];
              antimuonPz[i*ip+j] = pz_m[i];
	      antimuonEnergy[i*ip+j] = E_m;
              Particle q(E_p, px_p[j], py_p[j], pz_p[j], E_m, px_m[i], py_m[i], pz_m[i]);
              result[i*ip+j] = q.inv_mass();
              event_muon[i*ip+j] = event_p[j];
              event_antimuon[i*ip+j] = event_m[i];
              event_index[i*ip+j] = i*ip+j;
              std::cout << "The invariant mass is: m = " << result[i*ip+j] << std::endl;                
            }
         }
         
         // Use associative sort to sort masses
         associative_sort(result, event_index, ip*im);
         
         //--------------------------------------------------------------------
         // - Present results
         //
	 std::cout << "Results:" << std::endl;
	 std::cout << "========" << std::endl;
	 std::cout << "Analysed File : " << path << std::endl;
	 std::cout << "Number of Muons     = " << ip << std::endl;
         std::cout << "Number of AntiMuons = " << im << std::endl;
         std::cout << "----------------------------" << std::endl;

         for (int i = 0; i < 10; ++i) {
        // int muonIndex(muonPairIndex[i] % numberOfMuons);
        // int antimuonIndex((muonPairIndex[i] - muonIndex) / numberOfMuons);

         std::cout << "{InvariantMass : " << result[event_index[i]]
              << ",\n\t"
              << "{Muon : "
              << "Event = " << event_muon[event_index[i]] << ", "
              << "(E, P) = ("
              << muonEnergy[event_index[i]] << ", "
              << muonPx[event_index[i]] << ", "
              << muonPy[event_index[i]] << ", "
              << muonPz[event_index[i]] << ")}\n\t"
              << "{AntiMuon : "
              << "Event = " << event_antimuon[event_index[i]] << ", "
              << "(E, P) = ("
              << antimuonEnergy[event_index[i]] << ", "
              << antimuonPx[event_index[i]] << ", "
              << antimuonPy[event_index[i]] << ", "
              << antimuonPz[event_index[i]] << ")}\n"
              << "}"
              << std::endl;
         }
      
    }else{
       std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
       continue;
    }
    }
     
}

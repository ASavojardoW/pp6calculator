#include "PP6Math.hpp"
#include "PP6Day4Menu.hpp"
#include "PP6FileReader.hpp"
#include "Particle.hpp"
#include "PP6ParticleInfo.hpp"

#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <string>
#include <map>

#include "FileReader.hpp"

void pp6day4menu(){
    std::vector<int> event;
    std::vector<int> pdg_code;
    std::vector<int> charge;
    std::vector<double> mass;
    std::vector<double> px;
    std::vector<double> py;
    std::vector<double> pz;
    std::vector<std::string> particle_name;
    std::vector<std::string> name;
    std::vector<std::string> run;

    std::string database_path;
    std::cout << "Give the database path" << std::endl;
    std::cin >> database_path;
    PP6FileReader file(database_path);

    if (file.isValid()) {
      // Loop until out of lines
        while (file.nextLine()) {
        // Fields in each line line are treated as whitespace separated
        // and counted from 1.
          particle_name.push_back(file.getField(1, particle_name));
          pdg_code.push_back(file.getField(2, pdg_code));
          charge.push_back(file.getField(3, charge);
          mass.push_back(file.getField(4, mass));
                 
       }
     // Check that input is o.k.
     if (file.inputFailed()) break;
    }
    
    std::string path;
    std::cout << "Give the file path" << std::endl;
    std::cin >> path;
    PP6FileReader f(path);
    
    if (f.valid()) {
     // Loop until out of lines
     while (f.nextLine()) {
      // Fields in each line line are treated as whitespace separated
      // and counted from 1.
      event.push_back(f.getField(1, event));
      name.push_back(f.getField(2, name));
      px.push_back(f.getField(3, px);
      py.push_back(f.getField(4, py));           
      pz.push_back(f.getField(5, pz));
      run.push_back(f.getField(6, run));
      
     }
    // Check that input is o.k.
    if (file.inputFailed()) break;
    }
    
    //ip = 
    //im = 
    //mu_mass = 
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
      
}

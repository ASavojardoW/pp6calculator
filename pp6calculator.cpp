#include "PP6Day1Menu.hpp"
#include "PP6Day2Menu.hpp"
#include "PP6Day3Menu.hpp"
#include "PP6Day4Menu.hpp"
#include "PP6Day5Menu.hpp"

#include <iostream>
#include <limits>

//----------------------------------------------------------------------
// Main program
// 
int main() {
    char op('\0');
    
    while(true){
       // Ask for the day
       std::cout << "Enter the operation you would like to perform:" << std::endl;
       std::cout << "1) 1st day" << std::endl;
       std::cout << "2) 2nd day" << std::endl;
       std::cout << "3) 3rd day" << std::endl;
       std::cout << "4) 4th day" << std::endl;
       std::cout << "5) 5th day" << std::endl;
       std::cout << "q) Quit" << std::endl;
       std::cout << ">> ";
       std::cin >> op;
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
       pp6day1menu();
    }

    else if(op == '2'){  
       pp6day2menu();
    }

    else if(op == '3'){  
       pp6day3menu();
    }
    
    else if(op == '4'){  
       pp6day4menu();
    }
    
    else if(op == '5'){  
       pp6day5menu();
    }
    else{
        std::cerr << "[error] Operation '" << op << "' not recognised." << std::endl;
        continue;
    }
    }
  
  std::cout << "Thank you for using pp6calculator!" << std::endl;
  return 0;
}

 

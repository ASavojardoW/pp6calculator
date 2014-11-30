#include <sstream>
#include "PP6FileReader.hpp"

PP6FileReader::PP6FileReader(const char* filename)
  : file(filename), line(), failed(false)
{}

PP6FileReader::PP6FileReader(const std::string& filename)
  : file(filename.c_str()), line(), failed(false)
{}  

bool PP6FileReader::isValid() const {
  if ( ! file )
    return false;
  else
    return true;
}

bool PP6FileReader::nextLine(){
  getline(file, line);
  if (file.eof())
    return false;
  else 
    return true;
}

void PP6FileReader::skip_fields(std::istringstream& ist, const int n) {
  if (n < 1)
    return;
  std::string tmp;
  for(int i = 1; i <= n; ++i) {
    ist >> tmp;
  }
}

void PP6FileReader::getField(const int n, T& rval){
     failed = false;
     std::istringstream ist(line);
     this->skip_fields(ist, n-1);
     ist >> rval;
     if (ist.fail()) {
        failed = true;
     return 0;
     }
     else
     return rval;
}


bool PP6FileReader::inputFailed() const {
  return failed;
}

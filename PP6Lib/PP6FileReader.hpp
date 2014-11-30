#ifndef PP6FILEREADER_HPP
#define PP6FILEREADER_HPP

#include <fstream>
#include <string>


class PP6FileReader {
 public:
  PP6FileReader(const char* filename);
  PP6FileReader(const std::string& filename);

  bool nextLine();

  template <typename T> 
  void getField(const int n, T* rval);


  bool inputFailed() const {return failed;}
  bool isValid() const;

 private:
  void skip_fields(std::istringstream& ist, const int n);
  std::ifstream file;
  std::string line;
  bool failed;
};


#endif

#include <iostream>
 
class Intern {
public:
  uint add(const std::string& str) {
    uint index = -1;
    uint block = 0;
    char c;
    for (uint c : str) {
      if (block >= fwd.size()) {
        block = fwd.size();
        fwd.resize(block + 256, -1);
        bwd.push_back(index);
        if (index != (uint) -1)
          fwd[index] = block;
      }
      index = block + c;
      block = fwd[index];
    }
    return index;
  }

  std::string get(uint index) {
    std::string str;
    while (index != (unsigned)-1) {
      str.insert(0, 1, index % 256);
      index = bwd[index / 256];
    }
    return str;
  }

  private:
    std::vector<uint> fwd;
    std::vector<uint> bwd;
};
 
int main()
{
  Intern intern;

  uint id = intern.add("ABC");
  uint id2 = intern.add("DEF");
  std::cout << id << std::endl;
  std::cout << intern.get(id) << std::endl;
  std::cout << id2 << std::endl;
  std::cout << intern.get(id2) << std::endl;

  return 0;
}
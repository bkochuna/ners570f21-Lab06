#include "hello.hpp"
#include <sstream>

using namespace spmv;

int main()
{
  std::ostringstream oss;
  std::streambuf *p_cout_streambuf = std::cout.rdbuf();
  std::cout.rdbuf(oss.rdbuf());

  hello();

  std::cout.rdbuf(p_cout_streambuf); // restore

  // test your oss content...
  assert(oss && oss.str() == "Hello\n");
  std::cout << oss.str();

  return 0;
}
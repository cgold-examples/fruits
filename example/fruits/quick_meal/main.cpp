#include <iostream>
#include <fruits/fruits.hpp>

int main() {
  using fruits::rosaceae::Plum;
  using fruits::rosaceae::Pear;

  std::cout << "Quick meal:" << std::endl;
  std::cout << "  " << Plum::name() << " x 2" << std::endl;
  std::cout << "  " << Pear::name() << " x 1" << std::endl;
}

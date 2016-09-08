#include <iostream>

#include <fruits/rosaceae/Plum.hpp>
#include <fruits/tropical/Pineapple.hpp>

int main() {
  using fruits::rosaceae::Plum;
  using fruits::tropical::Pineapple;

  std::cout << "Dinner:" << std::endl;
  std::cout << "  " << Plum::name() << " x 2" << std::endl;
  std::cout << "  " << Pineapple::name() << " x 1" << std::endl;
}

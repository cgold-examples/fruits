#include <iostream>
#include <fruits/fruits.hpp>

int main() {
  using fruits::rosaceae::Plum;
  using fruits::rosaceae::Pear;
  using fruits::tropical::Pineapple;
  using fruits::tropical::Avocado;

  std::cout << "Vegan party:" << std::endl;
  std::cout << "  " << Plum::name() << " x 200" << std::endl;
  std::cout << "  " << Pear::name() << " x 100" << std::endl;
  std::cout << "  " << Pineapple::name() << " x 15" << std::endl;
  std::cout << "  " << Avocado::name() << " x 60" << std::endl;
}

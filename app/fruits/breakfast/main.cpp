#include <iostream> // std::cout

#include <fruits/breakfast/flatware/Teaspoon.hpp>
#include <fruits/tropical/Avocado.hpp>

int main() {
  using fruits::breakfast::flatware::Teaspoon;
  using fruits::tropical::Avocado;

  std::cout << "Breakfast:" << std::endl;
  std::cout << "  prepare " << Teaspoon::name() << std::endl;
  std::cout << "  eat " << Avocado::name() << std::endl;
}

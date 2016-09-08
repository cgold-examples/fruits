#include <gtest/gtest.h> // TEST
#include <fstream> // std::ifstream

#include <fruits/tropical/Avocado.hpp>

namespace fruits {
namespace tropical {
namespace unittest {

TEST(fruits_tropical_avocado, check_tropical) {
  using fruits::tropical::Avocado;

  ASSERT_TRUE(Avocado::tropical());
}

TEST(fruits_tropical_avocado, read_file) {
  std::ifstream file("avocado.ini");

  ASSERT_TRUE(file);
}

} // namespace unittest
} // namespace tropical
} // namespace fruits

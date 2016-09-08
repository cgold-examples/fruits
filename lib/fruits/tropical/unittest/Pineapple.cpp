#include <gtest/gtest.h> // TEST

#include <fruits/tropical/Pineapple.hpp>

namespace fruits {
namespace tropical {
namespace unittest {

TEST(fruits_tropical_pineapple, skin_off) {
  using fruits::tropical::Pineapple;

  ASSERT_TRUE(Pineapple::skin_off());
}

} // namespace unittest
} // namespace tropical
} // namespace fruits

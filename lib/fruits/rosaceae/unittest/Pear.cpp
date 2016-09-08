#include <gtest/gtest.h> // TEST

#include <fruits/rosaceae/Pear.hpp>

namespace fruits {
namespace rosaceae {
namespace unittest {

TEST(fruits_rosaceae_pear, skin_off) {
  using fruits::rosaceae::Pear;

  ASSERT_FALSE(Pear::skin_off());
}

} // namespace unittest
} // namespace rosaceae
} // namespace fruits

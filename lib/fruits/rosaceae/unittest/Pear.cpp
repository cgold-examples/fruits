#include <gtest/gtest.h> // TEST

#include <fruits/rosaceae/Pear.hpp>

namespace fruits {
namespace rosaceae {
namespace unittest {

TEST(fruits_rosaceae_pear, skin_off) {
  using fruits::rosaceae::Pear;

  Pear pear(1);

  ASSERT_FALSE(pear.skin_off());

  // Test private API
  ASSERT_EQ(pear.code(), 67);
}

} // namespace unittest
} // namespace rosaceae
} // namespace fruits

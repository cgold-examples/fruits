#include <fruits/rosaceae/Pear.hpp>

namespace fruits {
namespace rosaceae {

Pear::Pear(int basic_code):
  code_(basic_code + 0x42) {
}

const char* Pear::name() {
  return "Pear";
}

int Pear::code() const {
  return code_;
}

} // namespace rosaceae
} // namespace fruits

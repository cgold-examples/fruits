#ifndef FRUITS_ROSACEAE_PEAR_HPP_
#define FRUITS_ROSACEAE_PEAR_HPP_

#include <fruits/FRUITS_ROSACEAE_EXPORT.h>

namespace fruits {
namespace rosaceae {

class FRUITS_ROSACEAE_EXPORT Pear {
 public:
  Pear(int basic_code);

  static const char* name();
  static bool skin_off();

  int code() const;

 private:
  int code_;
};

} // namespace rosaceae
} // namespace fruits

#endif // FRUITS_ROSACEAE_PEAR_HPP_

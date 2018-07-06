#ifndef FRUITS_ROSACEAE_PEAR_HPP_
#define FRUITS_ROSACEAE_PEAR_HPP_

#include <fruits/FRUITS_ROSACEAE_EXPORT.h>

namespace fruits {
namespace rosaceae {

class Pear {
 public:
  FRUITS_ROSACEAE_EXPORT Pear(int basic_code);

  FRUITS_ROSACEAE_EXPORT static const char* name();
  FRUITS_ROSACEAE_EXPORT static bool skin_off();

  int code() const;

 private:
  int code_;
};

} // namespace rosaceae
} // namespace fruits

#endif // FRUITS_ROSACEAE_PEAR_HPP_

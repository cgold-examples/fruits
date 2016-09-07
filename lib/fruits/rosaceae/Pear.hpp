#ifndef FRUITS_ROSACEAE_PEAR_HPP_
#define FRUITS_ROSACEAE_PEAR_HPP_

namespace fruits {
namespace rosaceae {

class Pear {
 public:
  Pear(int basic_code);

  static const char* name();

  int code() const;

 private:
  int code_;
};

} // namespace rosaceae
} // namespace fruits

#endif // FRUITS_ROSACEAE_PEAR_HPP_

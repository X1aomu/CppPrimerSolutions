#include "common/string.h"

#include <memory>

using std::allocator;

namespace cps {

// definition for static data member
allocator<char> String::alloc_; // default initialization

// TODO implement operator overloaded functions

} // namespace cps

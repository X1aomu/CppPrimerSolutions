#include "common/str_vec.h"

#include <memory>
#include <string>

using std::allocator;
using std::string;

namespace cps {

// definition for static data member
allocator<string> StrVec::alloc; // default initialization

// all other StrVec members are inline and defined inside "common/str_vec.h"

} // namespace cps

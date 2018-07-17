#include "13/31_has_ptr.h"

namespace cps {

bool operator<(const HasPtr &l, const HasPtr &r) { return *l.ps_ < *r.ps_; }

} // namespace cps

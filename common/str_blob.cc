#include "common/str_blob.h"

namespace cps {

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data_->size()); }

ConstStrBlobPtr StrBlob::cbegin() const { return ConstStrBlobPtr(*this); }

ConstStrBlobPtr StrBlob::cend() const {
  return ConstStrBlobPtr(*this, data_->size());
}

} // namespace cps

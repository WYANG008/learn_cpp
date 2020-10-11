#include <string>

#include "slice.h"

#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

int MAC(int x, int y, int& sum);

void PutVarint32(std::string* dst, uint32_t value);
bool GetVarint32(leveldb::Slice* input, uint32_t* value);

// Internal routine for use by fallback path of GetVarint32Ptr
const char* GetVarint32PtrFallback(const char* p, const char* limit,
                                   uint32_t* value);
inline const char* GetVarint32Ptr(const char* p, const char* limit,
                                  uint32_t* value) {
  if (p < limit) {
    uint32_t result = *(reinterpret_cast<const uint8_t*>(p));
    if ((result & 128) == 0) {
      *value = result;
      return p + 1;
    }
  }
  return GetVarint32PtrFallback(p, limit, value);
}

#endif /* EXAMPLE_HPP */
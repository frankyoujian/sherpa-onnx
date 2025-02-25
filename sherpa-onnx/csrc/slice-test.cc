// sherpa-onnx/csrc/slice-test.cc
//
// Copyright (c)  2023  Xiaomi Corporation

#include "sherpa-onnx/csrc/slice.h"

#include <numeric>

#include "gtest/gtest.h"
#include "sherpa-onnx/csrc/onnx-utils.h"

namespace sherpa_onnx {

TEST(Slice, Slice3D) {
  Ort::AllocatorWithDefaultOptions allocator;
  std::array<int64_t, 3> shape{3, 5, 4};
  Ort::Value v =
      Ort::Value::CreateTensor<float>(allocator, shape.data(), shape.size());
  float *p = v.GetTensorMutableData<float>();

  std::iota(p, p + shape[0] * shape[1] * shape[2], 0);

  auto v1 = Slice(&v, 0, 2, 5);
  auto v2 = Slice(&v, 1, 2, 4);

  Print3D(&v);
  Print2D(&v1);
  Print2D(&v2);

  // TODO(fangjun): Check that the results are correct
}

}  // namespace sherpa_onnx

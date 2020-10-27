#pragma once

#include <vector>
#include <iostream>

#include "src/util/tensor.h"

using namespace compute_graph;

void test_tensor_construct()
{
    shape_t shape = shape_t({3, 5, 7});

    // random tensor with shape [3, 5, 7]
    Tensor tensor_a = Tensor(shape);
    assert(tensor_a.expr() == "Tensor[3, 5, 7]");

    Tensor tensor_b = Tensor(tensor_a);
    Tensor tensor_c = Tensor(shape_t({5, 7}), 0.7f);

    Tensor tensor_d = tensor_b + tensor_c;
    assert(tensor_b != tensor_a);
}
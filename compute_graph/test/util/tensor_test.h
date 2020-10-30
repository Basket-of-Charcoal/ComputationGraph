#pragma once

#include <cassert>
#include <iostream>
#include <vector>

#include "src/util/log.h"
#include "src/util/tensor.h"

using namespace compute_graph;

void test_tensor_construct()
{
    shape_t shape = shape_t({3, 5, 7});

    // random tensor with shape [3, 5, 7]
    Tensor tensor_a = Tensor(shape);
    assert(tensor_a.expr() == "Tensor[3, 5, 7]");

    INFO("check 1");
    Tensor tensor_b = Tensor(tensor_a);
    Tensor tensor_c = Tensor(shape_t({5, 7}), 0.7f);

    INFO("check 2");
    tensor_b = tensor_b + tensor_c;

    INFO("check 3");
    assert(tensor_b != tensor_a);

    float inp[] = {0.2f, 0.5f, -1.4f, 3.3f};
    tensor_b = Tensor(shape_t({2, 2}), inp);

    INFO("xxx %s", tensor_b.expr().c_str());
    assert(tensor_b ==
           Tensor(shape_t({2, 2}), std::vector<data_t>({0.2f, 0.5f, -1.4f, 3.3f})));
}

void test_tensor_calculate()
{
    Tensor tensor_a = Tensor(shape_t({2, 2}), {0.2f, 0.5f, -1.4f, 3.3f});
    Tensor tensor_b = Tensor(shape_t({2}), {0.3f, -0.9f});

    assert((tensor_a + tensor_b) == Tensor(shape_t({2, 2}), {0.5f, -0.4f, -1.1f, 2.4f}));

    tensor_b += Tensor(shape_t({2}), {0.2f, 0.5f});
    assert(tensor_b == Tensor(shape_t({2}), {0.5f, -0.4f}));

    tensor_b *= 3;
    assert(tensor_b == Tensor(shape_t({2}), {1.5f, -1.2f}));

    tensor_a /= 2;
    assert(tensor_a == Tensor(shape_t({2, 2}), {0.1f, 0.25f, -0.7f, 1.65f}));
}

void test_tensor_interface()
{
    Tensor tensor_a = Tensor(shape_t({2, 2}), {0.2f, 0.5f, -1.4f, 3.3f});
    assert(tensor_a.dim() == 2);

    tensor_a = Tensor(shape_t({2, 2, 5, 7}));
    assert(tensor_a.dim() == 4);
    assert(tensor_a.shape() == shape_t({2, 2, 5, 7}));

    tensor_a.reshape(shape_t({4, 7}));
    assert(tensor_a.dim() == 3);
    assert(tensor_a.shape() == shape_t({4, 7, 5}));

    tensor_a.reshape(shape_t({5, 7, 4}));
    assert(tensor_a.dim() == 3);
    assert(tensor_a.shape() == shape_t({5, 7, 4}));
}

void tensor_test()
{
    INFO("run tensor test");
    test_tensor_construct();
    test_tensor_calculate();
    test_tensor_interface();
}
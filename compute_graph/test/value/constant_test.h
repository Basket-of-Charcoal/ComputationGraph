#pragma once

#include "src/base/graph.h"
#include "src/operation/operation_add.h"
#include "src/util/log.h"
#include "src/value/constant.h"

namespace compute_graph
{
    void test_constant_construct()
    {
        Tensor t = Tensor(shape_t({5, 7}), 0.7f);
        Constant c = Constant(t);

        assert(c.compute() == t);

        Constant c_1 = Constant(shape_t({5, 7}), 0.7f);
        assert(c_1.compute() == t);
        assert(c_1.compute() < Tensor(shape_t({5, 7}), 0.9f));
    }

    void test_constant_calculate()
    {
        Constant c = Constant(shape_t({2, 2}),
                              std::vector<data_t>({0.2f, 0.5f, -1.4f, 3.3f}));
        assert(c.compute() + Tensor(shape_t({2}), 0.5) ==
               Tensor(shape_t({2, 2}), {0.7f, 1.0f, -0.9f, 3.8f}));
        Constant d = Constant(shape_t({2, 2}), 1.0f);
        OperationAdd add = OperationAdd(c, d);
        assert(add.compute() ==
               Tensor(shape_t({2, 2}), {1.2f, 1.5f, -0.4f, 4.3f}));
    }

    void constant_test()
    {
        INFO("start constant test");
        Graph graph = Graph();
        graph.as_default();

        test_constant_construct();
        test_constant_calculate();
        INFO("constant test succeed");
    }
} // namespace compute_graph
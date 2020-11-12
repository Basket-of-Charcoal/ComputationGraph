#pragma once

#include <cassert>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "src/base/graph.h"
#include "src/base/session.h"
#include "src/operation/operation_add.h"
#include "src/operation/operation_sub.h"
#include "src/placeholder/placeholder.h"
#include "src/util/log.h"
#include "src/value/constant.h"

using namespace compute_graph;

void test_placeholder_calculate()
{
    Constant w = Constant(shape_t({2, 2}),
                          std::vector<data_t>({0.2f, 0.5f, -1.4f, 3.3f}));
    Constant b = Constant(shape_t({2}),
                          std::vector<data_t>({0.5f, -0.3f}));
    Placeholder x = Placeholder("x");

    auto out = w + b - x;

    Session &sess = Session::get_instance();
    Tensor input_x = Tensor(shape_t({2}), std::vector<data_t>({0.2f, 0.4f}));
    std::map<std::string, Tensor> feed_dict = std::map<std::string, Tensor>(
        {std::make_pair("x", input_x)});

    Tensor out_t = sess.run(out, feed_dict);
    assert(out_t == Tensor(shape_t({2, 2}),
                           std::vector<data_t>({0.5f, -0.2f, -1.1f, 2.6f})));
}

void placeholder_test()
{
    INFO("start placeholder test");
    Graph graph = Graph();
    graph.as_default();

    test_placeholder_calculate();
    INFO("placeholder test succeed");
}
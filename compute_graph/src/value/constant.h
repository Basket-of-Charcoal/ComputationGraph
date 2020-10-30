#pragma once

#include "src/base/node.h"
#include "src/util/tensor.h"

namespace compute_graph
{
    class Constant : public Node
    {
        Tensor *_value;

    public:
        Constant() = delete;
        ~Constant();

        Constant(const Tensor &);
        Constant(const shape_t &, data_t);
        Constant(const shape_t &, const std::vector<data_t> &);
        Constant(const shape_t &, data_t *);

        const Tensor &compute();
    };
} // namespace compute_graph
#pragma once

#include "src/util/tensor.h"

namespace compute_graph
{
    class Node
    {
    public:
        Node() = default;
        virtual ~Node() = default;
        virtual Tensor compute();
    };
} // namespace compute_graph
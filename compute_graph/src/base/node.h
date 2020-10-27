#pragma once

#include "src/util/tensor.h"

namespace compute_graph
{
    class Graph;

    class Node
    {
    protected:
        Graph *_graph;

    public:
        Node() = default;
        virtual ~Node() = default;
        virtual Tensor compute() = 0;
    };
} // namespace compute_graph
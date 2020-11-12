#pragma once

#include "src/util/tensor.h"

namespace compute_graph
{
    class Graph;
    class OperationAdd;
    class OperationSub;

    class Node
    {
    protected:
        Graph *_graph;

    public:
        Node();
        virtual ~Node() = default;
        virtual const Tensor &compute() = 0;

        OperationAdd operator+(Node &);
        OperationSub operator-(Node &);
    };
} // namespace compute_graph
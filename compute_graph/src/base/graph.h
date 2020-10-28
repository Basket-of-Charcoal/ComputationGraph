#pragma once

#include <map>

#include "node.h"

namespace compute_graph
{
    class Graph
    {
        std::map<Node *, Tensor> _placeholders;
        std::map<Node *, Tensor> _variables;
        std::map<Node *, Tensor> _operations;

    public:
        Graph() = default;
        ~Graph() = default;
    };
} // namespace compute_graph
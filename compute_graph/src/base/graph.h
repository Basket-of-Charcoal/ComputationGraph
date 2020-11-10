#pragma once

#include <map>
#include <string>

#include "node.h"
#include "src/operation/operation.h"

namespace compute_graph
{
    class Graph
    {
        std::map<std::string, Node *> _placeholders;
        std::vector<Node *> _variables, _constants;
        std::vector<Operation *> _operations;

    public:
        Graph() = default;
        ~Graph() = default;

        void as_default();
        void reset_buff();
        void add_operation(Operation *);
    };
} // namespace compute_graph
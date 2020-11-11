#pragma once

#include <map>
#include <string>

#include "node.h"
#include "src/operation/operation.h"

namespace compute_graph
{
    class Graph
    {
        std::map<std::string, Tensor> _placeholders;
        std::vector<Node *> _variables, _constants;
        std::vector<Operation *> _operations;

    public:
        Graph() = default;
        ~Graph() = default;

        void as_default();
        void reset_buff();
        void feed_placeholder(const std::map<std::string, Tensor> &);
        void register_operation(Operation *);
        const Tensor &get_placeholder_value(const std::string &);
    };
} // namespace compute_graph
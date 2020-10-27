#pragma once

#include <vector>

#include "src/base/node.h"

namespace compute_graph
{
    class Operation : public Node
    {
    protected:
        std::vector<Node *> _input;

    public:
        Operation() = default;
        ~Operation() = default;

        virtual Tensor compute() = 0;
    };
} // namespace compute_graph
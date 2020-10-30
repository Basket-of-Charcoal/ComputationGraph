#pragma once

#include <vector>

#include "src/base/node.h"

namespace compute_graph
{
    class Operation : public Node
    {
    protected:
        std::vector<Node *> _input;
        Tensor *_value;

    public:
        Operation() = default;
        ~Operation()
        {
            delete this->_value;
        };

        virtual const Tensor &compute() = 0;
        virtual std::vector<Tensor> gradient() = 0;
    }; // namespace compute_graph
} // namespace compute_graph
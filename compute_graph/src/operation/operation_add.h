#pragma once

#include <vector>

#include "operation.h"

namespace compute_graph
{
    class OperationAdd : public Operation
    {
    public:
        OperationAdd() = delete;
        ~OperationAdd() = default;

        OperationAdd(Node &a, Node &b);

        Tensor compute();
        std::vector<Tensor> gradient();
    };
} // namespace compute_graph
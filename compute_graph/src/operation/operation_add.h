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

        const Tensor &compute() override;
        std::vector<Tensor> gradient() override;
    };
} // namespace compute_graph
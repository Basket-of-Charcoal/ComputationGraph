#pragma once

#include <vector>

#include "operation.h"

namespace compute_graph
{
    class OperationSub : public Operation
    {
    public:
        OperationSub() = delete;
        ~OperationSub() = default;

        OperationSub(Node &, Node &);

        const Tensor &compute() override;
        std::vector<Tensor> gradient() override;
    };
} // namespace compute_graph
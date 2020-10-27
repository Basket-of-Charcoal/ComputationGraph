#pragma once

#include <vector>

#include "operation.h"

namespace compute_graph
{
    class OpAdd : public Operation
    {
    public:
        OpAdd() = delete;
        ~OpAdd() = default;

        OpAdd(Node &a, Node &b);

        Tensor compute();
    };
} // namespace compute_graph
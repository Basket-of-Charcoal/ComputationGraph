#pragma once

#include "src/base/node.h"

namespace compute_graph
{
    class Placeholder : public Node
    {
    public:
        Placeholder() = default;
        ~Placeholder() = default;
        const Tensor &compute();
    };
} // namespace compute_graph
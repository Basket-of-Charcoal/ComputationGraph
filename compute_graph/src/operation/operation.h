#pragma once

namespace compute_graph
{
    class Operation
    {
    public:
        Operation() = default;
        ~Operation() = default;

        void compute();
    };
} // namespace compute_graph
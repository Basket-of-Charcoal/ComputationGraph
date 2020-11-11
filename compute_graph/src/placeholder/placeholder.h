#pragma once

#include "string"
#include "src/base/node.h"

namespace compute_graph
{
    class Placeholder : public Node
    {
        std::string _name;

    public:
        Placeholder() = delete;
        ~Placeholder() = default;

        Placeholder(const std::string &);
        const Tensor &compute() override;
    };
} // namespace compute_graph
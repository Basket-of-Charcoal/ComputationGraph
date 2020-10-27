#include "op_add.h"

#define FIRST 0
#define SECOND 1

namespace compute_graph
{
    OpAdd::OpAdd(Node &a, Node &b)
    {
        this->_input.push_back(a);
        this->_input.push_back(b);
    }

    Tensor OpAdd::compute()
    {
        return this->_input[FIRST].compute() + this->_input[SECOND].compute();
    }
} // namespace compute_graph
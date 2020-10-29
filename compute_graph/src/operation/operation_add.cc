#include "operation_add.h"

#define FIRST 0
#define SECOND 1

namespace compute_graph
{
    OperationAdd::OperationAdd(Node &a, Node &b)
    {
        this->_input.push_back(&a);
        this->_input.push_back(&b);
    }

    Tensor OperationAdd::compute()
    {
        return this->_input[FIRST]->compute() + this->_input[SECOND]->compute();
    }

    std::vector<Tensor> OperationAdd::gradient()
    {
        return std::vector<Tensor>();
    }
} // namespace compute_graph
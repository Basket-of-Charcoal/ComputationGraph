#include "operation_sub.h"
#include "src/util/log.h"

#define FIRST 0
#define SECOND 1

namespace compute_graph
{
    OperationSub::OperationSub(Node &a, Node &b)
    {
        this->_value = NULL;
        this->_input.push_back(&a);
        this->_input.push_back(&b);
    }

    const Tensor &OperationSub::compute()
    {
        delete this->_value;
        this->_value = new Tensor(this->_input[FIRST]->compute() - this->_input[SECOND]->compute());
        return *this->_value;
    }

    std::vector<Tensor> OperationSub::gradient()
    {
        return std::vector<Tensor>();
    }
} // namespace compute_graph
#include "operation_add.h"
#include "src/util/log.h"

#define FIRST 0
#define SECOND 1

namespace compute_graph
{
    OperationAdd::OperationAdd(Node &a, Node &b)
    {
        this->_input.push_back(&a);
        this->_input.push_back(&b);
    }

    const Tensor &OperationAdd::compute()
    {
        INFO("befor");
        delete this->_value;
        INFO("befor_");
        this->_value = new Tensor(this->_input[FIRST]->compute() + this->_input[SECOND]->compute());
        return *this->_value;
        INFO("after");
    }

    std::vector<Tensor> OperationAdd::gradient()
    {
        return std::vector<Tensor>();
    }
} // namespace compute_graph
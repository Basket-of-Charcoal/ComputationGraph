#include "node.h"
#include "src/base/session.h"
#include "src/operation/operation_add.h"
#include "src/operation/operation_sub.h"

namespace compute_graph
{
    Node::Node()
    {
        this->_graph = &Session::get_graph();
    }

    OperationAdd Node::operator+(Node &other)
    {
        return OperationAdd(*this, other);
    }

    OperationSub Node::operator-(Node &other)
    {
        return OperationSub(*this, other);
    }
} // namespace compute_graph
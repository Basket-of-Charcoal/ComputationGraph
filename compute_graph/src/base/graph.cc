#include "graph.h"
#include "session.h"
#include "src/operation/operation.h"

namespace compute_graph
{
    void Graph::as_default()
    {
        Session::set_default_graph(this);
    }

    void Graph::reset_buff()
    {
        for (Operation *op : this->_operations)
        {
            op->reset_buff();
        }
    }

    void Graph::add_operation(Operation *op)
    {
        this->_operations.push_back(op);
    }
} // namespace compute_graph

#include "node.h"
#include "src/base/session.h"

namespace compute_graph
{
    Node::Node()
    {
        this->_graph = &Session::get_graph();
    }
} // namespace compute_graph
#include "placeholder.h"
#include "src/base/graph.h"

namespace compute_graph
{
    Placeholder::Placeholder(const std::string &name)
    {
        this->_name = std::string(name);
    }

    const Tensor &Placeholder::compute()
    {
        return this->_graph->get_placeholder_value(this->_name);
    }
} // namespace compute_graph
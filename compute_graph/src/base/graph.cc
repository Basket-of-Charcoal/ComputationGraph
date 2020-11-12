#include "graph.h"
#include "session.h"
#include "src/base/status.h"
#include "src/operation/operation.h"
#include "src/util/log.h"

namespace compute_graph
{
    Graph::~Graph()
    {
        Session::set_default_graph(NULL);
    }

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

    void Graph::feed_placeholder(const std::map<std::string, Tensor> &feed_dict)
    {
        // make a copy from param to prevent temporary variables from being released
        this->_placeholders = std::map<std::string, Tensor>(feed_dict);
    }

    void Graph::register_operation(Operation *op)
    {
        this->_operations.push_back(op);
    }

    const Tensor &Graph::get_placeholder_value(const std::string &name)
    {
        auto iter = this->_placeholders.find(name);
        if (iter == this->_placeholders.end())
        {
            ERROR("key \"%s\" can not be find in feed_dict.", name.c_str());
            exit(FAILURE);
        }
        return iter->second;
    }
} // namespace compute_graph

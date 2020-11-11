#include "operation.h"
#include "src/base/session.h"

namespace compute_graph
{
    Operation::Operation()
    {
        Session::get_instance().get_graph().register_operation(this);
    }

    Operation::~Operation()
    {
        delete this->_value;
    }

    void Operation::reset_buff()
    {
        delete this->_value;
        this->_value = NULL;
    }
} // namespace compute_graph
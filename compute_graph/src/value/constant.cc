#include "constant.h"

namespace compute_graph
{
    Constant::~Constant()
    {
        delete this->_value;
    }

    Constant::Constant(const Tensor &other)
    {
        this->_value = new Tensor(other);
    }

    Constant::Constant(const shape_t &shape, data_t data)
    {
        this->_value = new Tensor(shape, data);
    }

    Constant::Constant(const shape_t &shape, const std::vector<data_t> &data)
    {
        this->_value = new Tensor(shape, data);
    }

    Constant::Constant(const shape_t &shape, data_t *data)
    {
        this->_value = new Tensor(shape, data);
    }

    const Tensor &Constant::compute()
    {
        return *this->_value;
    }
} // namespace compute_graph
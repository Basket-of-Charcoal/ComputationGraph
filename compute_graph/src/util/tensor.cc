#include "tensor.h"
#include "src/util/log.h"

namespace compute_graph
{
    int Tensor::allocate()
    {
        size_t size = total_size();
        try
        {
            _data = new DTYPE[size];
        }
        catch (std::exception &e)
        {
            ERROR("failed allocate memory bacause %s", e.what());
            return FAILURE;
        }
        return SUCCEED;
    }

    int Tensor::total_size()
    {
        size_t ret = 1;
        for (size_t dim : _shape)
        {
            ret *= dim;
        }
        return ret;
    }

    Tensor::Tensor(std::vector<size_t> dim)
    {
        this->_shape = std::vector<size_t>(dim);
        allocate();
    }
} // namespace compute_graph
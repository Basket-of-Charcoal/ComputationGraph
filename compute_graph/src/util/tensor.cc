#include <random>

#include "expr.h"
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

    size_t cal_total_size(std::vector<size_t> shape)
    {
        size_t ret = 1;
        for (size_t dim : shape)
        {
            ret *= dim;
        }
        return ret;
    }

    size_t Tensor::total_size()
    {
        return cal_total_size(this->_shape);
    }

    Tensor::Tensor(std::vector<size_t> shape)
    {
        this->_shape = std::vector<size_t>(shape);
        allocate();

        std::default_random_engine e;
        std::uniform_real_distribution<DTYPE> u(0.0, 1.0);
        size_t total_sz = total_size();
        for (int i = 0; i < total_sz; i++)
        {
            this->_data[i] = u(e);
        }
    }

    Tensor::Tensor(std::vector<size_t> shape, DTYPE data)
    {
        this->_shape = std::vector<size_t>(shape);
        allocate();

        size_t total_sz = total_size();
        for (int i = 0; i < total_sz; i++)
        {
            this->_data[i] = data;
        }
    }

    Tensor::Tensor(std::vector<size_t> shape, std::vector<DTYPE> data)
    {
        size_t total_sz = total_size();
        size_t data_sz = data.size();
        if (!data_sz || total_sz % data_sz)
        {
            ERROR("tensor shape %s cannot be divisiable by data size %ul",
                  to_str(shape).c_str(), data_sz);
        }

        this->_shape = std::vector<size_t>(shape);
        allocate();

        for (int i = 0; i < total_sz; i++)
        {
            this->_data[i] = data[i % data_sz];
        }
    }

    Tensor::Tensor(std::vector<size_t> shape, DTYPE *data)
    {
        this->_shape = std::vector<size_t>(shape);
        allocate();

        size_t total_sz = total_size();
        for (int i = 0; i < total_sz; i++)
        {
            this->_data[i] = data[i];
        }
    }

    size_t Tensor::dim()
    {
        return this->_shape.size();
    }

    std::vector<size_t> Tensor::shape()
    {
        return this->_shape;
    }

    void Tensor::reshape(std::vector<size_t> new_shape)
    {
        size_t new_total_sz = cal_total_size(new_shape);
        size_t total_sz = total_size();

        if (!new_total_sz || total_sz % new_total_sz)
        {
            ERROR("tensor shape %s cannot be convert by data shape %s",
                  to_str(new_shape).c_str(), to_str(this->_shape).c_str());
        }

        this->_shape = std::vector<size_t>(new_shape);
    }

} // namespace compute_graph
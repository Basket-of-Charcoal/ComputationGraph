#include <cstring>
#include <random>

#include "expr.h"
#include "tensor.h"
#include "scalar.h"
#include "src/util/log.h"

namespace compute_graph
{
    int Tensor::allocate()
    {
        size_t size = total_size();
        try
        {
            _data = new data_t[size];
        }
        catch (std::exception &e)
        {
            ERROR("failed allocate memory bacause %s", e.what());
            return FAILURE;
        }
        return SUCCEED;
    }

    size_t Tensor::total_size() const
    {
        return cal_total_size(this->_shape);
    }

    size_t Tensor::cal_total_size(const shape_t &shape) const
    {
        size_t ret = 1;
        for (size_t dim : shape)
        {
            ret *= dim;
        }
        return ret;
    }

    Tensor::Tensor(const Tensor &other)
    {
        this->_shape = shape_t(other._shape);
        allocate();
        memcpy(this->_data, other._data, total_size() * sizeof(data_t));
    }

    Tensor::Tensor(shape_t shape)
    {
        this->_shape = shape_t(shape);
        allocate();

        std::default_random_engine e;
        std::uniform_real_distribution<data_t> u(0.0, 1.0);
        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            this->_data[i] = u(e);
        }
    }

    Tensor::Tensor(shape_t shape, data_t data)
    {
        this->_shape = shape_t(shape);
        allocate();

        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            this->_data[i] = data;
        }
    }

    Tensor::Tensor(shape_t shape, std::vector<data_t> data)
    {
        size_t total_sz = cal_total_size(shape);
        size_t data_sz = data.size();
        if ((!data_sz) || total_sz % data_sz)
        {
            ERROR("tensor shape %s cannot be divisiable by data size %zu",
                  to_str(shape).c_str(), data_sz);
            exit(FAILURE);
        }

        this->_shape = shape_t(shape);
        allocate();

        for (size_t i = 0; i < total_sz; i++)
        {
            this->_data[i] = data[i % data_sz];
        }
    }

    Tensor::Tensor(shape_t shape, data_t *data)
    {
        this->_shape = shape_t(shape);
        allocate();

        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            this->_data[i] = data[i];
        }
    }

    size_t Tensor::dim() const
    {
        return this->_shape.size();
    }

    shape_t Tensor::shape() const
    {
        return this->_shape;
    }

    void Tensor::reshape(const shape_t &new_shape)
    {
        if (!multiple_shape(this->_shape, new_shape))
        {
            ERROR("tensor shape %s cannot be convert by data shape %s",
                  to_str(new_shape).c_str(), to_str(this->_shape).c_str());
            exit(FAILURE);
        }

        // automatically deduce the size of the last dimension
        size_t multiple = total_size() / cal_total_size(new_shape);
        this->_shape = shape_t(new_shape);
        if (multiple != 1)
        {
            this->_shape.push_back(multiple);
        }
    }

    std::string Tensor::expr() const
    {
        return "Tensor" + to_str(_shape);
    }

    bool Tensor::same_shape(const Tensor &a, const Tensor &b) const
    {
        return same_shape(a._shape, b._shape);
    }

    bool Tensor::same_shape(const shape_t &a, const shape_t &b) const
    {
        if (a.size() != b.size())
        {
            return false;
        }
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
        return true;
    }

    bool Tensor::multiple_shape(const Tensor &a, const Tensor &b) const
    {
        return multiple_shape(a._shape, b._shape);
    }

    bool Tensor::multiple_shape(const shape_t &a, const shape_t &b) const
    {
        size_t total_sz_a = cal_total_size(a);
        size_t total_sz_b = cal_total_size(b);

        if ((!total_sz_a) || (!total_sz_b) || (total_sz_a % total_sz_b))
        {
            return false;
        }
        return true;
    }

    bool Tensor::operator<(const Tensor &other) const
    {
        if (!same_shape(*this, other))
        {
            ERROR("can not compare tensor with different shape %s, %s",
                  to_str(this->_shape).c_str(), to_str(other._shape).c_str());
            exit(FAILURE);
        }
        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            if (!float_equals(this->_data[i], other._data[i]))
            {
                return this->_data[i] < other._data[i];
            }
        }
        return false;
    }

    bool Tensor::operator==(const Tensor &other) const
    {
        if (!same_shape(*this, other))
        {
            ERROR("can not compare tensor with different shape %s, %s",
                  to_str(this->_shape).c_str(), to_str(other._shape).c_str());
            exit(FAILURE);
        }
        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            if (!float_equals(this->_data[i], other._data[i]))
            {
                return false;
            }
        }
        return true;
    }

    bool Tensor::operator!=(const Tensor &other) const
    {
        return !(*this == other);
    }

    Tensor Tensor::operator+(const Tensor &other) const
    {
        Tensor resp = Tensor(*this);
        resp += other;
        return resp;
    }

    Tensor Tensor::operator-(const Tensor &other) const
    {
        Tensor resp = Tensor(*this);
        resp -= other;
        return resp;
    }

    Tensor Tensor::operator*(const data_t &other) const
    {
        Tensor resp = Tensor(*this);
        resp *= other;
        return resp;
    }

    Tensor Tensor::operator/(const data_t &other) const
    {
        Tensor resp = Tensor(*this);
        resp /= other;
        return resp;
    }

    Tensor &Tensor::operator+=(const Tensor &other)
    {
        if (!multiple_shape(this->_shape, other._shape))
        {
            ERROR("can not add tensors with unmultiple shape %s, %s",
                  to_str(this->_shape).c_str(), to_str(other._shape).c_str());
            exit(FAILURE);
        }

        size_t total_sz_a = total_size();
        size_t total_sz_b = other.total_size();
        for (size_t i = 0; i < total_sz_a; i++)
        {
            this->_data[i] += other._data[i % total_sz_b];
        }
        return *this;
    }

    Tensor &Tensor::operator-=(const Tensor &other)
    {
        if (!multiple_shape(this->_shape, other._shape))
        {
            ERROR("can not minus tensors with unmultiple shape %s, %s",
                  to_str(this->_shape).c_str(), to_str(other._shape).c_str());
            exit(FAILURE);
        }

        size_t total_sz_a = total_size();
        size_t total_sz_b = other.total_size();
        for (size_t i = 0; i < total_sz_a; i++)
        {
            this->_data[i] -= other._data[i % total_sz_b];
        }
        return *this;
    }

    Tensor &Tensor::operator*=(const data_t &other)
    {
        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            this->_data[i] *= other;
        }
        return *this;
    }

    Tensor &Tensor::operator/=(const data_t &other)
    {
        size_t total_sz = total_size();
        for (size_t i = 0; i < total_sz; i++)
        {
            this->_data[i] /= other;
        }
        return *this;
    }
} // namespace compute_graph
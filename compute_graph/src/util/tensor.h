#pragma once

#include <vector>
#include <string>

#include "src/base/status.h"

namespace compute_graph
{
    typedef float data_t;
    typedef std::vector<size_t> shape_t;

    class Tensor
    {
        shape_t _shape;
        data_t *_data;

        // allocate memory according to _shape
        int allocate();

        // total data size ()
        size_t total_size() const;
        size_t cal_total_size(const shape_t &) const;

        // Tensor a with same shape of b
        bool same_shape(const Tensor &, const Tensor &) const;
        bool same_shape(const shape_t &, const shape_t &) const;

        // Tensor a's shape is an integral multiple of b's
        bool multiple_shape(const Tensor &, const Tensor &) const;
        bool multiple_shape(const shape_t &, const shape_t &) const;

    public:
        // disable default constructor
        Tensor() = delete;
        ~Tensor() = default;

        Tensor(const Tensor &);
        Tensor(shape_t);
        Tensor(shape_t, data_t);
        Tensor(shape_t, std::vector<data_t>);
        Tensor(shape_t, data_t *);

        size_t dim() const;
        shape_t shape() const;
        void reshape(const shape_t &);
        std::string expr() const;

        bool operator<(const Tensor &other) const;
        bool operator==(const Tensor &other) const;
        bool operator!=(const Tensor &other) const;
        Tensor operator+(const Tensor &other) const;
        Tensor operator-(const Tensor &other) const;
        Tensor operator*(const data_t &other) const;
        Tensor operator/(const data_t &other) const;
        Tensor &operator+=(const Tensor &other);
        Tensor &operator-=(const Tensor &other);
        Tensor &operator*=(const data_t &other);
        Tensor &operator/=(const data_t &other);
    };
} // namespace compute_graph
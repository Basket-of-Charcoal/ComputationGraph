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
        shape_t *_shape;
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
        ~Tensor();

        Tensor(const Tensor &);
        Tensor(const shape_t &);
        Tensor(const shape_t &, data_t);
        Tensor(const shape_t &, const std::vector<data_t> &);
        Tensor(const shape_t &, data_t *);

        size_t dim() const;
        const shape_t &shape() const;
        void reshape(const shape_t &);
        std::string expr() const;

        Tensor &operator=(const Tensor &);
        bool operator<(const Tensor &) const;
        bool operator==(const Tensor &) const;
        bool operator!=(const Tensor &) const;
        Tensor operator+(const Tensor &) const;
        Tensor operator-(const Tensor &) const;
        Tensor operator*(const data_t &) const;
        Tensor operator/(const data_t &) const;
        Tensor &operator+=(const Tensor &);
        Tensor &operator-=(const Tensor &);
        Tensor &operator*=(const data_t &);
        Tensor &operator/=(const data_t &);
    };
} // namespace compute_graph
#pragma once

#include <vector>

#include "src/base/status.h"

namespace compute_graph
{
    class Tensor
    {
        typedef float DTYPE;
        std::vector<size_t> _shape;
        DTYPE *_data;

        // allocate memory according to _shape
        int allocate();

        // total data size ()
        int total_size();

    public:
        // disable default constructor
        Tensor() = delete;
        ~Tensor() = default;

        Tensor(std::vector<size_t>);
        Tensor(std::vector<size_t>, DTYPE);
        Tensor(std::vector<size_t>, std::vector<DTYPE>);
        Tensor(std::vector<size_t>, DTYPE *);

        size_t dim();
        std::vector<size_t> shape();
        void reshape(std::vector<size_t>);

        bool operator<(const Tensor &other) const;
        bool operator==(const Tensor &other) const;
        Tensor operator+(const Tensor &other) const;
        Tensor operator-(const Tensor &other) const;
        Tensor operator*(const DTYPE &other) const;
        Tensor operator/(const DTYPE &other) const;
    };
} // namespace compute_graph
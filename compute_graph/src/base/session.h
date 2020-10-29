#pragma once

#include <mutex>

#include "graph.h"

namespace compute_graph
{
    class Session
    {
        static Session *_p_instance;
        static std::mutex _mtx;
        static Graph *_p_graph;
        Session() = default;

    public:
        static Session &
        get_instance();
        static void set_default_graph(Graph *);
    };
} // namespace compute_graph
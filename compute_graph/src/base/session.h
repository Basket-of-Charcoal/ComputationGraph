#pragma once

#include <map>
#include <mutex>
#include <string>

#include "graph.h"

namespace compute_graph
{
    class Session
    {
        static std::mutex _mtx;
        static Session *_p_instance;
        Graph *_p_graph;
        Session();

    public:
        static Session &
        get_instance();
        static void set_default_graph(Graph *);
        static Graph &get_graph();
        static Tensor run(Node &);
        static Tensor run(Node &, const std::map<std::string, Tensor> &);
    };
} // namespace compute_graph
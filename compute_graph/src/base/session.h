#pragma once

#include <map>
#include <mutex>
#include <string>

#include "graph.h"
#include "src/base/status.h"
#include "src/util/log.h"

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

        template <typename NodeType>
        static Tensor run(NodeType &target)
        {
            return Session::run(target, std::map<std::string, Tensor>());
        }

        template <typename NodeType>
        static Tensor run(NodeType &target, const std::map<std::string, Tensor> &feed_dict)
        {
            Session &session = Session::get_instance();
            if (session._p_graph == NULL)
            {
                ERROR("graph is not defined yet.");
                exit(FAILURE);
            }
            session._p_graph->reset_buff();
            session._p_graph->feed_placeholder(feed_dict);

            return target.compute();
        }
    };
} // namespace compute_graph
#include "session.h"
#include "src/base/status.h"
#include "src/util/log.h"

namespace compute_graph
{
    Session::Session()
    {
        this->_p_graph = NULL;
    }

    Session &
    Session::get_instance()
    {
        Session::_mtx.lock();
        if (Session::_p_instance == NULL)
        {
            Session::_p_instance = new Session();
        }
        Session::_mtx.unlock();
        return *Session::_p_instance;
    }

    void Session::set_default_graph(Graph *p_graph)
    {
        Session::get_instance()._p_graph = p_graph;
    }

    Graph &Session::get_graph()
    {
        Graph *graph = Session::get_instance()._p_graph;
        if (graph == NULL)
        {
            ERROR("graph is not defined yet.");
            exit(FAILURE);
        }
        return *graph;
    }

    Tensor Session::run(Node &target)
    {
        return Session::run(target, std::map<std::string, Tensor>());
    }

    Tensor Session::run(Node &target, const std::map<std::string, Tensor> &feed_dict)
    {
        Session &session = Session::get_instance();
        if (session._p_graph == NULL)
        {
            ERROR("graph is not defined yet.");
            exit(FAILURE);
        }
        session._p_graph->reset_buff();
        for (auto it : feed_dict)
        {
            INFO("%s", it.first.c_str());
        }

        return target.compute();
    }

    Session *Session::_p_instance = NULL;
    std::mutex Session::_mtx;
} // namespace compute_graph
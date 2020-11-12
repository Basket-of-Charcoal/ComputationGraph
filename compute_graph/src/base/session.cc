#include "session.h"

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

    Session *Session::_p_instance = NULL;
    std::mutex Session::_mtx;
} // namespace compute_graph
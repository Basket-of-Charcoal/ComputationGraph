#include "session.h"

namespace compute_graph
{
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
        Session::_p_graph = p_graph;
    }

    Session *Session::_p_instance = NULL;
    std::mutex Session::_mtx;
    Graph *Session::_p_graph = NULL;
} // namespace compute_graph
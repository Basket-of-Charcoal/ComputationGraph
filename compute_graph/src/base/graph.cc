#include "graph.h"
#include "session.h"

namespace compute_graph
{
    void Graph::as_default()
    {
        Session::get_instance().set_default_graph(this);
    }
} // namespace compute_graph

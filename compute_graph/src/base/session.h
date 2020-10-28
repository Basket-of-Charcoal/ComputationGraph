#pragma once

#include <mutex>

namespace compute_graph
{
    class Session
    {
        static Session *_p_instance;
        static std::mutex _mtx;
        Session() = default;

    public:
        static Session &
        get_instance()
        {
            Session::_mtx.lock();
            if (_p_instance == NULL)
            {
                _p_instance = new Session();
            }
            Session::_mtx.unlock();
            return *_p_instance;
        }
    };

    Session *Session::_p_instance = NULL;
    std::mutex Session::_mtx = std::mutex();
} // namespace compute_graph
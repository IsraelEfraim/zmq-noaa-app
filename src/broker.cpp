#include <zmq.hpp>

auto main() -> int {
    auto context = zmq::context_t(1);

    auto frontend = zmq::socket_t(context, zmq::socket_type::sub);
    frontend.bind("tcp://*:5559");
    frontend.setsockopt(ZMQ_SUBSCRIBE, "", 0);

    auto backend = zmq::socket_t(context, zmq::socket_type::pub);
    backend.bind("tcp://*:5560");

    zmq::proxy(zmq::socket_ref(frontend), zmq::socket_ref(backend), nullptr);

    return 0;
}

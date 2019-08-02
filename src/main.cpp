#include <iostream>

#include "actors/actors.h"
#include "actors/Inspect.hpp"

CAF_PUSH_WARNINGS
#include "test.pb.h"
#include "otherTest.h"
CAF_POP_WARNINGS

using namespace caf;
using namespace caf::io;
using namespace Protobuf;

using namespace std;
using ping_atom = atom_constant<atom("ping")>;
using pong_atom = atom_constant<atom("pong")>;



class config : public actor_system_config {
public:
    config() {
        add_message_type<Test>("Test");
//        add_message_type<OtherTest>("OtherTest"); // this is OK
    }
};

behavior pong() {
    return {
            [](ping_atom, string val) -> result<pong_atom, string> {
                cout << "ping_atom->pong_atom - " << val << endl;
                return {pong_atom::value, val};
            }
    };
}

void caf_main(actor_system &system, const config &cfg) {
    auto pong_actor = system.spawn(pong);
    string dummy;
    std::getline(std::cin, dummy);
    cout << "... cya" << endl;
    anon_send_exit(pong_actor, exit_reason::user_shutdown);
}

CAF_MAIN(io::middleman)

#pragma once

#include "actors.h"
#include <utility>
#include <string>
#include "test.pb.h"
#include "otherTest.h"

// A lightweight scope guard implementation.
template <class Fun>
class scope_guard {
public:
    scope_guard(Fun f) : fun_(std::move(f)), enabled_(true) { }

    scope_guard(scope_guard&& x) : fun_(std::move(x.fun_)), enabled_(x.enabled_) {
        x.enabled_ = false;
    }

    ~scope_guard() {
        if (enabled_) fun_();
    }

private:
    Fun fun_;
    bool enabled_;
};

// Creates a guard that executes `f` as soon as it goes out of scope.
template <class Fun>
scope_guard<Fun> make_scope_guard(Fun f) {
    return {std::move(f)};
}

template <class Inspector>
typename std::enable_if<Inspector::reads_state, typename Inspector::result_type>::type
inspect(Inspector& f, Protobuf::Test& x) {
    return f(caf::meta::type_name("Test"), x.uid());
}

template <class Inspector>
typename std::enable_if<Inspector::writes_state, typename Inspector::result_type>::type
inspect(Inspector& f, Protobuf::Test& x) {
    std::string uid;
    auto g = make_scope_guard([&] {
        x.set_uid(uid);
    });
    return f(caf::meta::type_name("Test"), uid);
}

template <class Inspector>
typename Inspector::result_type
inspect(Inspector& f, OtherTest& x) {
    return f(caf::meta::type_name("OtherTest"), x.uid);
}
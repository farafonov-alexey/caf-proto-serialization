cmake_minimum_required(VERSION 3.2)
project(proto_caf_serial C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CAF_ROOT_DIR ${PROJECT_SOURCE_DIR}/modules/actor-framework)
set(CMAKE_PREFIX_PATH  "$ENV{PROTOBUF_DIR_${ARCH}}" "${CMAKE_PREFIX_PATH}" )

find_package(CAF COMPONENTS core io REQUIRED)
find_package(Protobuf REQUIRED)

include_directories(${CAF_INCLUDE_DIRS} ${Protobuf_INCLUDE_DIR})
add_compile_definitions(UNICODE _UNICODE)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS test.proto)

include(ProtoCAF)

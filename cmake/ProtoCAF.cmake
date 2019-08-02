set(PROTO_CAF proto_caf_serial)

set(SOURCE_FILES
        actors/Inspect.hpp
        main.cpp
        )

add_executable(proto_caf_serial ${SOURCE_FILES} ${PROTO_SRCS} ${PROTO_HDRS})

message("PROTO_SRCS = ${PROTO_SRCS}")
message("CAF_LIBRARY_CORE = ${CAF_LIBRARY_CORE}")
message("CAF_LIBRARY_IO = ${CAF_LIBRARY_IO}")
message("Protobuf_INCLUDE_DIR = ${Protobuf_INCLUDE_DIR}")
message("Protobuf_LIBRARIES = ${Protobuf_LIBRARIES}")

target_link_libraries(
        proto_caf_serial
        ${CAF_LIBRARY_IO}
        ${CAF_LIBRARY_CORE}
        ${Protobuf_LIBRARIES}
        -liphlpapi
        -lpsapi
        -lWs2_32
        -static-libstdc++
        -static-libgcc
        -static -lpthread
        )

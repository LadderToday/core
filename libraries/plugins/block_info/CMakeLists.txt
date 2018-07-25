file(GLOB HEADERS "include/core/plugins/block_info/*.hpp")

add_library( core_block_info
             ${HEADERS}
             block_info_plugin.cpp
             block_info_api.cpp
           )

target_link_libraries( core_block_info core_app core_chain core_protocol fc )
target_include_directories( core_block_info
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

file(GLOB HEADERS "include/core/plugins/debug_node/*.hpp")

add_library( core_debug_node
             ${HEADERS}
             debug_node_plugin.cpp
             debug_node_api.cpp
           )

target_link_libraries( core_debug_node core_app core_chain core_protocol fc )
target_include_directories( core_debug_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS core_debug_node
         RUNTIME DESTINATION bin
         LIBRARY DESTINATION lib
         ARCHIVE DESTINATION lib
       )
INSTALL( FILES ${HEADERS} DESTINATION "include/core/plugins/debug_node" )

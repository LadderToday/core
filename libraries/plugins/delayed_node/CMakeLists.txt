file(GLOB HEADERS "include/core/delayed_node/*.hpp")

add_library( core_delayed_node
             delayed_node_plugin.cpp
           )

target_link_libraries( core_delayed_node core_chain core_protocol core_app )
target_include_directories( core_delayed_node
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

if(MSVC)
  set_source_files_properties( delayed_node_plugin.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   core_delayed_node

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

file(GLOB HEADERS "include/core/private_message/*.hpp")

add_library( core_private_message
             private_message_plugin.cpp
           )

target_link_libraries( core_private_message core_chain core_protocol core_app )
target_include_directories( core_private_message
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   core_private_message

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

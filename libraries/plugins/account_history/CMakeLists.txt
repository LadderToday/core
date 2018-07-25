file(GLOB HEADERS "include/core/account_history/*.hpp")

add_library( core_account_history
             account_history_plugin.cpp
           )

target_link_libraries( core_account_history core_chain core_protocol core_app )
target_include_directories( core_account_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   core_account_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

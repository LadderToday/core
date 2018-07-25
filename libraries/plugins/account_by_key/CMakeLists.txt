file(GLOB HEADERS "include/core/account_by_key/*.hpp")

add_library( core_account_by_key
             account_by_key_plugin.cpp
             account_by_key_api.cpp
           )

target_link_libraries( core_account_by_key core_chain core_protocol core_app )
target_include_directories( core_account_by_key
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   core_account_by_key

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

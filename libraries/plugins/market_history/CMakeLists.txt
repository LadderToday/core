file(GLOB HEADERS "include/core/market_history/*.hpp")

add_library( core_market_history
             market_history_plugin.cpp
             market_history_api.cpp
           )

target_link_libraries( core_market_history core_chain core_protocol core_app )
target_include_directories( core_market_history
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
   core_market_history

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)
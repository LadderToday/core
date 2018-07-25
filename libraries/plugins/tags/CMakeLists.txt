file(GLOB HEADERS "include/core/tags/*.hpp")

add_library( core_tags
             tags_plugin.cpp )

target_link_libraries( core_tags core_chain core_protocol core_app )
target_include_directories( core_tags
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
        core_tags

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

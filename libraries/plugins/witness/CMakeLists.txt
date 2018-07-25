file(GLOB HEADERS "include/core/witness/*.hpp")

add_library( core_witness
             witness_plugin.cpp
             witness_evaluators.cpp
             witness_operations.cpp
           )

target_link_libraries( core_witness core_chain core_protocol core_app )
target_include_directories( core_witness
                            PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

install( TARGETS
        core_witness

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

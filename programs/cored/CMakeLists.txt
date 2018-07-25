add_executable( cored main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling cored with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( CORE_STATIC_BUILD )
   target_link_libraries( cored PRIVATE
      "-static-libstdc++ -static-libgcc"
      core_plugins
      core_mf_plugins
      core_app
      core_witness
      core_account_history
      core_chain
      core_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
else( CORE_STATIC_BUILD )
   target_link_libraries( cored PRIVATE
      core_plugins
      core_mf_plugins
      core_app
      core_witness
      core_account_history
      core_chain
      core_protocol
      fc
      ${CMAKE_DL_LIBS}
      ${PLATFORM_SPECIFIC_LIBS}
   )
endif( CORE_STATIC_BUILD )

install( TARGETS
        cored

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

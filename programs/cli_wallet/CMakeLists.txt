add_executable( cli_wallet main.cpp )
if( UNIX AND NOT APPLE )
  set(rt_library rt )
endif()

find_package( Gperftools QUIET )
if( GPERFTOOLS_FOUND )
    message( STATUS "Found gperftools; compiling cli_wallet with TCMalloc")
    list( APPEND PLATFORM_SPECIFIC_LIBS tcmalloc )
endif()

if( CORE_STATIC_BUILD )
   # I don't know why core_app is required twice in the following line, I just know the linker breaks if it isn't.
   target_link_libraries( cli_wallet PRIVATE
                          "-static-libstdc++ -static-libgcc -lreadline"
           core_app graphene_net core_chain core_protocol graphene_utilities core_wallet core_private_message core_app core_follow fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
else( CORE_STATIC_BUILD )
   target_link_libraries( cli_wallet PRIVATE
           core_app graphene_net core_chain core_protocol graphene_utilities core_wallet core_private_message core_app core_follow fc ${CMAKE_DL_LIBS} ${PLATFORM_SPECIFIC_LIBS} )
endif( CORE_STATIC_BUILD )

if(MSVC)
  set_source_files_properties( main.cpp PROPERTIES COMPILE_FLAGS "/bigobj" )
endif(MSVC)

install( TARGETS
   cli_wallet

   RUNTIME DESTINATION bin
   LIBRARY DESTINATION lib
   ARCHIVE DESTINATION lib
)

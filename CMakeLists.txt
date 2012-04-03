CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

SET( LIB_NAME YAPOG )
SET( CLIENT_NAME YAPOG.Client )
SET( SERVER_NAME YAPOG.Server )

SET( BIN_PATH bin )

if( WINDOWS )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

if( UNIX )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall" )
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb" )
        endif()
endif()

SET( sfml_include_dir "" CACHE STRING "SFML include directory." )
SET( sfml_lib_dir "" CACHE STRING "SFML lib directory." )

SET( sfml_system_lib_debug_name sfml-system-d )
SET( sfml_window_lib_debug_name sfml-window-d )
SET( sfml_graphics_lib_debug_name sfml-graphics-d )
SET( sfml_network_lib_debug_name sfml-network-d )
SET( sfml_audio_lib_debug_name sfml-audio-d )

SET( sfml_system_lib_release_name sfml-system )
SET( sfml_window_lib_release_name sfml-window )
SET( sfml_graphics_lib_release_name sfml-graphics )
SET( sfml_network_lib_release_name sfml-network )
SET( sfml_audio_lib_release_name sfml-audio )

SET( boost_include_dir "" CACHE STRING "Boost include directory." )
SET( boost_lib_dir "" CACHE STRING "Boost lib directory." )

SET( boost_signals_lib_debug_name "boost_signals" CACHE STRING "Boost signals lib debug." )
SET( boost_date_time_lib_debug_name "boost_date_time" CACHE STRING "Boost date_time lib debug." )

SET( boost_signals_lib_release_name "boost_signals" CACHE STRING "Boost signals lib release." )
SET( boost_date_time_lib_release_name "boost_date_time" CACHE STRING "Boost date_time lib release." )

SET( sfml_system_lib debug ${sfml_system_lib_debug_name} optimized ${sfml_system_lib_release_name} )
SET( sfml_window_lib debug ${sfml_window_lib_debug_name} optimized ${sfml_window_lib_release_name} )
SET( sfml_graphics_lib debug ${sfml_graphics_lib_debug_name} optimized ${sfml_graphics_lib_release_name} )
SET( sfml_network_lib debug ${sfml_network_lib_debug_name} optimized ${sfml_network_lib_release_name} )
SET( sfml_audio_lib debug ${sfml_audio_lib_debug_name} optimized ${sfml_audio_lib_release_name} )
SET( boost_signals_lib debug ${boost_signals_lib_debug_name} optimized ${boost_signals_lib_release_name} )
SET( boost_date_time_lib debug ${boost_date_time_lib_debug_name} optimized ${boost_date_time_lib_release_name} )
SET(
        link_lib
        ${sfml_system_lib}
        ${sfml_window_lib}
        ${sfml_graphics_lib}
        ${sfml_network_lib}
        ${sfml_audio_lib}
        ${boost_signals_lib}
        ${boost_date_time_lib}
)

ADD_SUBDIRECTORY( YAPOG )
ADD_SUBDIRECTORY( YAPOG.Client )
ADD_SUBDIRECTORY( YAPOG.Server )
ADD_SUBDIRECTORY( YAPOG.Test )

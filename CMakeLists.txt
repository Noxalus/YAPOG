CMAKE_MINIMUM_REQUIRED( VERSION 2.6 )

# projects name
SET( LIB_NAME YAPOG )
SET( CLIENT_NAME YAPOG.Client )
SET( SERVER_NAME YAPOG.Server )

SET( BIN_PATH bin )

# additional flags
if( WIN32 )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /EHsc" )
endif()

if( UNIX )
    SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++0x -Wall" )
    if( CMAKE_BUILD_TYPE STREQUAL "Debug" )
        SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -ggdb" )
	endif()
endif()

# external libs
if( WIN32 )
    SET( EXT_LIB_DIR
    	"${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/sfml2/Debug" #SFML debug lib directory.
        	"${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/sfml2/Release" #SFML release lib directory.
                	"${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/postgresql" #PostgreSQL lib directory.
                        	"${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/boost_1_49_0/Debug" #Boost debug lib directory.
                                	"${CMAKE_SOURCE_DIR}/extlibs/libs-msvc/x86/boost_1_49_0/Release"  #Boost release lib directory.
)

SET( EXT_INCLUDE_DIR
     "${CMAKE_SOURCE_DIR}/extlibs/headers/sfml2" #SFML include directory.
     "${CMAKE_SOURCE_DIR}/extlibs/headers/postgresql" #PostgreSQL include directory.
     "${CMAKE_SOURCE_DIR}/extlibs/headers/boost_1_49_0" #Boost include directory.
)

endif()

if( UNIX )
    SET( EXT_LIB_DIR ${CMAKE_SOURCE_DIR}/extlibs/libs-unix/sfml2/release )
    SET( EXT_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/extlibs/headers/sfml2 )
endif()

if( WIN32 )
	SET( boost_signals_lib_debug_name libboost_signals-vc110-mt-gd-1_49 )
	SET( boost_date_time_lib_debug_name libboost_date_time-vc110-mt-gd-1_49 )

	SET( boost_signals_lib_release_name libboost_signals-vc110-mt-1_49 )
	SET( boost_date_time_lib_release_name libboost_date_time-vc110-mt-1_49 )

    SET( pgsql_lib debug libpq optimized libpq )
endif()

if( UNIX )
	SET( boost_signals_lib_debug_name "boost_signals" CACHE STRING "Boost signals lib debug." )
	SET( boost_date_time_lib_debug_name "boost_date_time" CACHE STRING "Boost date_time lib debug." )

	SET( boost_signals_lib_release_name "boost_signals" CACHE STRING "Boost signals lib release." )
	SET( boost_date_time_lib_release_name "boost_date_time" CACHE STRING "Boost date_time lib release." )

	SET( pgsql_lib debug pq optimized pq )
endif()

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
	${pgsql_lib}
)

ADD_SUBDIRECTORY( YAPOG )
ADD_SUBDIRECTORY( YAPOG.Client )
ADD_SUBDIRECTORY( YAPOG.Server )
ADD_SUBDIRECTORY( YAPOG.Test )

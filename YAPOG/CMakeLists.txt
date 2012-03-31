PROJECT( ${LIB_NAME} )

SET( LIBRARY_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

SET( sfml_include_dir "" CACHE STRING "SFML include directory.")
SET( sfml_lib_dir "" CACHE STRING "SFML lib directory.")

SET( boost_signals_lib_name boost_signals )
SET( boost_date_time_lib_name boost_date_time )

SET( sfml_system_lib_name sfml-system )
SET( sfml_window_lib_name sfml-window )
SET( sfml_graphics_lib_name sfml-graphics )
SET( sfml_network_lib_name sfml-network )
SET( sfml_audio_lib_name sfml-audio )

INCLUDE_DIRECTORIES(
        include
        ${sfml_include_dir}
        ${boost_include_dir}
)

LINK_DIRECTORIES(
        ${sfml_lib_dir}
        ${boost_lib_dir}
)

FILE(
        GLOB_RECURSE
        source_files
        src/${PROJECT_NAME}/*
        include/${PROJECT_NAME}/*
)

ADD_LIBRARY(
        ${PROJECT_NAME}
        SHARED
        ${source_files}
)

TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        ${sfml_system_lib_name}
        ${sfml_window_lib_name}
        ${sfml_graphics_lib_name}
        ${sfml_network_lib_name}
        ${sfml_audio_lib_name}
        ${boost_signals_lib_name}
        ${boost_date_time_lib_name}
)

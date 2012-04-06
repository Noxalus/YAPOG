PROJECT( ${SERVER_NAME} )

SET( EXECUTABLE_OUTPUT_PATH ${BIN_PATH}/${CMAKE_BUILD_TYPE} )

INCLUDE_DIRECTORIES(
        include
        ${sfml_include_dir}
        ${boost_include_dir}
		${pgsql_include_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/include
)

LINK_DIRECTORIES(
        ${sfml_lib_dir}
        ${boost_lib_dir}
		${pgsql_lib_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/${BIN_PATH}
)

FILE(
        GLOB_RECURSE
        source_files
        src/*
        include/*
)

ADD_EXECUTABLE(
        ${PROJECT_NAME}
        ${source_files}
)

TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        ${link_lib}
        ${LIB_NAME}
)

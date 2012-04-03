PROJECT( ${LIB_NAME} )

SET( LIBRARY_OUTPUT_PATH ${BIN_PATH}/${CMAKE_BUILD_TYPE} )

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
        ${link_lib}
)

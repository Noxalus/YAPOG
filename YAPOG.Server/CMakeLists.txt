PROJECT( YAPOG.Server )

SET( LIB_NAME YAPOG )
SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

INCLUDE_DIRECTORIES(
        include
        ${sfml_include_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/include
)

INCLUDE_DIRECTORIES(
        include
        ${sfml_include_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/include
)

LINK_DIRECTORIES(
        ${sfml_lib_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/bin
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
        ${LIB_NAME}
)

PROJECT( YAPOG.Lib )

SET( LIBRARY_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

INCLUDE_DIRECTORIES( include )

FILE(
        GLOB_RECURSE
        source_files
        src/*
        include/*
)

ADD_LIBRARY(
        ${PROJECT_NAME}
        SHARED
        ${source_files}
)

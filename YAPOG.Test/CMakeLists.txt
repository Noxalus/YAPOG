macro( gen_test target )

PROJECT( ${target} )

SET( EXECUTABLE_OUTPUT_PATH bin/${CMAKE_BUILD_TYPE} )

INCLUDE_DIRECTORIES(
        include
        ${sfml_include_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/include
)

LINK_DIRECTORIES(
        ${sfml_lib_dir}
        ${CMAKE_SOURCE_DIR}/${LIB_NAME}/bin
)

ADD_EXECUTABLE(
        ${PROJECT_NAME}
        ${PROJECT_NAME}.cpp
)

TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        ${LIB_NAME}
)

endmacro()

gen_test( test_array )
gen_test( test_list )
gen_test( test_map )

macro( gen_test target )

PROJECT( ${target} )

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

ADD_EXECUTABLE(
        ${PROJECT_NAME}
        ${PROJECT_NAME}.cpp
)

TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        ${link_lib}
        ${LIB_NAME}
)

endmacro()

gen_test( test_array )
gen_test( test_list )
gen_test( test_map )
gen_test( test_xml )
gen_test( test_db )
gen_test( test_timer )

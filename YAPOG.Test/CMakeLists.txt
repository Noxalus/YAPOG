macro( gen_test target )

PROJECT( ${target} )

SET( EXECUTABLE_OUTPUT_PATH ${BIN_PATH}/${CMAKE_BUILD_TYPE} )

INCLUDE_DIRECTORIES(
	include
	${EXT_INCLUDE_DIR}
	${CMAKE_SOURCE_DIR}/${LIB_NAME}/include
)

LINK_DIRECTORIES(
	${EXT_LIB_DIR}
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
gen_test( test_chat )
gen_test( test_filechecker )
gen_test( test_list )
gen_test( test_map )
gen_test( test_xml )
gen_test( test_db )
gen_test( test_timer )
gen_test( test_sprite )
gen_test( test_audio )
gen_test( test_pokemon )
gen_test( test_pokemon_type )
gen_test( test_pokemon_battle )

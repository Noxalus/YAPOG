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

if( WIN32 )
#Replace / by \ for the source path
STRING(
	REGEX
	REPLACE
	"/"
	"\\\\"
	CMAKE_SOURCE_DIR_VS
	"${CMAKE_SOURCE_DIR}"
)

ADD_CUSTOM_COMMAND(
	TARGET
	${PROJECT_NAME}
	PRE_BUILD
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\sfml2\\\$\(Configuration\) \$\(OutDir\)
	COMMENT "Copy the SFML2 DLL files in the good directory !"
)

ADD_CUSTOM_COMMAND(
	TARGET
	${PROJECT_NAME}
	PRE_BUILD
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\postgresql \$\(OutDir\)
	COMMENT "Copy the SFML2 DLL files in the good directory !"
)
endif()

endmacro()

gen_test( test_array )
gen_test( test_list )
gen_test( test_map )
gen_test( test_xml )
gen_test( test_db )
gen_test( test_timer )
gen_test( test_sprite )
gen_test( test_audio )
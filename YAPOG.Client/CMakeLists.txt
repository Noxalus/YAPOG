PROJECT( ${CLIENT_NAME} )

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
	COMMAND xcopy ARGS /s ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\sfml2\\\$\(Configuration\) \$\(OutDir\)
	COMMENT "Copy the SFML2 DLL files in the good directory !"
)
endif()

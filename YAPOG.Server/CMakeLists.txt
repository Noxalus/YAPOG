PROJECT( ${SERVER_NAME} )

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

SET( inc_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include )
SET( src_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src )
SET(
source_files
${inc_root}/tmp/Server.hpp
${src_root}/tmp/Server.cpp
${inc_root}/Database/IInsertTable.hpp
${inc_root}/Database/Tables/InsertAccount.hpp
${src_root}/Database/Tables/InsertAccount.cpp
${inc_root}/Database/Tables/SelectAccount.hpp
${src_root}/Database/Tables/SelectAccount.cpp
${inc_root}/Account/AccountManager.hpp
${src_root}/Account/AccountManager.cpp
${inc_root}/Account/AccountPermission.hpp
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

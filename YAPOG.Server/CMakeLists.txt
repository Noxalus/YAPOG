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
${src_root}/Server.cpp
${inc_root}/Server/Server.hpp
${src_root}/Server/Server.cpp
${inc_root}/Server/ClientSession.hpp
${src_root}/Server/ClientSession.cpp
${inc_root}/Database/IInsertTable.hpp
${inc_root}/Database/Tables/InsertAccount.hpp
${src_root}/Database/Tables/InsertAccount.cpp
${inc_root}/Database/Tables/SelectAccount.hpp
${src_root}/Database/Tables/SelectAccount.cpp
${inc_root}/Account/AccountManager.hpp
${src_root}/Account/AccountManager.cpp
${inc_root}/Account/AccountPermission.hpp
${inc_root}/World/World.hpp
${src_root}/World/World.cpp
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

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
${inc_root}/Database/Tables/ITable.hpp
${inc_root}/Database/Requests/IRequest.hpp
${inc_root}/Database/Requests/Inserts/IInsertRequest.hpp
${inc_root}/Database/Requests/Selects/ISelectRequest.hpp
${inc_root}/Database/Requests/Updates/IUpdateRequest.hpp

${inc_root}/Database/Tables/AccountTable.hpp
${src_root}/Database/Tables/AccountTable.cpp
${inc_root}/Database/Tables/PlayerDataTable.hpp
${src_root}/Database/Tables/PlayerDataTable.cpp

${inc_root}/Database/Requests/Inserts/AccountInsertRequest.hpp
${src_root}/Database/Requests/Inserts/AccountInsertRequest.cpp
${inc_root}/Database/Requests/Inserts/PlayerDataInsertRequest.hpp
${src_root}/Database/Requests/Inserts/PlayerDataInsertRequest.cpp

${inc_root}/Database/Requests/Selects/AccountSelectRequest.hpp
${src_root}/Database/Requests/Selects/AccountSelectRequest.cpp
${inc_root}/Database/Requests/Selects/PlayerDataSelectRequest.hpp
${src_root}/Database/Requests/Selects/PlayerDataSelectRequest.cpp

${inc_root}/Database/Requests/Updates/AccountUpdateRequest.hpp
${src_root}/Database/Requests/Updates/AccountUpdateRequest.cpp
${inc_root}/Database/Requests/Updates/PlayerDataUpdateRequest.hpp
${src_root}/Database/Requests/Updates/PlayerDataUpdateRequest.cpp

${inc_root}/Server/Server.hpp
${src_root}/Server/Server.cpp
${inc_root}/Server/ClientManager.hpp
${src_root}/Server/ClientManager.cpp
${inc_root}/Server/ClientSession.hpp
${src_root}/Server/ClientSession.cpp
${inc_root}/Server/User.hpp
${src_root}/Server/User.cpp
${inc_root}/Account/AccountManager.hpp
${src_root}/Account/AccountManager.cpp
${inc_root}/Account/Account.hpp
${src_root}/Account/Account.cpp
${inc_root}/Account/AccountPermission.hpp

${inc_root}/World/Map/DynamicObjectFactory.hpp
${src_root}/World/Map/DynamicObjectFactory.cpp
${inc_root}/World/Map/IDGenerator.hpp
${src_root}/World/Map/IDGenerator.cpp
${inc_root}/World/World.hpp
${src_root}/World/World.cpp
${inc_root}/World/Map/Map.hpp
${src_root}/World/Map/Map.cpp
${inc_root}/World/Map/MapReader.hpp
${src_root}/World/Map/MapReader.cpp
${inc_root}/World/Map/Character.hpp
${src_root}/World/Map/Character.cpp
${inc_root}/World/Map/CharacterReader.hpp
${src_root}/World/Map/CharacterReader.cpp
${inc_root}/World/Map/NPC.hpp
${src_root}/World/Map/NPC.cpp
${inc_root}/World/Map/NPCReader.hpp
${src_root}/World/Map/NPCReader.cpp
${inc_root}/World/Map/Player.hpp
${src_root}/World/Map/Player.cpp
${inc_root}/World/Map/PlayerReader.hpp
${src_root}/World/Map/PlayerReader.cpp
${inc_root}/World/Map/Teleporter.hpp
${src_root}/World/Map/Teleporter.cpp

${inc_root}/World/Map/ServerInfoAddObjectVisitor.hpp
${src_root}/World/Map/ServerInfoAddObjectVisitor.cpp
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

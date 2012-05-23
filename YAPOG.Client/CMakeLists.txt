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

SET( inc_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include )
SET( src_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src )
SET(
source_files
${inc_root}/Battle/Battle.hpp
${src_root}/Battle/Battle.cpp
${inc_root}/Battle/BaseBattleWidget.hpp
${src_root}/Battle/BaseBattleWidget.cpp
${inc_root}/Battle/BattleBackgroundWidget.hpp
${src_root}/Battle/BattleBackgroundWidget.cpp
${inc_root}/Battle/BattleInterface.hpp
${src_root}/Battle/BattleInteface.cpp
${inc_root}/Battle/BattlePhaseManager.hpp
${src_root}/Battle/BattlePhaseManager.cpp
${inc_root}/Battle/WildBattle.hpp
${src_root}/Battle/WildBattle.cpp
${inc_root}/Battle/Phase/EndBattlePhase.hpp
${src_root}/Battle/Phase/EndBattlePhase.cpp
${inc_root}/Battle/Phase/BattlePhase.hpp
${src_root}/Battle/Phase/BattlePhase.cpp
${inc_root}/Battle/Phase/BeginBattlePhase.hpp
${src_root}/Battle/Phase/BeginBattlePhase.cpp
${inc_root}/Battle/Phase/BeginTurnPhase.hpp
${src_root}/Battle/Phase/BeginTurnPhase.cpp
${inc_root}/Battle/Phase/SelectionPhase.hpp
${src_root}/Battle/Phase/SelectionPhase.cpp
${inc_root}/Battle/Phase/ActionPhase.hpp
${src_root}/Battle/Phase/ActionPhase.cpp
${inc_root}/Battle/Phase/EndTurnPhase.hpp
${src_root}/Battle/Phase/EndTurnPhase.cpp
${inc_root}/Battle/Phase/EndBattlePhase.hpp
${src_root}/Battle/Phase/EndBattlePhase.cpp


${src_root}/Client.cpp
${inc_root}/Client/Session.hpp
${src_root}/Client/Session.cpp
${inc_root}/Client/User.hpp
${src_root}/Client/User.cpp

${inc_root}/GameInput/GameInputReader.hpp
${src_root}/GameInput/GameInputReader.cpp
${inc_root}/GameScreen/BaseScreen.hpp
${src_root}/GameScreen/BaseScreen.cpp
${inc_root}/GameScreen/LoadingScreen.hpp
${src_root}/GameScreen/LoadingScreen.cpp
${inc_root}/GameScreen/UpdateScreen.hpp
${src_root}/GameScreen/UpdateScreen.cpp
${inc_root}/GameScreen/OptionScreen.hpp
${src_root}/GameScreen/OptionScreen.cpp
${inc_root}/GameScreen/LoginScreen.hpp
${src_root}/GameScreen/LoginScreen.cpp
${inc_root}/GameScreen/GameplayScreen.hpp
${src_root}/GameScreen/GameplayScreen.cpp
${inc_root}/GameScreen/BattleScreen.hpp
${src_root}/GameScreen/BattleScreen.cpp

${inc_root}/Pokemon/Pokemon.hpp
${src_root}/Pokemon/Pokemon.cpp

${inc_root}/TestGame.hpp
${src_root}/TestGame.cpp

${inc_root}/World/Map/Character.hpp
${src_root}/World/Map/Character.cpp
${inc_root}/World/Map/CharacterReader.hpp
${src_root}/World/Map/CharacterReader.cpp
${inc_root}/World/Map/Map.hpp
${src_root}/World/Map/Map.cpp
${inc_root}/World/Map/MapReader.hpp
${src_root}/World/Map/MapReader.cpp
${inc_root}/World/Map/NPC.hpp
${src_root}/World/Map/NPC.cpp
${inc_root}/World/Map/Player.hpp
${src_root}/World/Map/Player.cpp
${inc_root}/World/Map/PlayerReader.hpp
${src_root}/World/Map/PlayerReader.cpp
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

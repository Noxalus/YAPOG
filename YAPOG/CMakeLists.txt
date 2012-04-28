PROJECT( ${LIB_NAME} )

SET( LIBRARY_OUTPUT_PATH ${BIN_PATH}/${CMAKE_BUILD_TYPE} )

INCLUDE_DIRECTORIES(
        include
        ${EXT_INCLUDE_DIR}
)

LINK_DIRECTORIES(
    ${EXT_LIB_DIR}
)

if( WIN32 )
ADD_DEFINITIONS(
	-DDLLEXPORT
)
endif()

SET( inc_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include/YAPOG )
SET( src_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/YAPOG )
SET( pgstream_inc_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/include/pgstream )
SET( pgstream_src_root ${CMAKE_SOURCE_DIR}/${PROJECT_NAME}/src/pgstream )
SET(
source_files
${inc_root}/Collection/Array.hpp
${inc_root}/Collection/Array.hxx
${inc_root}/Collection/List.hpp
${inc_root}/Collection/List.hxx
${inc_root}/Collection/Map.hpp
${inc_root}/Collection/Map.hxx
${inc_root}/Collection/Queue.hpp
${inc_root}/Collection/Queue.hxx

${inc_root}/Content/ContentManager.hpp
${src_root}/Content/ContentManager.cpp

${inc_root}/Game/Factory/ICloneable.hpp
${inc_root}/Game/Factory/ILoadable.hpp
${inc_root}/Game/Factory/IIDLoadable.hpp
${inc_root}/Game/Factory/IObjectIDLoader.hpp
${inc_root}/Game/Factory/IObjectLoader.hpp
${inc_root}/Game/Factory/ObjectFactory.hpp
${inc_root}/Game/Factory/ObjectFactory.hxx
${src_root}/Game/Factory/ObjectFactory.cpp
${inc_root}/Game/Factory/XmlObjectIDLoader.hpp
${inc_root}/Game/Factory/XmlObjectIDLoader.hxx
${inc_root}/Game/Factory/XmlObjectLoader.hpp
${inc_root}/Game/Factory/XmlObjectLoader.hxx
${inc_root}/Game/ID.hpp
${src_root}/Game/ID.cpp
${inc_root}/Game/IUpdateable.hpp
${inc_root}/Game/World/Map/Direction.hpp
${inc_root}/Game/World/Map/Map.hpp
${src_root}/Game/World/Map/Map.cpp
${inc_root}/Game/World/Map/MapReader.hpp
${src_root}/Game/World/Map/MapReader.cpp
${inc_root}/Game/World/Map/Physics/ICollidable.hpp
${inc_root}/Game/World/ISpatial3.hpp
${inc_root}/Game/World/Spatial3Info.hpp
${src_root}/Game/World/Spatial3Info.cpp
${src_root}/Game/Pokemon/Pokemon.cpp
${inc_root}/Game/Pokemon/Pokemon.hpp
${src_root}/Game/Pokemon/PokemonInfo.cpp
${inc_root}/Game/Pokemon/PokemonInfo.hpp
${src_root}/Game/Pokemon/PokemonInfoReader.cpp
${inc_root}/Game/Pokemon/PokemonInfoReader.hpp
${src_root}/Game/Pokemon/TypeInfo.cpp
${inc_root}/Game/Pokemon/TypeInfo.hpp
${src_root}/Game/Pokemon/PokemonType.cpp
${inc_root}/Game/Pokemon/PokemonType.hpp
${inc_root}/Game/Pokemon/Gender.hpp
${inc_root}/Game/Pokemon/Status.hpp
${src_root}/Game/Pokemon/SkillInfo.cpp
${inc_root}/Game/Pokemon/SkillInfo.hpp
${src_root}/Game/Pokemon/PokemonSkill.cpp
${inc_root}/Game/Pokemon/PokemonSkill.hpp
${src_root}/Game/Pokemon/PokemonStat.cpp
${inc_root}/Game/Pokemon/PokemonStat.hpp
${src_root}/Game/Pokemon/BaseStat.cpp
${inc_root}/Game/Pokemon/BaseStat.hpp
${src_root}/Game/Pokemon/HitPoint.cpp
${inc_root}/Game/Pokemon/HitPoint.hpp
${src_root}/Game/Pokemon/Attack.cpp
${inc_root}/Game/Pokemon/Attack.hpp
${src_root}/Game/Pokemon/Defense.cpp
${inc_root}/Game/Pokemon/Defense.hpp
${src_root}/Game/Pokemon/Speed.cpp
${inc_root}/Game/Pokemon/Speed.hpp
${src_root}/Game/Pokemon/SpecialAttack.cpp
${inc_root}/Game/Pokemon/SpecialAttack.hpp
${src_root}/Game/Pokemon/SpecialDefense.cpp
${inc_root}/Game/Pokemon/SpecialDefense.hpp
${src_root}/Game/Pokemon/Ability.cpp
${inc_root}/Game/Pokemon/Ability.hpp
${src_root}/Game/Pokemon/NatureInfoReader.cpp
${inc_root}/Game/Pokemon/NatureInfoReader.hpp
${src_root}/Game/Pokemon/NatureInfo.cpp
${inc_root}/Game/Pokemon/NatureInfo.hpp
${src_root}/Game/Pokemon/Gender.cpp
${inc_root}/Game/Pokemon/Gender.hpp

${inc_root}/Graphics/Camera.hpp
${src_root}/Graphics/Camera.cpp
${inc_root}/Graphics/DrawingContext.hpp
${src_root}/Graphics/DrawingContext.cpp
${inc_root}/Graphics/Game/Game.hpp
${src_root}/Graphics/Game/Game.cpp
${inc_root}/Graphics/Game/GameScreen.hpp
${src_root}/Graphics/Game/GameScreen.cpp
${inc_root}/Graphics/Game/GameScreenManager.hpp
${src_root}/Graphics/Game/GameScreenManager.cpp
${inc_root}/Graphics/Game/IGame.hpp
${inc_root}/Graphics/Game/IGameScreen.hpp
${inc_root}/Graphics/Game/IGameScreenManager.hpp
${inc_root}/Graphics/Game/Sprite/AnimatedSprite.hpp
${src_root}/Graphics/Game/Sprite/AnimatedSprite.cpp
${inc_root}/Graphics/Game/Sprite/AnyFrameSwitcher.hpp
${src_root}/Graphics/Game/Sprite/AnyFrameSwitcher.cpp
${inc_root}/Graphics/Game/Sprite/BaseSprite.hpp
${src_root}/Graphics/Game/Sprite/BaseSprite.cpp
${inc_root}/Graphics/Game/Sprite/ComposedSprite.hpp
${src_root}/Graphics/Game/Sprite/ComposedSprite.cpp
${inc_root}/Graphics/Game/Sprite/DelayedFrameSwitcher.hpp
${src_root}/Graphics/Game/Sprite/DelayedFrameSwitcher.cpp
${inc_root}/Graphics/Game/Sprite/DirectionalSpriteSet.hpp
${src_root}/Graphics/Game/Sprite/DirectionalSpriteSet.cpp
${inc_root}/Graphics/Game/Sprite/FrameSwitcher.hpp
${src_root}/Graphics/Game/Sprite/FrameSwitcher.cpp
${inc_root}/Graphics/Game/Sprite/HorizontalComposedSprite.hpp
${src_root}/Graphics/Game/Sprite/HorizontalComposedSprite.cpp
${inc_root}/Graphics/Game/Sprite/ISprite.hpp
${inc_root}/Graphics/Game/Sprite/RegularAnimatedSprite.hpp
${src_root}/Graphics/Game/Sprite/RegularAnimatedSprite.cpp
${inc_root}/Graphics/Game/Sprite/Sprite.hpp
${src_root}/Graphics/Game/Sprite/Sprite.cpp
${inc_root}/Graphics/Game/Sprite/SpriteReader.hpp
${src_root}/Graphics/Game/Sprite/SpriteReader.cpp
${inc_root}/Graphics/Game/Sprite/SpriteSet.hpp
${inc_root}/Graphics/Game/Sprite/SpriteSet.hxx
${inc_root}/Graphics/Game/Sprite/SquareComposedSprite.hpp
${src_root}/Graphics/Game/Sprite/SquareComposedSprite.cpp
${inc_root}/Graphics/Game/Sprite/VerticalComposedSprite.hpp
${src_root}/Graphics/Game/Sprite/VerticalComposedSprite.cpp
${inc_root}/Graphics/Game/World/Map/BasicTileLayoutHandler.hpp
${src_root}/Graphics/Game/World/Map/BasicTileLayoutHandler.cpp
${inc_root}/Graphics/Game/World/Map/RandomTileLayoutHandler.hpp
${src_root}/Graphics/Game/World/Map/RandomTileLayoutHandler.cpp
${inc_root}/Graphics/Game/World/Map/RandomTileLayoutHandlerReader.hpp
${src_root}/Graphics/Game/World/Map/RandomTileLayoutHandlerReader.cpp
${inc_root}/Graphics/Game/World/Map/TileFamily.hpp
${src_root}/Graphics/Game/World/Map/TileFamily.cpp
${inc_root}/Graphics/Game/World/Map/Tile.hpp
${src_root}/Graphics/Game/World/Map/Tile.cpp
${inc_root}/Graphics/Game/World/Map/TileLayer.hpp
${src_root}/Graphics/Game/World/Map/TileLayer.cpp
${inc_root}/Graphics/Game/World/Map/TileLayerStack.hpp
${src_root}/Graphics/Game/World/Map/TileLayerStack.cpp
${inc_root}/Graphics/Game/World/Map/TileLayoutHandler.hpp
${src_root}/Graphics/Game/World/Map/TileLayoutHandler.cpp
${inc_root}/Graphics/Game/World/Map/TileLayoutHandlerReader.hpp
${src_root}/Graphics/Game/World/Map/TileLayoutHandlerReader.cpp
${inc_root}/Graphics/Game/World/Map/TileReader.hpp
${src_root}/Graphics/Game/World/Map/TileReader.cpp
${inc_root}/Graphics/Gui/BaseWidget.hpp
${src_root}/Graphics/Gui/BaseWidget.cpp
${inc_root}/Graphics/Gui/GameInput/GameInputEntry.hpp
${src_root}/Graphics/Gui/GameInput/GameInputEntry.cpp
${inc_root}/Graphics/Gui/GameInput/GameInput.hpp
${src_root}/Graphics/Gui/GameInput/GameInput.cpp
${inc_root}/Graphics/Gui/GameInput/GameInputManager.hpp
${src_root}/Graphics/Gui/GameInput/GameInputManager.cpp
${inc_root}/Graphics/Gui/GameInput/GameInputReader.hpp
${src_root}/Graphics/Gui/GameInput/GameInputReader.cpp
${inc_root}/Graphics/Gui/GameInput/GameInputType.hpp
${inc_root}/Graphics/Gui/GameInput/KeyboardGameInputEntry.hpp
${src_root}/Graphics/Gui/GameInput/KeyboardGameInputEntry.cpp
${inc_root}/Graphics/Gui/GameInput/MouseGameInputEntry.hpp
${src_root}/Graphics/Gui/GameInput/MouseGameInputEntry.cpp
${inc_root}/Graphics/Gui/GuiEvent.hpp
${src_root}/Graphics/Gui/GuiEvent.cpp
${inc_root}/Graphics/Gui/GuiManager.hpp
${src_root}/Graphics/Gui/GuiManager.cpp
${inc_root}/Graphics/Gui/IEventHandler.hpp
${inc_root}/Graphics/Gui/IWidget.hpp
${inc_root}/Graphics/ICamera.hpp
${inc_root}/Graphics/IDrawable.hpp
${inc_root}/Graphics/IDrawingContext.hpp
${inc_root}/Graphics/ISpatial.hpp
${inc_root}/Graphics/RectReader.hpp
${inc_root}/Graphics/RectReader.hxx
${inc_root}/Graphics/SpatialInfo.hpp
${src_root}/Graphics/SpatialInfo.cpp
${inc_root}/Graphics/Texture.hpp
${src_root}/Graphics/Texture.cpp
${inc_root}/Graphics/TextureReader.hpp
${src_root}/Graphics/TextureReader.cpp
${inc_root}/Graphics/Vector2.hpp
${src_root}/Graphics/Vector2.cpp

${inc_root}/Macros.hpp

${inc_root}/System/Error/ContentLoadingFailException.hpp
${src_root}/System/Error/ContentLoadingFailException.cpp
${inc_root}/System/Error/Exception.hpp
${src_root}/System/Error/Exception.cpp
${inc_root}/System/Error/InvalidMethodCallException.hpp
${src_root}/System/Error/InvalidMethodCallException.cpp
${inc_root}/System/Event/Event.hpp
${inc_root}/System/Event/Event.hxx
${inc_root}/System/IntTypes.hpp
${inc_root}/System/IO/IReaderConstVisitor.hpp
${inc_root}/System/IO/IReader.hpp
${inc_root}/System/IO/IReaderVisitor.hpp
${inc_root}/System/IO/IWriterConstVisitor.hpp
${inc_root}/System/IO/IWriter.hpp
${inc_root}/System/IO/IWriterVisitor.hpp
${inc_root}/System/IO/Log/CountLoggerMode.hpp
${src_root}/System/IO/Log/CountLoggerMode.cpp
${inc_root}/System/IO/Log/DebugLogger.hpp
${src_root}/System/IO/Log/DebugLogger.cpp
${inc_root}/System/IO/Log/DatabaseLogger.hpp
${src_root}/System/IO/Log/DatabaseLogger.cpp
${inc_root}/System/IO/Log/Logger.hpp
${inc_root}/System/IO/Log/Logger.hxx
${src_root}/System/IO/Log/Logger.cpp
${inc_root}/System/IO/Log/LoggerMode.hpp
${src_root}/System/IO/Log/LoggerMode.cpp
${inc_root}/System/IO/Log/TimeLoggerMode.hpp
${src_root}/System/IO/Log/TimeLoggerMode.cpp
${inc_root}/System/IO/Xml/XmlHelper.hpp
${src_root}/System/IO/Xml/XmlHelper.cpp
${inc_root}/System/IO/Xml/XmlReaderCollection.hpp
${src_root}/System/IO/Xml/XmlReaderCollection.cpp
${inc_root}/System/IO/Xml/XmlReader.hpp
${src_root}/System/IO/Xml/XmlReader.cpp
${inc_root}/System/IO/Xml/XmlReaderVisitor.hpp
${src_root}/System/IO/Xml/XmlReaderVisitor.cpp
${inc_root}/System/IO/Xml/XmlTree.hpp
${inc_root}/System/IO/Xml/XmlTree.hxx
${src_root}/System/IO/Xml/XmlTree.cpp
${inc_root}/System/IO/Xml/XmlWriter.hpp
${src_root}/System/IO/Xml/XmlWriter.cpp
${inc_root}/System/IOStream.hpp
${inc_root}/System/MathHelper.hpp
${inc_root}/System/MathHelper.hxx
${inc_root}/System/Path.hpp
${src_root}/System/Path.cpp
${inc_root}/System/RandomHelper.hpp
${src_root}/System/RandomHelper.cpp
${inc_root}/System/StringHelper.hpp
${inc_root}/System/StringHelper.hxx
${src_root}/System/StringHelper.cpp
${inc_root}/System/String.hpp
${inc_root}/System/Time/DateTimeHelper.hpp
${src_root}/System/Time/DateTimeHelper.cpp
${inc_root}/System/Time/DateTime.hpp
${src_root}/System/Time/DateTime.cpp
${inc_root}/System/Time/Time.hpp
${src_root}/System/Time/Time.cpp
${inc_root}/System/Time/Timer.hpp
${src_root}/System/Time/Timer.cpp
${inc_root}/System/Time/UpdateableTimer.hpp
${src_root}/System/Time/UpdateableTimer.cpp
${pgstream_inc_root}/pgstream.hpp
${pgstream_src_root}/pgstream.cpp
${inc_root}/Database/DatabaseManager.hpp
${src_root}/Database/DatabaseManager.cpp
)

ADD_LIBRARY(
	${PROJECT_NAME}
	SHARED
	${source_files}
)

TARGET_LINK_LIBRARIES(
	${PROJECT_NAME}
	${link_lib}
)

if( WIN32 )
ADD_CUSTOM_COMMAND(
	TARGET
	${PROJECT_NAME}
	POST_BUILD
	COMMAND copy ARGS \$\(CodeAnalysisInputAssembly\) \$\(SolutionDir\)YAPOG.Client\\bin\\\$\(Configuration\)
	COMMAND copy ARGS \$\(CodeAnalysisInputAssembly\) \$\(SolutionDir\)YAPOG.Server\\bin\\\$\(Configuration\)
	COMMAND copy ARGS \$\(CodeAnalysisInputAssembly\) \$\(SolutionDir\)YAPOG.Test\\bin\\\$\(Configuration\)
	COMMENT "Copy the YAPOG DLL file in the good directory !"
)

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
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\sfml2\\\$\(Configuration\)
							\$\(SolutionDir\)YAPOG.Client\\bin\\\$\(Configuration\)
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\sfml2\\\$\(Configuration\)
							\$\(SolutionDir\)YAPOG.Server\\bin\\\$\(Configuration\)
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\sfml2\\\$\(Configuration\)
							\$\(SolutionDir\)YAPOG.Test\\bin\\\$\(Configuration\)
	COMMENT "Copy the SFML2 DLL files in the good directory !"
)

ADD_CUSTOM_COMMAND(
	TARGET
	${PROJECT_NAME}
	PRE_BUILD
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\postgresql
							\$\(SolutionDir\)\\YAPOG.Client\\bin\\\$\(Configuration\)
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\postgresql
							\$\(SolutionDir\)\\YAPOG.Server\\bin\\\$\(Configuration\)
	COMMAND xcopy ARGS /s/y ${CMAKE_SOURCE_DIR_VS}\\extlibs\\bin\\x86\\postgresql
							\$\(SolutionDir\)\\YAPOG.Test\\bin\\\$\(Configuration\)
	COMMENT "Copy the SFML2 DLL files in the good directory !"
)
endif()

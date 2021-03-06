CMAKE_MINIMUM_REQUIRED(VERSION 2.8.4)

PROJECT(Pong)

# Modules
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

# Output directories
IF (UNIX)
    set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
ENDIF (UNIX)

# Move all targets to /bin (e.g. Release, Debug)
IF(WIN32)
    FOREACH(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})
        STRING( TOUPPER ${OUTPUTCONFIG} OUTPUTCONFIG )
        SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_SOURCE_DIR}/bin)
        SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_SOURCE_DIR}/bin)
        SET(CMAKE_ARCHIVE_OUTPUT_DIRECTORY_${OUTPUTCONFIG} ${PROJECT_SOURCE_DIR}/bin)
    ENDFOREACH(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)
ENDIF(WIN32)

# Adding a new executable with the name ${PROJECT_NAME}
ADD_EXECUTABLE(
    ${PROJECT_NAME}
    src/main.cpp
    src/Player.cpp
    src/BitmapFont.cpp
    src/MainBitmapFont.cpp
    src/Ball.cpp
    src/World.cpp
    src/Paddle.cpp
    src/Vector2.cpp
    src/AABB2.cpp
    src/Drawing.cpp
    src/MathUtilities.cpp
    src/Texture.cpp
    src/Sound.cpp
    src/Game.cpp
    src/PongGame.cpp
)

IF (WIN32)
    
    # More information about the following macros:
    # https://binglongx.wordpress.com/tag/safeseh/

    # Append str to a string property of a target. 
    # target:      string: target name. 
    # property:    name of target’s property. e.g: COMPILE_FLAGS, or LINK_FLAGS 
    # str:         string: string to be appended to the property 
    MACRO(MACRO_APPEND_TARGET_PROPERTY target property str) 
      GET_TARGET_PROPERTY(current_property ${target} ${property}) 
      IF(NOT current_property) # property non-existent or empty 
          SET_TARGET_PROPERTIES(${target} PROPERTIES ${property} ${str}) 
      ELSE() 
          SET_TARGET_PROPERTIES(${target} PROPERTIES ${property} "${current_property} ${str}") 
      ENDIF() 
    ENDMACRO(MACRO_APPEND_TARGET_PROPERTY)

    # Add/append compile flags to a target. 
    # target: string: target name. 
    # flags : string: compile flags to be appended 
    MACRO(MACRO_ADD_COMPILE_FLAGS target flags) 
      MACRO_APPEND_TARGET_PROPERTY(${target} COMPILE_FLAGS ${flags}) 
    ENDMACRO(MACRO_ADD_COMPILE_FLAGS)


    # Add/append link flags to a target. 
    # target: string: target name. 
    # flags : string: link flags to be appended 
    MACRO(MACRO_ADD_LINK_FLAGS target flags) 
      MACRO_APPEND_TARGET_PROPERTY(${target} LINK_FLAGS ${flags}) 
    ENDMACRO(MACRO_ADD_LINK_FLAGS) 


    # Disable the Linker option Image Has Safe Exception Handlers (SAFESEH)
    # This cause compilation errors in VS2012, VS2013 with the OpenAL dll.
    MACRO_ADD_LINK_FLAGS(${PROJECT_NAME} "/SAFESEH:NO")

ENDIF (WIN32)

# OpenGL
FIND_PACKAGE(OpenGL REQUIRED)
INCLUDE_DIRECTORIES(${OpenGL_INCLUDE_DIRS})
LINK_DIRECTORIES(${OpenGL_LIBRARY_DIRS})
ADD_DEFINITIONS(${OpenGL_DEFINITIONS})
IF(NOT OPENGL_FOUND)
    MESSAGE(ERROR " OPENGL not found!")
ENDIF(NOT OPENGL_FOUND)

if (UNIX)
    # DevIL
    FIND_PACKAGE(DevIL REQUIRED)
    IF(NOT IL_FOUND)
        MESSAGE(ERROR " DevIL not found!")
    ENDIF(NOT IL_FOUND)

    # OpenAL
    FIND_PACKAGE(OPENAL REQUIRED)
    IF(NOT OPENAL_FOUND)
        MESSAGE(ERROR " OPENAL not found!")
    ENDIF(NOT OPENAL_FOUND)

    # ALUT
    FIND_PACKAGE(ALUT REQUIRED)
    IF(NOT ALUT_FOUND)
        MESSAGE(ERROR " OPENAL not found!")
    ENDIF(NOT ALUT_FOUND)

    # SDL2
    FIND_PACKAGE(SDL2 REQUIRED)
    INCLUDE_DIRECTORIES(${SDL2_INCLUDE_DIR})
    IF(NOT SDL2_FOUND)
        MESSAGE(ERROR " SDL2 not found!")
    ENDIF(NOT SDL2_FOUND)

    # Linking libraries
    TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        ${OPENGL_LIBRARIES}
        ${SDL2_LIBRARY}
        ${IL_LIBRARIES}
        ${ILU_LIBRARIES}
        ${ILUT_LIBRARIES}
        ${OPENAL_LIBRARY}
        ${ALUT_LIBRARY}
    )

    # Copy images
    ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/images ${PROJECT_SOURCE_DIR}/bin/images
    )

    # Copy fonts
    ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/fonts ${PROJECT_SOURCE_DIR}/bin/fonts
    )

    # Copy sounds
    ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/sounds ${PROJECT_SOURCE_DIR}/bin/sounds
    )

endif (UNIX)

IF(WIN32)

    INCLUDE_DIRECTORIES(
        ${PROJECT_SOURCE_DIR}/deps/win32/devil/include
        ${PROJECT_SOURCE_DIR}/deps/win32/openal/include
        ${PROJECT_SOURCE_DIR}/deps/win32/sdl2/include
    )

    TARGET_LINK_LIBRARIES(
        ${PROJECT_NAME}
        ${OPENGL_LIBRARIES}
        ${PROJECT_SOURCE_DIR}/deps/win32/devil/lib/DevIL.lib
        ${PROJECT_SOURCE_DIR}/deps/win32/devil/lib/ILU.lib
        ${PROJECT_SOURCE_DIR}/deps/win32/devil/lib/ILUT.lib
        ${PROJECT_SOURCE_DIR}/deps/win32/openal/lib/OpenAL32.lib
        ${PROJECT_SOURCE_DIR}/deps/win32/openal/lib/alut.lib
        ${PROJECT_SOURCE_DIR}/deps/win32/sdl2/lib/SDL2.lib
    )

    # Gather all *.dll files
    FILE(GLOB_RECURSE DLLFiles ${PROJECT_SOURCE_DIR}/deps/*.dll)

    # Iterate throught the different targets (e.g. Release, Debug)
    FOREACH(OUTPUTCONFIG ${CMAKE_CONFIGURATION_TYPES})

        # Copy fonts
        ADD_CUSTOM_COMMAND(
            TARGET ${PROJECT_NAME} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/fonts ${OUTPUTCONFIG}/fonts
        )

        # Copy sounds
        ADD_CUSTOM_COMMAND(
            TARGET ${PROJECT_NAME} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/sounds ${OUTPUTCONFIG}/sounds
        )

        # Copy images
        ADD_CUSTOM_COMMAND(
            TARGET ${PROJECT_NAME} PRE_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${PROJECT_SOURCE_DIR}/images ${OUTPUTCONFIG}/images
        )

        FOREACH(DLLFile ${DLLFiles})
            ADD_CUSTOM_COMMAND(
                TARGET ${PROJECT_NAME} PRE_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy 
                ${DLLFile} ${OUTPUTCONFIG}
            )
        ENDFOREACH()

    ENDFOREACH(OUTPUTCONFIG CMAKE_CONFIGURATION_TYPES)

    # Copy fonts, for running the project from VS
    ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/fonts fonts
    )

    # Copy sounds, for running the project from VS
    ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/sounds sounds
    )

    # Copy images, for running the project from VS
    ADD_CUSTOM_COMMAND(
        TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${PROJECT_SOURCE_DIR}/images images
    )

ENDIF(WIN32)

INSTALL (
    TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION ${PROJECT_BINARY_DIR}/bin
)

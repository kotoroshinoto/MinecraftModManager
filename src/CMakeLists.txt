add_subdirectory(tabs)
add_subdirectory(GUI)

#placeholder for content that needs to be moved here
set(APP_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Minecraft_Mod_ManagerApp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Minecraft_Mod_ManagerMain.cpp
        )
set(APP_HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/Minecraft_Mod_ManagerApp.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Minecraft_Mod_ManagerMain.h
        )

#MESSAGE(INFO "\tAPP source files: ${APP_SOURCE_FILES}")
#MESSAGE(INFO "\tAPP header files: ${APP_HEADER_FILES}")

set(MinecraftModManager_SOURCE_FILES ${MinecraftModManager_SOURCE_FILES} ${APP_SOURCE_FILES} CACHE STRING "Application Source Files" FORCE)
set(MinecraftModManager_HEADER_FILES ${MinecraftModManager_HEADER_FILES} ${APP_HEADER_FILES} CACHE STRING "Application Header Files" FORCE)
#MESSAGE(INFO "\tUpdated Main Source files: ${MinecraftModManager_SOURCE_FILES}")
#MESSAGE(INFO "\tUpdated Main Header files: ${MinecraftModManager_HEADER_FILES}")

#add_library(APP OBJECT ${APP_SOURCE_FILES})

#XERCES_SRC_BACKUP/MinecraftUpdater.cpp
#XERCES_SRC_BACKUP/MinecraftUpdater.h
#
#ACLOCAL_AMFLAGS= ${ACLOCAL_FLAGS}
#
#SUBDIRS= GUI tabs launcher
#
#bin_PROGRAMS= MinecraftModManager
#MinecraftModManager_SOURCES= wx_pch.h Minecraft_Mod_ManagerMain.cpp Minecraft_Mod_ManagerApp.cpp
#MinecraftModManager_LDADD= GUI/libGUI.la tabs/libtabs.la
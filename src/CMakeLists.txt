add_subdirectory(GUI)
add_subdirectory(tabs)

#placeholder for content that needs to be moved here
set(SOURCE_FILES
        Minecraft_Mod_ManagerApp.cpp
        Minecraft_Mod_ManagerApp.h
        Minecraft_Mod_ManagerMain.cpp
        Minecraft_Mod_ManagerMain.h
        )

#XERCES_SRC_BACKUP/MinecraftUpdater.cpp
#XERCES_SRC_BACKUP/MinecraftUpdater.h

add_executable(MinecraftModManager ${SOURCE_FILES} $<TARGET_OBJECTS:GUI> $<TARGET_OBJECTS:TABS>)

target_link_libraries(MinecraftModManager ${requiredlibs})

#
#ACLOCAL_AMFLAGS= ${ACLOCAL_FLAGS}
#
#SUBDIRS= GUI tabs launcher
#
#bin_PROGRAMS= MinecraftModManager
#MinecraftModManager_SOURCES= wx_pch.h Minecraft_Mod_ManagerMain.cpp Minecraft_Mod_ManagerApp.cpp
#MinecraftModManager_LDADD= GUI/libGUI.la tabs/libtabs.la
#placeholder for content that needs to be moved here
set(SOURCE_FILES
        GUI/GUIFrame.cpp
        GUI/GUIFrame.h
        GUI/GUIFrame_additional_setup.h
        GUI/GUIFrame_events.cpp
        GUI/SupplementaryIncludes.h
        tabs/ClientInstanceTab.cpp
        tabs/ClientInstanceTab.h
        tabs/InstanceTab.cpp
        tabs/InstanceTab.h
        tabs/JarTab.cpp
        tabs/JarTab.h
        tabs/MinecraftSessionManager.cpp
        tabs/MinecraftSessionManager.h
        tabs/MinecraftUpdater.cpp
        tabs/MinecraftUpdater.h
        tabs/MinecraftUtils.cpp
        tabs/MinecraftUtils.h
        tabs/ModTab.cpp
        tabs/ModTab.h
        tabs/ParentApp.cpp
        tabs/ParentApp.h
        tabs/ServerInstanceTab.cpp
        tabs/ServerInstanceTab.h
        tabs/SettingsTab.cpp
        tabs/SettingsTab.h
        tabs/Terminal.cpp
        tabs/Terminal.h
        tabs/types.h
        Minecraft_Mod_ManagerApp.cpp
        Minecraft_Mod_ManagerApp.h
        Minecraft_Mod_ManagerMain.cpp
        Minecraft_Mod_ManagerMain.h
        )

#XERCES_SRC_BACKUP/MinecraftUpdater.cpp
#XERCES_SRC_BACKUP/MinecraftUpdater.h

add_executable(MinecraftModManager ${SOURCE_FILES})

target_link_libraries(MinecraftModManager ${requiredlibs})
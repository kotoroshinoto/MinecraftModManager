cmake_minimum_required(VERSION 3.6)
project(MinecraftModManager)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/GUI/GUIFrame.cpp
        src/GUI/GUIFrame.h
        src/GUI/GUIFrame_additional_setup.h
        src/GUI/GUIFrame_events.cpp
        src/GUI/SupplementaryIncludes.h
        src/tabs/ClientInstanceTab.cpp
        src/tabs/ClientInstanceTab.h
        src/tabs/InstanceTab.cpp
        src/tabs/InstanceTab.h
        src/tabs/JarTab.cpp
        src/tabs/JarTab.h
        src/tabs/MinecraftSessionManager.cpp
        src/tabs/MinecraftSessionManager.h
        src/tabs/MinecraftUpdater.cpp
        src/tabs/MinecraftUpdater.h
        src/tabs/MinecraftUtils.cpp
        src/tabs/MinecraftUtils.h
        src/tabs/ModTab.cpp
        src/tabs/ModTab.h
        src/tabs/ParentApp.cpp
        src/tabs/ParentApp.h
        src/tabs/ServerInstanceTab.cpp
        src/tabs/ServerInstanceTab.h
        src/tabs/SettingsTab.cpp
        src/tabs/SettingsTab.h
        src/tabs/Terminal.cpp
        src/tabs/Terminal.h
        src/tabs/types.h
        src/Minecraft_Mod_ManagerApp.cpp
        src/Minecraft_Mod_ManagerApp.h
        src/Minecraft_Mod_ManagerMain.cpp
        src/Minecraft_Mod_ManagerMain.h
        XERCES_SRC_BACKUP/MinecraftUpdater.cpp
        XERCES_SRC_BACKUP/MinecraftUpdater.h)

add_executable(MinecraftModManager ${SOURCE_FILES})
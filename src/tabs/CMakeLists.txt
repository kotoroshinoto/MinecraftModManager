#noinst_LTLIBRARIES= libtabs.la
#libtabs_la_SOURCES= ParentApp.cpp InstanceTab.cpp ClientInstanceTab.cpp ServerInstanceTab.cpp JarTab.cpp ModTab.cpp SettingsTab.cpp Terminal.cpp MinecraftUtils.cpp  MinecraftSessionManager.cpp MinecraftUpdater.cpp
set(TAB_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/ClientInstanceTab.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/InstanceTab.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/JarTab.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MinecraftSessionManager.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MinecraftUpdater.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/MinecraftUtils.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ModTab.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ParentApp.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/ServerInstanceTab.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/SettingsTab.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/Terminal.cpp
        )

set(TAB_HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/ClientInstanceTab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/InstanceTab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/JarTab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MinecraftSessionManager.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MinecraftUpdater.h
        ${CMAKE_CURRENT_SOURCE_DIR}/MinecraftUtils.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ModTab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ParentApp.h
        ${CMAKE_CURRENT_SOURCE_DIR}/ServerInstanceTab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SettingsTab.h
        ${CMAKE_CURRENT_SOURCE_DIR}/Terminal.h
        ${CMAKE_CURRENT_SOURCE_DIR}/types.h
        )
#MESSAGE(INFO "\tTAB source files: ${TAB_SOURCE_FILES}")
#MESSAGE(INFO "\tTAB header files: ${TAB_HEADER_FILES}")
set(MinecraftModManager_SOURCE_FILES ${MinecraftModManager_SOURCE_FILES} ${TAB_SOURCE_FILES} CACHE STRING "Application Source Files" FORCE)
set(MinecraftModManager_HEADER_FILES ${MinecraftModManager_HEADER_FILES} ${TAB_HEADER_FILES} CACHE STRING "Application Header Files" FORCE)
#MESSAGE(INFO "\tUpdated Main Source files: ${MinecraftModManager_SOURCE_FILES}")
#MESSAGE(INFO "\tUpdated Main Header files: ${MinecraftModManager_HEADER_FILES}")
#add_library(TABS OBJECT ${TAB_SOURCE_FILES})
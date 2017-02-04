#noinst_LTLIBRARIES = libGUI.la
#libGUI_la_SOURCES = GUIFrame.cpp
set(GUI_SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/GUIFrame.cpp
        )
set(GUI_HEADER_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/GUIFrame.h
        ${CMAKE_CURRENT_SOURCE_DIR}/SupplementaryIncludes.h
        ${CMAKE_CURRENT_SOURCE_DIR}/GUIFrame_additional_setup.h
        )
#GUIFrame_additional_setup.h
#GUIFrame_events.cpp

#MESSAGE(INFO "\tGUI source files: ${GUI_SOURCE_FILES}")
#MESSAGE(INFO "\tGUI header files: ${GUI_HEADER_FILES}")
set(MinecraftModManager_SOURCE_FILES ${MinecraftModManager_SOURCE_FILES} ${GUI_SOURCE_FILES} CACHE STRING "Application Source Files" FORCE)
set(MinecraftModManager_HEADER_FILES ${MinecraftModManager_HEADER_FILES} ${GUI_HEADER_FILES} CACHE STRING "Application Header Files" FORCE)
#MESSAGE(INFO "\tUpdated Main Source files: ${MinecraftModManager_SOURCE_FILES}")
#MESSAGE(INFO "\tUpdated Main Header files: ${MinecraftModManager_HEADER_FILES}")
#add_library(GUI OBJECT ${GUI_SOURCE_FILES})
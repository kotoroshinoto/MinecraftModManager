#noinst_LTLIBRARIES = libGUI.la
#libGUI_la_SOURCES = GUIFrame.cpp
set(GUI_SOURCE_FILES
        GUIFrame.cpp
        GUIFrame.h
        GUIFrame_additional_setup.h
        GUIFrame_events.cpp
        SupplementaryIncludes.h
        )

add_library(GUI OBJECT ${GUI_SOURCE_FILES})
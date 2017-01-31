#noinst_LTLIBRARIES= libtabs.la
#libtabs_la_SOURCES= ParentApp.cpp InstanceTab.cpp ClientInstanceTab.cpp ServerInstanceTab.cpp JarTab.cpp ModTab.cpp SettingsTab.cpp Terminal.cpp MinecraftUtils.cpp  MinecraftSessionManager.cpp MinecraftUpdater.cpp
set(TAB_SOURCE_FILES
        ClientInstanceTab.cpp
        ClientInstanceTab.h
        InstanceTab.cpp
        InstanceTab.h
        JarTab.cpp
        JarTab.h
        MinecraftSessionManager.cpp
        MinecraftSessionManager.h
        MinecraftUpdater.cpp
        MinecraftUpdater.h
        MinecraftUtils.cpp
        MinecraftUtils.h
        ModTab.cpp
        ModTab.h
        ParentApp.cpp
        ParentApp.h
        ServerInstanceTab.cpp
        ServerInstanceTab.h
        SettingsTab.cpp
        SettingsTab.h
        Terminal.cpp
        Terminal.h
        types.h
        )
add_library(TABS OBJECT ${TAB_SOURCE_FILES})
cmake_minimum_required(VERSION 3.5)

project(MinecraftModManager)

set(CMAKE_CXX_STANDARD 11)
set(BUILD_SHARED_LIBS OFF)
SET(requiredlibs)

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

#FIND_PACKAGE(JNI)
#IF(JNI_FOUND)
#    INCLUDE_DIRECTORIES(${JNI_INCLUDE_DIR})
#    SET(requiredlibs ${requiredlibs} ${JNI_LIBRARIES} )
#    MESSAGE(INFO "\tFound JNI at path ${JAVA_INCLUDE_PATH}")
#ELSE(JNI_FOUND)
#    MESSAGE(FATAL_ERROR "Could not find the JNI library and development files.")
#ENDIF(JNI_FOUND)

#FIND_PACKAGE(XercesC)
#IF(XercesC_FOUND)
#    INCLUDE_DIRECTORIES(${XercesC_INCLUDE_DIR})
#    SET(requiredlibs ${requiredlibs} ${XercesC_LIBRARIES} )
#ELSE(XercesC_FOUND)
#    MESSAGE(FATAL_ERROR "Could not find the XercesC library and development files.")
#ENDIF(XercesC_FOUND)

set(wxWidgets_USE_STATIC ON)
set(wxWidgets_USE_UNICODE ON)
set(wxWidgets_USE_UNIVERSAL OFF)
set(wxWidgets_USE_DEBUG OFF)

find_package(wxWidgets REQUIRED net gl core base xml)
IF(wxWidgets_FOUND)
    INCLUDE_DIRECTORIES(${wxWidgets_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${wxWidgets_LIBRARIES} )
    MESSAGE("-- wxWidgets found! with configuration: ${wxWidgets_CONFIGURATION} at path ${wxWidgets_ROOT_DIR}")
ELSE(wxWidgets_FOUND)
    MESSAGE(FATAL_ERROR "\tCould not find the wxWidgets library and development files.")
ENDIF(wxWidgets_FOUND)


list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

#asdf

# check for mbedtls (*REQUIRED*)
find_package(MbedTLS REQUIRED)

#MESSAGE(INFO "\tMBEDTLS_FOUND: ${MBEDTLS_FOUND}")
#MESSAGE(INFO "\tMBEDTLS_INCLUDE_DIRS: ${MBEDTLS_INCLUDE_DIRS}")
#MESSAGE(INFO "\tMBEDTLS_LIBRARIES: ${MBEDTLS_LIBRARIES}")

if(MBEDTLS_FOUND  AND  MBEDTLS_INCLUDE_DIRS  AND  MBEDTLS_LIBRARIES)
    include_directories(${MBEDTLS_INCLUDE_DIRS})
    set(_MBEDTLS_VERSION_ ${MBEDTLS_VERSION})
    message("-- mbedTLS ${MBEDTLS_VERSION} found!")
    SET(requiredlibs ${requiredlibs} ${MBEDTLS_LIBRARIES})
else()
    MESSAGE(FATAL_ERROR "\tCould not find the mbedTLS library and development files.")
endif()

if(WIN32)
    add_definitions(-D__WXMSW__ -D__GNUWIN32__)
    SET(requiredlibs ${requiredlibs} shlwapi version)
endif()

add_definitions(-D_UNICODE)

include(${wxWidgets_USE_FILE})

set(MinecraftModManager_SOURCE_FILES CACHE STRING "Application Source Files")
set(MinecraftModManager_HEADER_FILES CACHE STRING "Application Header Files")

add_subdirectory(src)

#MESSAGE(INFO "\tUpdated Main Source files: ${MinecraftModManager_SOURCE_FILES}")
#MESSAGE(INFO "\tUpdated Main Header files: ${MinecraftModManager_HEADER_FILES}")
add_executable(MinecraftModManager ${MinecraftModManager_SOURCE_FILES})

MESSAGE("-- Linking to libraries: ${requiredlibs}")

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++ -static")

target_link_libraries(MinecraftModManager ${requiredlibs})

add_executable(wxURL-test wxURL_test.cpp)
target_link_libraries(wxURL-test ${requiredlibs})

add_executable(wxURL-Download-test wxURL_DownloadTest.cpp)
target_link_libraries(wxURL-Download-test ${requiredlibs})

add_executable(mbedTLStest mbed_TLS_test.cpp)
target_link_libraries(mbedTLStest ${requiredlibs})

cmake_minimum_required(VERSION 3.6)

project(MinecraftModManager)

set(CMAKE_CXX_STANDARD 11)

SET(requiredlibs)

FIND_PACKAGE(CURL)
IF(CURL_FOUND)
    INCLUDE_DIRECTORIES(${CURL_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${CURL_LIBRARIES} )
ELSE(CURL_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the CURL library and development files.")
ENDIF(CURL_FOUND)

FIND_PACKAGE(OpenSSL)
IF(OpenSSL_FOUND)
    INCLUDE_DIRECTORIES(${OpenSSL_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${OpenSSL_LIBRARIES} )
ELSE(OpenSSL_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the OpenSSL library and development files.")
ENDIF(OpenSSL_FOUND)

FIND_PACKAGE(JNI)
IF(JNI_FOUND)
    INCLUDE_DIRECTORIES(${JNI_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${JNI_LIBRARIES} )
ELSE(JNI_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the JNI library and development files.")
ENDIF(JNI_FOUND)

#FIND_PACKAGE(XercesC)
#IF(XercesC_FOUND)
#    INCLUDE_DIRECTORIES(${XercesC_INCLUDE_DIR})
#    SET(requiredlibs ${requiredlibs} ${XercesC_LIBRARIES} )
#ELSE(XercesC_FOUND)
#    MESSAGE(FATAL_ERROR "Could not find the XercesC library and development files.")
#ENDIF(XercesC_FOUND)

set(wxWidgets_CONFIG_OPTIONS --toolkit=base --prefix=/usr)
find_package(wxWidgets REQUIRED net gl core base)
IF(wxWidgets_FOUND)
    INCLUDE_DIRECTORIES(${wxWidgets_INCLUDE_DIR})
    SET(requiredlibs ${requiredlibs} ${wxWidgets_LIBRARIES} )
ELSE(wxWidgets_FOUND)
    MESSAGE(FATAL_ERROR "Could not find the wxWidgets library and development files.")
ENDIF(wxWidgets_FOUND)

include(${wxWidgets_USE_FILE})

add_subdirectory(src bin)

cmake_minimum_required(VERSION 3.5)

project(coalesce
    VERSION 1.1.1
    DESCRIPTION "Coalesce is a video player that supports local video, cloud drive and streaming."
    HOMEPAGE_URL "https://github.com/napchn/coalesce"
    LANGUAGES CXX
)

set(CMAKE_PREFIX_PATH "C:/Programs/Qt/6.5.2/mingw_64" CACHE PATH "Qt Installation Path")
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    include(cmake/project-source.cmake)
else()
    message(FATAL_ERROR "${CMAKE_PROJECT_NAME} only supports Qt6 or newer versions.")
endif()

target_link_libraries(${CMAKE_PROJECT_NAME}
    PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

set_target_properties(${CMAKE_PROJECT_NAME}
    PROPERTIES
    ${BUNDLE_ID_OPTION}
    WIN32_EXECUTABLE TRUE
)

qt_finalize_executable(${CMAKE_PROJECT_NAME})

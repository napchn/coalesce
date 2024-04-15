set(PROJECT_SOURCES main.cpp)
set(SRC_DIR_LIST
    src/cmpnt
    src/cmn
    src
)

foreach(SRC_DIR ${SRC_DIR_LIST})
    file(GLOB SRC_FILES 
        ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}/*.ui)
    list(APPEND PROJECT_SOURCES ${SRC_FILES})
endforeach()

qt_add_resources(PROJECT_RESOURCES static/resources.qrc)

qt_add_executable(${CMAKE_PROJECT_NAME}
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
    ${PROJECT_RESOURCES}
)

foreach(SRC_DIR ${SRC_DIR_LIST})
    target_include_directories(${CMAKE_PROJECT_NAME} PRIVATE
        "${CMAKE_CURRENT_SOURCE_DIR}/${SRC_DIR}"
    )
endforeach()

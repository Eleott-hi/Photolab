cmake_minimum_required(VERSION 3.5)

find_program(CMAKE_CXX_COMPILER NAMES g++)

if(CMAKE_CXX_COMPILER)
    message(STATUS "Found g++ compiler: ${CMAKE_CXX_COMPILER}")
else()
    message(FATAL_ERROR "Could not find g++ compiler")
    exit()
endif()

project(Photolab VERSION 1.0 LANGUAGES CXX)

# add_compile_options(-fsanitize=address)
# add_link_options(-fsanitize=address)
add_compile_options(-O3)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS forms)

set(QT_LIBS Widgets)
set(EXCLUDE_DIRS tests)
include_directories(model view common)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS ${QT_LIBS})
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS ${QT_LIBS})

file(GLOB_RECURSE PROJECT_FILES *.cc *.h *.ui)

foreach(i ${EXCLUDE_DIRS})
    message("Excluding dir: " ${i})
    list(FILTER PROJECT_FILES EXCLUDE REGEX ".*${i}.*")
endforeach()

foreach(i ${PROJECT_FILES})
    message("Project file: " ${i})
endforeach()

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(${PROJECT_NAME} MANUAL_FINALIZATION ${PROJECT_FILES})
else()
    if(ANDROID)
        add_library(${PROJECT_NAME} SHARED ${PROJECT_FILES})
    else()
        add_executable(${PROJECT_NAME} ${PROJECT_FILES})
    endif()
endif()

foreach(i ${QT_LIBS})
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::${i})
endforeach()

set_target_properties(${PROJECT_NAME} PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()

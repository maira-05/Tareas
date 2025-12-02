cmake_minimum_required(VERSION 3.5)
project(HealthTracker LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# IMPORTANTE: Ruta real de los .ui
set(CMAKE_AUTOUIC_SEARCH_PATHS
    ${CMAKE_SOURCE_DIR}/ui
)

find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)

set(SOURCES
    src/main.cpp
    src/MainWindow.cpp
    src/LoginDialog.cpp
    src/RecordDialog.cpp
    src/User.cpp
    src/HealthRecord.cpp
    src/HealthAnalyzer.cpp
    src/RecordsModel.cpp
    src/CSVExporter.cpp
    src/DatabaseManager.cpp
)

set(HEADERS
    include/MainWindow.h
    include/LoginDialog.h
    include/RecordDialog.h
    include/User.h
    include/HealthRecord.h
    include/HealthAnalyzer.h
    include/RecordsModel.h
    include/CSVExporter.h
    include/DatabaseManager.h
)

set(UIS
    ui/MainWindow.ui
    ui/LoginDialog.ui
    ui/RecordDialog.ui
)

set(RESOURCES
    resources/app_resources.qrc
)

add_executable(${PROJECT_NAME}
    ${SOURCES}
    ${HEADERS}
    ${UIS}
    ${RESOURCES}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Gui
    Qt5::Widgets
    Qt5::Sql
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_17)

cmake_minimum_required(VERSION 3.5)
project(HealthTracker LANGUAGES CXX)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Core Gui Widgets Sql REQUIRED)

# incluye carpeta include/
include_directories(${CMAKE_SOURCE_DIR}/include)

# fuentes
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

# headers
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

# ui files
set(UIS
    ui/MainWindow.ui
    ui/LoginDialog.ui
    ui/RecordDialog.ui
)

# recursos
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

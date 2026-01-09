cmake_minimum_required(VERSION 3.16)
project(VideoOCR VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_PREFIX_PATH "C:/Qt/6.5.3/msvc2019_64")
find_package(Qt6 REQUIRED COMPONENTS Core Widgets Multimedia MultimediaWidgets)
qt_standard_project_setup()
qt_add_executable(VideoOCR
    main.cpp
    mainwindow.cpp mainwindow.h
    monochromedialog.cpp monochromedialog.h
    ocrdialog.cpp ocrdialog.h
)
target_link_libraries(VideoOCR PRIVATE
    Qt6::Core
    Qt6::Widgets
    Qt6::Multimedia
    Qt6::MultimediaWidgets
)
set_target_properties(VideoOCR PROPERTIES
    WIN32_EXECUTABLE ON
    MACOSX_BUNDLE TRUE
)

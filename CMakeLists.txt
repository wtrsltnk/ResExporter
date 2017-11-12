cmake_minimum_required(VERSION 2.8)

project(res-exporter)

add_subdirectory(ControlLib)
add_subdirectory(DialogsLib)

add_executable(res-exporter WIN32
    Attribute.cpp
    BatchDlg.cpp
    BSPFileLoader.cpp
    BSPManager.cpp
    BSPOpener.cpp
    Entity.cpp
    EntityManager.cpp
    Error.cpp
    HelpDlg.cpp
    Main.cpp
    MainEvents.cpp
    MAPOpener.cpp
    MAPParser.cpp
    MAPReader.cpp
    ResourceManager.cpp
    SkyNames.cpp
    WadFiles.cpp

    Attribute.h
    BatchDlg.h
    BSPFileLoader.h
    BSPManager.h
    BSPOpener.h
    Entity.h
    EntityManager.h
    Error.h
    HelpDlg.h
    Main.h
    MAPOpener.h
    MAPParser.h
    MAPReader.h
    resource.h
    ResourceManager.h
    SkyNames.h
    WadFiles.h

    resource.rc
    )

target_include_directories(res-exporter
    PRIVATE ControlLib/package/include
    PRIVATE DialogsLib
    )

target_compile_features(res-exporter
    PRIVATE cxx_auto_type
    PRIVATE cxx_nullptr
    PRIVATE cxx_range_for
    )

target_link_libraries(res-exporter
    Controls
)

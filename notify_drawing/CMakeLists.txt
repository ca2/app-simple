cmake_minimum_required(VERSION 3.17)
project(app_simple_notify_drawing CXX)


list(APPEND library_source
    _.cpp
    _.h
    application.cpp
    application.h
    framework.cpp
    framework.h
    main_frame.cpp
    main_frame.h
    impact.cpp
    impact.h)


list(APPEND library_references
   acme
   apex
   aqua
   aura
   axis
   base
   app_simple_drawing
   )


add_executable(app_simple_notify_drawing ${library_source})


target_precompile_headers(app_simple_notify_drawing PRIVATE framework.h)


set_target_properties(app_simple_notify_drawing PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(app_simple_notify_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_notify_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_notify_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(app_simple_notify_drawing PRIVATE ${library_references})
elseif(LINUX)
    target_compile_options(app_simple_notify_drawing PRIVATE -fpermissive)
    #target_link_options(app_simple_notify_drawing PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(app_simple_notify_drawing PRIVATE ${library_references}  )
    target_link_options(app_simple_notify_drawing PRIVATE -Wl,-z,defs)
endif()


add_dependencies(app_simple_notify_drawing experience_core)
add_dependencies(app_simple_notify_drawing ${default_draw2d})
add_dependencies(app_simple_notify_drawing ${default_imaging})
add_dependencies(app_simple_notify_drawing ${default_write_text})
add_dependencies(app_simple_notify_drawing ${app_common_dependencies})


target_include_directories(app_simple_notify_drawing PRIVATE .)
target_include_directories(app_simple_notify_drawing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../..)
target_include_directories(app_simple_notify_drawing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/..)
target_include_directories(app_simple_notify_drawing PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})


target_compile_definitions(app_simple_notify_drawing PRIVATE _APP_SIMPLE_NOTIFY_DRAWING_LIBRARY)




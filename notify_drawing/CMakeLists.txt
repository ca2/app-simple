cmake_minimum_required(VERSION 3.16)
project(app_simple_notify_drawing CXX)


list(APPEND library_source
    _.cpp
    _.h
    ##_library.h
    #_factory.cpp
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


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(app_simple_notify_drawing PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(app_simple_notify_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_notify_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_notify_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(app_simple_notify_drawing PRIVATE ${library_references})
elseif(${LINUX} OR ${FREEBSD})
    target_compile_options(app_simple_notify_drawing PRIVATE -fpermissive)
    #target_link_options(app_simple_notify_drawing PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(app_simple_notify_drawing PRIVATE ${library_references}  )
    target_link_options(app_simple_notify_drawing PRIVATE -Wl,-z,defs)
endif()


add_dependencies(app_simple_notify_drawing experience_core)
add_dependencies(app_simple_notify_drawing ${default_draw2d})
add_dependencies(app_simple_notify_drawing ${default_imaging})
add_dependencies(app_simple_notify_drawing ${default_write_text})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_notify_drawing PRIVATE _APP_SIMPLE_NOTIFY_DRAWING_LIBRARY)


add_subdirectory(__implement)


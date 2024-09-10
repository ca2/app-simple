cmake_minimum_required(VERSION 3.16)
project(app_simple_nanoui_example CXX)


list(APPEND library_source
        _.cpp
        _.h
        #_factory.cpp
        ##_library.h
        application.cpp
        application.h
        example1.cpp
        example1.h
        example2.cpp
        example2.h
        example_icons.cpp
        example_icons.h
        #document.cpp
        document.h
        framework.cpp
        framework.h
        #impact.cpp
        main_window.cpp
        main_window.h
        )


list(APPEND library_references
        acme
        apex
        aqua
        aura
        axis
        base
        nanoui
        )


add_library(${PROJECT_NAME} SHARED ${library_source})
add_library(static_${PROJECT_NAME} STATIC ${library_source})


target_precompile_headers(${PROJECT_NAME} PRIVATE framework.h)
target_precompile_headers(static_${PROJECT_NAME} PRIVATE framework.h)


set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(${PROJECT_NAME} PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
    target_link_options(${PROJECT_NAME} PRIVATE "/SUBSYSTEM:WINDOWS")
elseif(${LINUX} OR ${__BSD__})

   target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

    target_compile_options(${PROJECT_NAME} PRIVATE $<$<COMPILE_LANGUAGE:CXX>:-fpermissive  ${EXTRA_CXX_TARGET_COMPILER_OPTIONS}>)
    #target_link_options(${PROJECT_NAME} PRIVATE -Wl,-rpath=$ORIGIN)
    target_link_libraries(${PROJECT_NAME} PRIVATE ${library_references})
    target_link_options(${PROJECT_NAME} PRIVATE -Wl,-z,defs)
endif ()


#add_dependencies(${PROJECT_NAME} experience_core)
#add_dependencies(${PROJECT_NAME} ${default_draw2d})
#add_dependencies(${PROJECT_NAME} ${default_write_text})
#add_dependencies(${PROJECT_NAME} database_sqlite3)


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)

target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})
target_include_directories(static_${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(${PROJECT_NAME} PRIVATE _${PROJECT_NAME}_project)


add_subdirectory(__implement)


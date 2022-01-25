cmake_minimum_required(VERSION 3.16)
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


add_library(app_simple_notify_drawing ${library_source})


target_precompile_headers(app_simple_notify_drawing PRIVATE framework.h)


set_target_properties(app_simple_notify_drawing PROPERTIES LINKER_LANGUAGE CXX)


if (MSVC)
    target_compile_options(app_simple_notify_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_notify_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(app_simple_notify_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(app_simple_notify_drawing PRIVATE ${library_references})
elseif(LINUX OR FREEBSD)
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
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_notify_drawing PRIVATE _APP_SIMPLE_NOTIFY_DRAWING_LIBRARY)


add_executable(_${PROJECT_NAME} operating-system/${SLASHED_OPERATING_SYSTEM}/_${PROJECT_NAME}.cpp)


list(APPEND executable_references
   acme
   apex
   aqua
   aura
   axis
   base
   app_simple_drawing
   app_simple_notify_drawing
   )


if(LINUX OR FREEBSD)
#
#   add_custom_command(
#      COMMAND ${APPLICATION_BUILD_HELPER} ${PROJECT_SOURCE_DIR}
#      COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_BINARY_DIR}/matter.timestamp
#      OUTPUT ${PROJECT_BINARY_DIR}/matter.timestamp
#      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
#      BYPRODUCTS ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o
#      DEPENDS application_matter.txt matter.txt _console_application_build_helper
#      VERBATIM
#      )
#
#   add_custom_target(${PROJECT_NAME}_matter
#      DEPENDS ${PROJECT_BINARY_DIR}/matter.timestamp
#   )
#
list(APPEND executable_references ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o)
#
#   add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_matter)
#
endif()



if (MSVC)


    target_compile_options(_app_simple_notify_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
    target_link_options(_app_simple_notify_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
    target_link_options(_app_simple_notify_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
    target_link_libraries(_app_simple_notify_drawing PRIVATE ${executable_references})


elseif(LINUX OR FREEBSD)


    target_compile_options(_app_simple_notify_drawing PRIVATE -fpermissive)
    target_link_libraries(_app_simple_notify_drawing PRIVATE ${executable_references})
    target_link_options(_app_simple_notify_drawing PRIVATE -Wl,-z,defs)


endif ()


add_dependencies(_${PROJECT_NAME} ${default_draw2d})
add_dependencies(_${PROJECT_NAME} ${default_imaging})
add_dependencies(_${PROJECT_NAME} ${default_write_text})
add_dependencies(_${PROJECT_NAME} ${default_node})
add_dependencies(_${PROJECT_NAME} ${app_common_dependencies})
add_dependencies(_${PROJECT_NAME} crypto_openssl)
add_dependencies(_${PROJECT_NAME} experience_core)
add_dependencies(_${PROJECT_NAME} folder_zip)


target_include_directories(_app_simple_notify_drawing PRIVATE ${library_include_directories})

target_link_directories(_app_simple_notify_drawing PRIVATE ${library_link_directories})

target_link_libraries(_app_simple_notify_drawing PRIVATE acme apex app_simple_notify_drawing)

set_target_properties(_app_simple_notify_drawing PROPERTIES LINKER_LANGUAGE CXX)




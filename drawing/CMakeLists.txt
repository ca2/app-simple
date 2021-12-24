cmake_minimum_required(VERSION 3.17)
project(app_simple_drawing CXX)


list(APPEND library_source
   _.cpp
   _.h
   _app_simple_drawing.h
   application.cpp
   application.h
   document.cpp
   document.h
   framework.cpp
   framework.h
   frame.cpp
   frame.h
   main_frame.cpp
   main_frame.h
   render.cpp
   render.h
   render_1through3.cpp
   render_arcs.cpp
   tab_view.cpp
   tab_view.h
   impact.cpp
   impact.h
   )


add_library(app_simple_drawing SHARED ${library_source})

target_precompile_headers(app_simple_drawing PRIVATE framework.h)

set_target_properties(app_simple_drawing PROPERTIES LINKER_LANGUAGE CXX)


list(APPEND library_references
   acme
   apex
   aqua
   aura
   axis
   base
   )


if (MSVC)

   target_compile_options(app_simple_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(app_simple_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(app_simple_drawing PRIVATE ${library_references})

elseif(LINUX OR FREEBSD)

   target_compile_options(app_simple_drawing PRIVATE -fpermissive)
   #target_link_options(app_simple_drawing PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(app_simple_drawing PRIVATE ${library_references})
   target_link_options(app_simple_drawing PRIVATE -Wl,-z,defs)

endif ()




target_link_directories(app_simple_drawing PRIVATE ${library_link_directories})


list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/../..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR}/..)
list(APPEND library_include_directories ${CMAKE_CURRENT_SOURCE_DIR})


target_include_directories(${PROJECT_NAME} PRIVATE ${library_include_directories})


target_compile_definitions(app_simple_drawing PRIVATE _APP_SIMPLE_DRAWING_LIBRARY)


add_executable(_${PROJECT_NAME} platform/${SLASHED_PLATFORM}/_${PROJECT_NAME}.cpp)


if(LINUX OR FREEBSD)

   add_custom_command(
      COMMAND ${APPLICATION_BUILD_HELPER} ${PROJECT_SOURCE_DIR}
      COMMAND ${CMAKE_COMMAND} -E touch ${PROJECT_BINARY_DIR}/matter.timestamp
      OUTPUT ${PROJECT_BINARY_DIR}/matter.timestamp
      WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
      BYPRODUCTS ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o
      DEPENDS application_matter.txt matter.txt _console_application_build_helper
      VERBATIM
      )

   add_custom_target(${PROJECT_NAME}_matter
      DEPENDS ${PROJECT_BINARY_DIR}/matter.timestamp
   )

   list(APPEND executable_references ${PROJECT_SOURCE_DIR}/.link_object/_matter.zip.o)

   add_dependencies(${PROJECT_NAME} ${PROJECT_NAME}_matter)

endif()



list(APPEND executable_references
   acme
   apex
   aqua
   aura
   axis
   base
   app_simple_drawing)




if (MSVC)

   target_compile_options(_app_simple_drawing PRIVATE "/MD$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_drawing PRIVATE "/DEFAULTLIB:msvcrt$<$<CONFIG:Debug>:d>")
   target_link_options(_app_simple_drawing PRIVATE "/SUBSYSTEM:WINDOWS")
   target_link_libraries(_app_simple_drawing PRIVATE ${executable_references})

elseif(LINUX OR FREEBSD)

   target_compile_options(_app_simple_drawing PRIVATE -fpermissive)
   #target_link_options(_app_simple_drawing PRIVATE -Wl,-rpath=$ORIGIN)
   target_link_libraries(_app_simple_drawing PRIVATE ${executable_references})
   target_link_options(_app_simple_drawing PRIVATE -Wl,-z,defs)

endif ()


add_dependencies(_${PROJECT_NAME} ${default_draw2d})
add_dependencies(_${PROJECT_NAME} ${default_imaging})
add_dependencies(_${PROJECT_NAME} ${default_write_text})
add_dependencies(_${PROJECT_NAME} ${app_common_dependencies})
add_dependencies(_${PROJECT_NAME} ${default_node})
add_dependencies(_${PROJECT_NAME} crypto_openssl)
add_dependencies(_${PROJECT_NAME} experience_core)
add_dependencies(_${PROJECT_NAME} folder_zip)


target_include_directories(_app_simple_drawing PRIVATE ${library_include_directories})

target_link_directories(_app_simple_drawing PRIVATE ${library_link_directories})

set_target_properties(_app_simple_drawing PROPERTIES LINKER_LANGUAGE CXX)




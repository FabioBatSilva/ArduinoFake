include_directories(../src)

file(GLOB cpp_test_files *.cpp)

add_definitions(-DUNIT_TEST)

foreach(filename ${cpp_test_files})

    get_filename_component(target ${filename} NAME_WE)
    add_executable(${target} ${filename})

    set_target_properties(${target} PROPERTIES DEBUG_POSTFIX "-d")
    target_link_libraries(${target} ${PROJECT_NAME} unity)
    add_test(NAME ${target} COMMAND ${target})

endforeach(filename)

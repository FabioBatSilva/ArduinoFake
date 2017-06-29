find_package(Git REQUIRED)

function(execute_git)
    set(options "")
    set(oneValueArgs
        OUTPUT_VARIABLE
    )
    set(multiValueArgs
        COMMAND
    )
    cmake_parse_arguments(args "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    execute_process(
        COMMAND ${GIT_EXECUTABLE} ${args_COMMAND}
        OUTPUT_VARIABLE GIT_RESULT
    )

    set(${args_OUTPUT_VARIABLE} ${GIT_RESULT} PARENT_SCOPE)
endfunction()

function(download_repo)
    set(options "")
    set(oneValueArgs
        URL
        TAG
        CLONE_DIR
    )
    set(multiValueArgs "")
    cmake_parse_arguments(args "${options}" "${oneValueArgs}" "${multiValueArgs}" ${ARGN})

    # If no tag is specified, default to master
    if(NOT args_TAG)
        set(args_TAG master)
    endif()

    execute_git(
        COMMAND rev-parse --show-toplevel
        OUTPUT_VARIABLE GIT_ROOT
    )

    # Need to remove linebreak
    string(STRIP ${GIT_ROOT} GIT_ROOT)

    # Make clone-dir path relative to git-root
    string(REPLACE ${GIT_ROOT}/ "" RELATIVE_CLONE_DIR ${args_CLONE_DIR})

    if(NOT EXISTS ${args_CLONE_DIR})
        message("Cloning branch ${args_TAG} from ${args_URL} into directory ${args_CLONE_DIR}")
        execute_git(
            COMMAND clone --depth=50 --branch=${args_TAG} ${args_URL} ${args_CLONE_DIR}
            WORKING_DIRECTORY ${GIT_ROOT}
        )
    endif()

endfunction()
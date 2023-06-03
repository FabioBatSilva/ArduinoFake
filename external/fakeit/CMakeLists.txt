cmake_minimum_required(VERSION 3.2.2)
project(fakeit VERSION 2.4.0 LANGUAGES CXX)

include(git-download)

set(REPO_DIR ${PROJECT_SOURCE_DIR}/${PROJECT_NAME}-repo)

download_repo(
    URL "https://github.com/eranpeer/FakeIt.git"
    TAG ${PROJECT_VERSION}
    CLONE_DIR ${REPO_DIR}
)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE
    ${REPO_DIR}/single_header/standalone/
)

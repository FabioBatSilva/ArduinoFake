aux_source_directory(. SRC_LIST)
aux_source_directory(./fakeit SRC_LIST)
aux_source_directory(./arduino SRC_LIST)

add_library(${PROJECT_NAME} SHARED ${SRC_LIST})

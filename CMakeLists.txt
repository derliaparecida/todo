cmake_minimum_required(VERSION 3.10)
project(TodoApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adiciona os arquivos fonte
set(SOURCES
    src/main.cpp
    src/models/Usuario.cpp
    src/utils/Database.cpp
    src/controllers/UsuarioController.cpp
)

# Cria o executável
add_executable(todo ${SOURCES})

# Linka com a biblioteca SQLite
find_package(SQLite3 REQUIRED)
if(SQLite3_FOUND)
    target_include_directories(todo PRIVATE ${SQLite3_INCLUDE_DIRS})
    target_link_libraries(todo PRIVATE ${SQLite3_LIBRARIES})
endif()

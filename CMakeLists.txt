cmake_minimum_required(VERSION 3.10)
project(MiniWordle)

set(CMAKE_CXX_STANDARD 11)

# executabilul
add_executable(MiniWordle main.cpp)

# spune compilatorului unde sunt header-ele
target_include_directories(MiniWordle PRIVATE ${CMAKE_SOURCE_DIR})

# spune linkerului unde este libbgi.a
target_link_directories(MiniWordle PRIVATE ${CMAKE_SOURCE_DIR})

# link biblioteci necesare WinBGIm
target_link_libraries(MiniWordle PRIVATE
        ${CMAKE_SOURCE_DIR}/libbgi.a
        gdi32 comdlg32 uuid oleaut32 ole32
)
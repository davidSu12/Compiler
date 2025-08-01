cmake_minimum_required(VERSION 3.26)
project(CompilerImp C)

set(CMAKE_C_STANDARD 11)


option(USE_TOPDOWN "top down" ON)


if (USE_TOPDOWN)
    set(SRC
            src/globalVar/listProduction/topDown/listProduction.c
            src/parser/LL/iterative/parser.c
            src/parser/LL/iterative/stack_production.c
            src/parser/LL/iterative/testStackProduction/testStackProduction.c
            src/parser/LL/iterative/setLabel.c
            src/parser/LL/iterative/testFirst/testFirst.c
            src/parser/LL/iterative/testFollow/testFollow.c
            src/globalVar/listProduction/topDown/parseTable.c
            src/parser/LL/iterative/testParseTable/testParseTable.c
    )
else()

    set(SRC
            src/globalVar/listProduction/bottomUp/listProduction.c
            src/globalVar/listProduction/bottomUp/listProduction.h
            src/parser/LR/items.h
            src/parser/LR/setItems.h
            src/parser/LR/setItems.c
            src/parser/LR/testSetItems/testSetItems.h
            src/parser/LR/testSetItems/testSetItems.c
            src/parser/LR/SLR/parser.c
            src/parser/LR/SLR/parser.h
            src/parser/LR/SLR/testClosure/testClosureFunction.h
            src/parser/LR/SLR/testClosure/testClosureFunction.c
    )
endif()




add_executable(
        CompilerImp
        src/main.c
        src/lexer.c
        src/paths.h
        ${SRC}
)
target_include_directories(CompilerImp
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)
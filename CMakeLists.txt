cmake_minimum_required(VERSION 3.26)
project(CompilerImp C)

set(CMAKE_C_STANDARD 11)


option(USE_TOPDOWN "top down" ON)



if (USE_TOPDOWN)
    set(SRC
            src/parser/LL/predictive/IR/parser.h
            src/parser/LL/predictive/IR/parser.c
            src/parser/LL/predictive/IR/ast.h
            src/parser/LL/predictive/IR/quadruplets.h
            src/parser/LL/predictive/IR/quadruplets.c
            src/parser/LL/predictive/IR/testQuadruplets/testQuadruplets.h
            src/parser/LL/predictive/IR/testQuadruplets/testQuadruplets.c
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
            src/parser/LR/SLR/testClosure/testClosureFunction.h
            src/parser/LR/superSetItems.h
            src/parser/LR/superSetItem.c
            src/parser/LR/testSuperSetItems/testSuperSetItems.h
            src/parser/LR/testSuperSetItems/testSuperSetItems.c
            src/parser/LR/SLR/testGoto/testGoto.h
            src/parser/LR/SLR/testGoto/testGoto.c
            src/parser/LR/CanonicalLR/parser.h
            src/parser/LR/CanonicalLR/parser.c
            src/parser/LR/SLR/testCanonical/testCanonical.h
            src/parser/LR/SLR/testCanonical/testCanonical.c
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
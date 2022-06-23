cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} main.cpp
        game/Game.cpp game/Game.h
        texture/Texture.cpp texture/Texture.h
        board/Board.cpp board/Board.h
        piece/Piece.cpp piece/Piece.h
        piece/Pieces.cpp piece/Pieces.h
        piece/King.cpp piece/King.h
        piece/Pawn.cpp piece/Pawn.h
        piece/Bishop.cpp piece/Bishop.h
        piece/Rook.cpp piece/Rook.h
        piece/Queen.cpp piece/Queen.h
        piece/Knight.cpp piece/Knight.h
        factory/PieceFactory.cpp factory/PieceFactory.h
        factory/Util.h
        event/EventManager.cpp event/EventManager.h
        pair/PairHash.h
        observer/CheckObserver.h observer/CheckObserver.cpp
        undo/UndoManager.cpp undo/UndoManager.h
        actions/MoveAction.cpp actions/MoveAction.h
        actions/Action.h
        actions/State.cpp actions/State.h)

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/actions
        ${CMAKE_SOURCE_DIR}/board
        ${CMAKE_SOURCE_DIR}/event
        ${CMAKE_SOURCE_DIR}/factory
        ${CMAKE_SOURCE_DIR}/game
        ${CMAKE_SOURCE_DIR}/observer
        ${CMAKE_SOURCE_DIR}/pair
        ${CMAKE_SOURCE_DIR}/piece
        ${CMAKE_SOURCE_DIR}/resources
        ${CMAKE_SOURCE_DIR}/texture
        ${CMAKE_SOURCE_DIR}/undo)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2_ttf SDL2_image)
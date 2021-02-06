cmake_minimum_required(VERSION 3.15)
project(Chess)

set(CMAKE_CXX_STANDARD 20)

add_executable(Chess main.cpp game/Game.cpp game/Game.h texture/Texture.cpp texture/Texture.h board/Board.cpp board/Board.h piece/Piece.cpp piece/Piece.h piece/King.cpp piece/King.h piece/Pawn.cpp piece/Pawn.h piece/Bishop.cpp piece/Bishop.h piece/Rook.cpp piece/Rook.h piece/Queen.cpp piece/Queen.h piece/Knight.cpp piece/Knight.h factory/PieceFactory.cpp factory/PieceFactory.h factory/Util.h event/EventManager.cpp event/EventManager.h pair/PairHash.h observer/CheckObserver.h observer/CheckObserver.cpp undo/UndoManager.cpp undo/UndoManager.h actions/MoveAction.cpp actions/MoveAction.h actions/Action.cpp actions/Action.h actions/State.cpp actions/State.h)

target_link_libraries(Chess SDL2 SDL2_ttf SDL2_image)
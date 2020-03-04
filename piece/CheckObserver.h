//
// Created by david on 04. 03. 2020..
//

#ifndef CHESS_CHECKOBSERVER_H
#define CHESS_CHECKOBSERVER_H

#include "Piece.h"

class Pieces;

class ICheckObserver
{
public:
    virtual ~ICheckObserver() = default;

    virtual void update(Pieces *pieces) = 0;
};

class CheckObserver : public ICheckObserver
{
public:
    void update(Pieces *pieces) override;
};

#endif //CHESS_CHECKOBSERVER_H

//
// Created by david on 04. 03. 2020..
//

#ifndef CHESS_CHECKOBSERVER_H
#define CHESS_CHECKOBSERVER_H

#include "../piece/Piece.h"

class Pieces;

/**
 * Interface that represents listener to check event.
 *
 * @author David
 */
class ICheckObserver
{
public:
    virtual ~ICheckObserver() = default;

    /**
     * Method called when event occurs.
     *
     * @param pieces Pointer to all pieces on the board.
     */
    virtual void update(Pieces *pieces) = 0;
};

/**
 * One concrete listener.
 *
 * @author David
 */
class CheckObserver : public ICheckObserver
{
public:
    void update(Pieces *pieces) override;
};


#endif //CHESS_CHECKOBSERVER_H

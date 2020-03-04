//
// Created by david on 04. 03. 2020..
//

#include "CheckObserver.h"
#include "../piece/King.h"

void CheckObserver::update(Pieces *pieces)
{
    for (auto const &piece : pieces->pieces)
    {
        if (piece->getPieceColor() == Game::turn ||
            (!dynamic_cast<King *>(piece.get()) && pieces->pieceAttackKing.size() > 1))
        {
            continue;
        }

        piece->getAvailableMovesCheck(pieces->pieceAttackKing[0]);
    }
}


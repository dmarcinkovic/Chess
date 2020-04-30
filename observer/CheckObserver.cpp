//
// Created by david on 04. 03. 2020..
//

#include "CheckObserver.h"

void CheckObserver::update(Pieces *pieces)
{
    for (auto &piece : pieces->pieces)
    {
        if (piece->getPieceColor() == Game::turn)
        {
            continue;
        }

        // TODO update moves because it is check
    }
}

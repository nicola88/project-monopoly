/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCCAMERACOMMERCIO_H
#define GCCAMERACOMMERCIO_H
#include "GameCore.h"
#include "GCNonEdificabile.h"
#include "GCPlayer.h"

class GCCameraCommercio : public GCNonEdificabile {
public:
    GCCameraCommercio(const QString, GameCore* const, int);
    virtual void sosta(GCPlayer*);
    virtual void transito(GCPlayer*);
};

#endif // GCCAMERACOMMERCIO_H

/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCPOLIZIA_H
#define GCPOLIZIA_H
#include "GCNonEdificabile.h"

class GCPolizia : public GCNonEdificabile {
public:
    GCPolizia(const QString n, GameCore *const cr, int amm, int ren=0);
    virtual void sosta(GCPlayer*);
    virtual void transito(GCPlayer*) {}
private:
    int ammenda;
};

#endif // GCPOLIZIA_H

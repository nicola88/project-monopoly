/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCTRIBUNALE_H
#define GCTRIBUNALE_H
#include "GCNonEdificabile.h"

class GCTribunale : public GCNonEdificabile {
public:
    GCTribunale(const QString n, GameCore *const cr);
    virtual void sosta(GCPlayer*);
};

#endif // GCTRIBUNALE_H

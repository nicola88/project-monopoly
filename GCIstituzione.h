/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCISTITUZIONE_H
#define GCISTITUZIONE_H
#include "GCNonEdificabile.h"
#include<vector>
class GCSocieta;

class GCIstituzione : public GCNonEdificabile {
public:
    GCIstituzione(const QString n, GameCore *const cr, GCSocieta *const soc);
    virtual void aggiornaTask();
    virtual void sosta(GCPlayer*);
    void acquistaQuota(int, GCPlayer*);

private:
    GCSocieta *const societa;
};

#endif // GCISTITUZIONE_H

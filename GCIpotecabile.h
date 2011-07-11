/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCIPOTECABILE_H
#define GCIPOTECABILE_H
#include "GCEdificabile.h"
#include<QString>

class GCIpotecabile : public GCEdificabile {
public:
    GCIpotecabile(const QString n, GameCore* const cr, const int, const int, const int, const int);
    virtual void aggiornaTask();
    bool eliminaGiocatore(GCPlayer*);
    void ipoteca(const int& =10);
    void riscatta(const int& =10);
    virtual void sosta(GCPlayer*);
private:
    const int valoreQuota;
    int quotaIpotecata;
};

#endif // GCIPOTECABILE_H

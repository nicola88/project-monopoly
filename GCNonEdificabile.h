/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCNONEDIFICABILE_H
#define GCNONEDIFICABILE_H
#include "GameCore.h"
#include "GCCasella.h"
#include "GCPlayer.h"

// Municipio - Polizia - Prigione - Tribunale - Sede regionale - Sede provinciale

class GCNonEdificabile : public GCCasella {
public:
    GCNonEdificabile(const QString n, GameCore *const cr, int ren=0);
    virtual void aggiornaTask();
    virtual bool eliminaGiocatore(GCPlayer*);
    virtual int getValore() const;
    virtual void sosta(GCPlayer*);
    int getPedaggio() const;

private:
    int pedaggio; // divisibile per 10 ==> spartizione GCIstituzioni
};

#endif // GCNONEDIFICABILE_H

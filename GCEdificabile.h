/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCEDIFICABILE_H
#define GCEDIFICABILE_H
#include<QString>
#include "GameCore.h"
#include "GCCasella.h"
#include "GCPlayer.h"

class GCEdificabile : public GCCasella {
public:
    GCEdificabile(const QString, GameCore* const cr, const int, const int, const int, const int);
    bool isAlbergo() const;
    bool acquistaVia(GCPlayer*);
    void aggiornaTask(); // VIRTUAL
    bool costruisciAlbergo(); // sse albergo == false;
    bool eliminaGiocatore(GCPlayer*); // VIRTUAL
    int getValore() const; // VIRTUAL
    int pedaggio() const; // dipende da rendita e renditaAlbergo
    void sosta(GCPlayer*); // Overriding di GCCasella::sosta(GameCore*,GCPlayer*)

protected:
    GCPlayer *proprietario;
    const int valore, rendita, valoreAlbergo, renditaAlbergo;
    bool albergo;
};

#endif // GCEDIFICABILE_H

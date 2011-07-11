/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCCASELLA_H
#define GCCASELLA_H
#include<QString>
class GameCore;
class GCPlayer;

// CAMPI: nome - giocatori presenti - azioni disponibili
// METODI: passaggio - sosta - refresh azioni disponibili

class GCCasella { // Classe base astratta
public:
    virtual ~GCCasella() {delete [] task;}
    virtual void aggiornaTask() =0;
    virtual bool eliminaGiocatore(GCPlayer*) =0;
    virtual int getValore() const =0;
    virtual void sosta(GCPlayer*) =0;
    virtual void transito(GCPlayer*) {}
    const QString getName() const;
    void setTask (const int&, const bool& =true);


protected:
    GCCasella(const QString n, GameCore *const cr, int numT=6);
    GameCore *const core;
    const QString nome;
    int numTask;
    bool *task;
};

#endif // GCCASELLA_H

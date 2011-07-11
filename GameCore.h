/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GAMECORE_H
#define GAMECORE_H
#include<QColor>
#include<QObject>
#include<vector>
using std::vector;
#include "GameTable.h"
#include "GameWelcome.h"
#include "GCPlayer.h"
#include "GCCasella.h"

class GameCore : public QObject {
Q_OBJECT
public:
    GameCore(int numG, int numOp);
    GameWelcome *Welcome;
    GameTable *Table;
    GCCasella* getCasella(const unsigned int&) const;
    GCCasella* getCasellaCorrente() const;
    GCPlayer* getGiocatore(const unsigned int&) const;
    GCPlayer* getGiocatoreCorrente() const;
    int getInvestimenti(GCPlayer*) const;
    bool getOpzione(int) const;
    int getTurnoCorrente() const;
    void lanciaDado();
    void muoviGiocatore(const int&, const int&, const int&);
    void terminaPartita();

private:
    vector<GCPlayer*> Giocatore;
    vector<GCCasella*> Percorso;
    int turniTotali, turniRimanenti, giocatoriRimasti, turnoCorrente /* giocatore attivo */;
    const int numGiocatori, numOpzioni, numCaselle;
    vector<QColor> Colore;
    vector<bool> Opzione;

public slots:
    void aggiornaAzioni(bool*);
    void aggiornaQuota(const bool&);
    void aggiornaQuota(const int&, const int&, const int& =10);
    void avanzaTurno(int);
    void creaPartita(QString*, bool*, unsigned int, unsigned int);
    void nuovaPartita();
    void rimuoviGiocatore(GCPlayer*);
    void setCapitale(GCPlayer*, int);
    void setMessagge(const QString&);
    // TASKS
    void acquistaVia();
    void costruisciAlbergo();
    void ipotecaAlbergo();
    void riscattaAlbergo();
    void acquistaQuota();
    void vendiQuota();
};

#endif // GAMECORE_H

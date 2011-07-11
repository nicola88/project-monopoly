/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCPLAYER_H
#define GCPLAYER_H
#include<QColor>
#include<QString>
#include<vector>
#include"ECC_CapitaleInsufficiente.h"
using std::vector;
class GameCore;
class GCEdificabile;

class GCPlayer : QObject {
Q_OBJECT
public:
    GCPlayer(QString, int, QColor, int, GameCore* const);
    bool attivo() const;
    void addPossedimento(GCEdificabile*);
    int capitale() const;
    int deposita(int);
    int getCapitale() const;
    QColor getColore() const;
    int getID() const;
    QString getName() const;
    int getPosizione() const;
    int getTurniAttesa();
    int preleva(int) throw(ECC_CapitaleInsufficiente);
    int setPosizione(const int&);
    void setTurniAttesa(const int&);
    void terminaPartita();
private:
    GameCore *const core;
    QColor color;
    QString nome;
    int liquidi;
    bool inPartita;
    int posizione, numID, turniAttesa;
    vector<GCEdificabile*> possedimenti;
signals:
    void sendCapitale(GCPlayer*, int /*Capitale*/);
};

#endif // GCPLAYER_H

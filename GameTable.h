/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GAMETABLE_H
#define GAMETABLE_H
#include<QWidget>
#include<vector>
#include "GTCasella.h"
#include "GTPlayer.h"
#include "GTStatistiche.h"
#include "GTTask.h"
using std::vector;
class GameCore;
class GCPlayer;

class GameTable : public QWidget {
Q_OBJECT
public:
    GameTable(QString*, unsigned int, unsigned int, GameCore* const, QWidget *parent=0);
    void aggiornaCapitale(GCPlayer* giocatore, const int& denaro);
    void aggiornaMessaggio(const QString&);
    GTPlayer *Player;
    GTStatistiche* Statistiche;
    GTTask *Task;
    vector<GTCasella*> Percorso;

private:
    QLabel *Stato;
    GameCore* const core;
    static int caselleRiga, caselleColonna;
    static int lunghezza;

signals:
    void sendNumber(int);

public slots:
    void showNumber();
    void movePlayer(int, int, int);
};

#endif // GAMETABLE_H

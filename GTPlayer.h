/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GTPLAYER_H
#define GTPLAYER_H
#include<QGroupBox>
#include<QLabel>
#include<QString>
#include<QWidget>
#include<vector>
using std::vector;
class GCPlayer;

class GTPlayer : public QWidget {
public:
    GTPlayer(const int&, QString*, int, QWidget *parent=0);
    void aggiornaCapitale(GCPlayer* giocatore, const int& somma);
private:
    vector<QGroupBox*> Player;
    vector<QLabel*> Money; // Money[i] è il capitale del giocatore (i+1)-esimo
};

#endif // GTPLAYER_H

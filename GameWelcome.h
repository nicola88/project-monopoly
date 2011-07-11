/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GAMEWELCOME_H
#define GAMEWELCOME_H
#include<QDialogButtonBox>
#include<QWidget>
#include<vector>
using std::vector;
class GWOptions;
class GWPlayer;

class GameWelcome : public QWidget {
Q_OBJECT
public:
    GameWelcome(const int&, const int&);

private:
    GWOptions *Options;
    GWPlayer *Player;
    QDialogButtonBox* Buttons;
    QString *Nomi;
    bool *Opzioni;
    unsigned int Capitale, maxTurni;

signals:
    void invioDati(QString *, bool *, unsigned int, unsigned int);

public slots:
    void raccoltaDati();
};

#endif // GAMEWELCOME_H

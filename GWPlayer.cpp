/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include<QVBoxLayout>
#include "GWPlayer.h"

GWPlayer::GWPlayer(const QString& title) : QGroupBox(title)
{
    Nome.push_back(new QLineEdit("Andrea"));
    Nome[0]->setStyleSheet("QLineEdit {border: 2px solid red}");
    Nome.push_back(new QLineEdit("Francesco"));
    Nome[1]->setStyleSheet("QLineEdit {border: 2px solid rgb(255,160,0)}");
    Nome.push_back(new QLineEdit("Nicola"));
    Nome[2]->setStyleSheet("QLineEdit {border: 2px solid blue}");
    Nome.push_back(new QLineEdit("Sara"));
    Nome[3]->setStyleSheet("QLineEdit {border: 2px solid black}");
    for(int i=0; i<4; i++)
    {
        Nome[i]->setToolTip(tr("Il nome del giocatore deve contenere almeno 2 caratteri (esclusi gli spazi)"));
    }

    QVBoxLayout *Layout = new QVBoxLayout();
    vector<QLineEdit*>::iterator it = Nome.begin();
    for(; it<Nome.end(); it++)
    {
        Layout->addWidget(*it);
    }
    setLayout(Layout);
    setAlignment(Qt::AlignCenter);
}

QString GWPlayer::getNome(const int& idGiocatore) const
{
    return (Nome[idGiocatore]->text()).trimmed();
}

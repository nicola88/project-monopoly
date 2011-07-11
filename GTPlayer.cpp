/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GTPlayer.h"
#include "GCPlayer.h"
#include<QHBoxLayout>
#include<QVBoxLayout>

GTPlayer::GTPlayer(const int& numero, QString *Nome, int Cap, QWidget *parent) : QWidget(parent)
{
    QHBoxLayout *Layout = new QHBoxLayout();
    for(int i=0; i<numero; i++)
    {
        Money.push_back(new QLabel());
        Money[i]->setNum(Cap);
        Money[i]->setAlignment(Qt::AlignCenter);

        QVBoxLayout *GBLayout = new QVBoxLayout();
        GBLayout->addWidget(Money[i]);
        GBLayout->setAlignment(Qt::AlignCenter);

        Player.push_back(new QGroupBox(Nome[i]));
        Player[i]->setAlignment(Qt::AlignCenter);
        Player[i]->setLayout(GBLayout);

        Layout->addWidget(Player[i]);
    }

    Player[0]->setStyleSheet("QGroupBox {color: red}");
    Player[1]->setStyleSheet("QGroupBox {color: rgb(255,160,0)}");
    Player[2]->setStyleSheet("QGroupBox {color: blue}");
    Player[3]->setStyleSheet("QGroupBox {color: black}");

    setLayout(Layout);
}

void GTPlayer::aggiornaCapitale(GCPlayer* player, const int& somma)
{
    unsigned int giocatore = player->getID();
    if(giocatore<Money.size())
    {
        Money[giocatore]->setNum(somma);
    }
}

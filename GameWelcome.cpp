/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GameWelcome.h"
#include "GWOptions.h"
#include "GWPlayer.h"
#include<QApplication>
#include<QHBoxLayout>
#include<QMessageBox>
#include<QVBoxLayout>

GameWelcome::GameWelcome(const int& numG, const int& numOp)
{
    Nomi = new QString[numG]; // numG = 4
    Opzioni = new bool[numOp]; // numOp = 4

    Player = new GWPlayer(tr("Lista giocatori"));
    Options = new GWOptions(tr("Opzioni"));
    QHBoxLayout *Body = new QHBoxLayout();
    Body->addWidget(Player);
    Body->addWidget(Options);

    Buttons = new QDialogButtonBox();
    Buttons->setStandardButtons(QDialogButtonBox::Ok|QDialogButtonBox::Cancel);
    Buttons->setOrientation(Qt::Horizontal);

    QVBoxLayout *Window = new QVBoxLayout();
    Window->addLayout(Body);
    Window->addWidget(Buttons);
    setLayout(Window);
    setWindowTitle(tr("Monopoli"));

    connect(Buttons,SIGNAL(accepted()),this,SLOT(raccoltaDati()));
    connect(Buttons,SIGNAL(rejected()),qApp,SLOT(quit()));
}

void GameWelcome::raccoltaDati()
{
    bool invalidName = false;
    for(int i=0; !invalidName  && i<4; i++)
    {
        Nomi[i] = Player->getNome(i);
        if(Nomi[i].size()<2) invalidName =true;
    }
    if(invalidName)
    {
        QMessageBox invalidName ;
        invalidName.setText(tr("Uno o più nomi dei giocatori non sono validi; il nome di ciascun giocatore deve contenere almeno 2 caratteri (esclusi gli spazi)."));
        invalidName.exec();
        invalidName.setIcon(QMessageBox::Warning);
        return;
    }
    Opzioni[0] = Options->isLegale();
    Opzioni[1] = Options->isPrivatizzata();
    Opzioni[2] = Options->isIpoteca();
    Opzioni[3] = Options->isDebug();
    Capitale = Options->getCapitale();
    maxTurni = Options->getTurni();
    emit invioDati(Nomi, Opzioni, Capitale, maxTurni);
}

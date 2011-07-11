/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include<ctime>
#include "GCPlayer.h"
#include "GameTable.h"
#include "GameCore.h"
#include<QGridLayout>

int GameTable::lunghezza = 20;
int GameTable::caselleRiga = 6;
int GameTable::caselleColonna = 6;

GameTable::GameTable(QString* Gio, unsigned int Cap, unsigned int Turni, GameCore *const cr, QWidget *parent) : QWidget(parent), Percorso(lunghezza), core(cr)
{
    Player = new GTPlayer(4,Gio,Cap);
    Statistiche = new GTStatistiche(tr("Statistiche partita"),Turni);
    Task = new GTTask(tr("Azioni"));
    Stato = new QLabel(tr("Benvenuti al gioco del Monopoli. Per iniziare, cliccare sul pulsante \"Prossimo turno\""));
    Stato->setAlignment(Qt::AlignCenter);
    Stato->setWordWrap(true);

    Percorso[0] = new GTCasella(4,core->getCasella(0)->getName(),core->getCasella(0)->getValore(),true);
    for(int i=1; i<lunghezza; i++)
    {
        Percorso[i] = new GTCasella(4,core->getCasella(i)->getName(),core->getCasella(i)->getValore());
    }

    // Layout del tavolo da gioco
    // GridLayout = 12x12 = 6x6 caselle
    QGridLayout *GTLayout = new QGridLayout();
    for (int i=0; i<5; i++) // 1° fila caselle
    {
        GTLayout->addWidget(Percorso[i],0,2*i,2,2); // 1° fila
        GTLayout->addWidget(Percorso[i+5],2*i,10,2,2); // 2° colonna
        GTLayout->addWidget(Percorso[14-i],10,2*(i+1),2,2); // 2° fila
        GTLayout->addWidget(Percorso[19-i],2*(i+1),0,2,2); // 1° colonna
    }

    GTLayout->addWidget(Player,9,2,1,8);
    GTLayout->addWidget(Task,3,7,6,3);
    GTLayout->addWidget(Statistiche,3,2,6,3);
    GTLayout->addWidget(Stato,2,2,1,8);
    setLayout(GTLayout); // OK : Task + Statistiche + Stato

    setMinimumSize(800,600);
    Stato->setStyleSheet("QLabel {border: 1px solid gray}");

    connect(Statistiche->Lancia,SIGNAL(clicked()),this,SLOT(showNumber())); // !!!!!!!!!
    connect(Statistiche->nuovaPartita, SIGNAL(clicked()),cr,SLOT(nuovaPartita()));
    connect(this,SIGNAL(sendNumber(int)),core,SLOT(avanzaTurno(int)));
    connect(Task->getAction(0),SIGNAL(clicked()),core,SLOT(acquistaVia()));
    connect(Task->getAction(1),SIGNAL(clicked()),core,SLOT(costruisciAlbergo()));
    connect(Task->getAction(2),SIGNAL(clicked()),core,SLOT(ipotecaAlbergo()));
    connect(Task->getAction(3),SIGNAL(clicked()),core,SLOT(riscattaAlbergo()));
    connect(Task->getAction(4),SIGNAL(clicked()),core,SLOT(acquistaQuota()));
    connect(Task->getAction(5),SIGNAL(clicked()),core,SLOT(vendiQuota()));
}

void GameTable::aggiornaCapitale(GCPlayer* giocatore, const int& denaro)
{
    Player->aggiornaCapitale(giocatore,denaro);
}

void GameTable::aggiornaMessaggio(const QString& msg)
{
    Stato->setText(msg);
}

void GameTable::showNumber()
{
    int n;
    srand(time(NULL));
    if(core->getOpzione(3))
    {
        n = 1;
    }
    else
    {
        n = 1+rand()%6;
    }
    Statistiche->aggiornaDado(n);
    emit sendNumber(n);
}

void GameTable::movePlayer(int gioc, int from, int to)
{
    Percorso[from]->removeSostaGiocatore(gioc);
    Percorso[to]->addSostaGiocatore(gioc);
}

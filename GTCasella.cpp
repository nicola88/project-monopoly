/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */s

#include "GTCasella.h"
#include<QFont>
#include<QGridLayout>
#include<QHBoxLayout>
#include<QVBoxLayout>

GTCasella::GTCasella(const int& numero, const QString& nm, int value, bool sos, QWidget *parent) : QWidget(parent), PColor(numero), PIcon(numero), inSosta(numero)
{
    // Creazione etichette con nome e valore della casella
    Name = new QLabel(nm);
    Name->setFont(QFont("Helvetica",8,QFont::Bold));
    Valore = new QLabel();
    if(value) Valore->setNum(value);
    for(int i=0; i<numero; i++)
    {
        inSosta[i] = sos;
    }

    // Creazione layout orizzontale in piè di casella
    // Ogni casella rappresenta un giocatore differente
    // Il colore della casella viene scelto nella schermata GameWelcome
    // Icona visibile <=> giocatore fermo nella casella
    QHBoxLayout *FootLayout = new QHBoxLayout();
    PColor[0] = Qt::red;
    PColor[1] = QColor(255,160,0);
    PColor[2] = Qt::blue;
    PColor[3] = Qt::black;
    for(int i=0; i<numero; i++)
    {
        PIcon[i] = new GTGiocatore(PColor[i],inSosta[i]);
        FootLayout->addWidget(PIcon[i]);
    }

    QVBoxLayout *Layout = new QVBoxLayout();
    Albergo = new GTAlbergo(QColor(Qt::white));
    Layout->addWidget(Albergo,0,Qt::AlignCenter);

    Layout->addWidget(Name,0,Qt::AlignCenter);
    Layout->addWidget(Valore,0,Qt::AlignCenter);
    Layout->addLayout(FootLayout);
    setLayout(Layout);
    setStyleSheet("QWidget {background-color: rgb(180,255,170)}");
}

void GTCasella::aggiornaStato(const bool& proprietario, const bool& albergo)
{
    Albergo->setProprietario(proprietario);
    Albergo->setAlbergo(albergo);
}

void GTCasella::removeSostaGiocatore(int gioc)
{
    PIcon[gioc]->setSosta(false);
}

void GTCasella::addSostaGiocatore(int gioc)
{
    PIcon[gioc]->setSosta(true);
}

/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include<QGroupBox>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include "GWOptions.h"

GWOptions::GWOptions(const QString& title) : QGroupBox(title)
{
    Legale = new QCheckBox(tr("Legale"));
    Legale->setToolTip(tr("Il giocatore che sosti sulle caselle Tribunale o Prigione può rimanere fermo per 1+ turni e ripartire dalla Prigione"));
    Privatizzata = new QCheckBox(tr("Privatizzata"));
    Privatizzata->setToolTip(tr("I giocatori possono acquistare quote delle Società (fino al 50%)"));
    Ipoteca = new QCheckBox(tr("Ipoteca"));
    Ipoteca->setToolTip(tr("Il giocatore che possieda alberghi può ipotecarne o riscattarne una quota"));
    Debug = new QCheckBox(tr("Debug"));
    Debug->setToolTip(tr("I giocatori avanzano sul percorso 1 casella alla volta"));

    CapitalLB = new QLabel(tr("Capitale iniziale:"));
    CapitalSB = new QSpinBox();
    CapitalSB->setAlignment(Qt::AlignRight),
    CapitalSB->setRange(100000,1000000);
    CapitalSB->setSingleStep(50000);
    CapitalSB->setToolTip(tr("Capitale assegnato ad ogni giocatore all'inizio della partita"));
    CapitalSB->setValue(250000);

    TurniLB = new QLabel(tr("Turni (massimo):"));
    TurniSB = new QSpinBox();
    TurniSB->setAlignment(Qt::AlignRight);
    TurniSB->setRange(100,1000);
    TurniSB->setSingleStep(50);
    TurniSB->setToolTip(tr("Ogni turno corrisponde al lancio del dado"));
    TurniSB->setValue(250);

    QHBoxLayout *CapLayout = new QHBoxLayout();
    CapLayout->addWidget(CapitalLB);
    CapLayout->addWidget(CapitalSB);
    QHBoxLayout *TurniLayout = new QHBoxLayout();
    TurniLayout->addWidget(TurniLB);
    TurniLayout->addWidget(TurniSB);

    QVBoxLayout *Options = new QVBoxLayout();
    Options->addWidget(Legale);
    Options->addWidget(Privatizzata);
    Options->addWidget(Ipoteca);
    Options->addWidget(Debug);

    QGroupBox *Mode = new QGroupBox(tr("Modalità di gioco"));
    Mode->setLayout(Options);
    Mode->setAlignment(Qt::AlignCenter);

    QVBoxLayout *Main = new QVBoxLayout();
    Main->addWidget(Mode);
    Main->addLayout(CapLayout);
    Main->addLayout(TurniLayout);

    setLayout(Main);
    setAlignment(Qt::AlignCenter);
}

bool GWOptions::isLegale() const
{
    return Legale->isChecked();
}

bool GWOptions::isPrivatizzata() const
{
    return Privatizzata->isChecked();
}

bool GWOptions::isIpoteca() const
{
    return Ipoteca->isChecked();
}

bool GWOptions::isDebug() const
{
    return Debug->isChecked();
}

int GWOptions::getCapitale() const
{
    return CapitalSB->value();
}

int GWOptions::getTurni() const
{
    return TurniSB->value();
}

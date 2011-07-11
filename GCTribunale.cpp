/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GCTribunale.h"
#include<QString>
#include<cstdlib>
#include<ctime>

GCTribunale::GCTribunale(const QString n, GameCore *const cr) : GCNonEdificabile(n,cr) {}

void GCTribunale::sosta(GCPlayer* pl)
{
    aggiornaTask();
    srand(time(NULL));
    int turniAttesa = 1+rand()%6;
    QString msg(core->getGiocatoreCorrente()->getName());
    msg.append(" si deve fermare per ");
    msg.append(QString::number(turniAttesa));
    if(turniAttesa==1) msg.append(" turno");
    else msg.append(" turni");
    msg.append(" e riprenderà dalla Prigione.");
    core->setMessagge(msg);

    pl->setTurniAttesa(turniAttesa);
    core->muoviGiocatore(pl->getID(),pl->getPosizione(),16);
}

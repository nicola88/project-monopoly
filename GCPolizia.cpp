/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */s

#include "GCPolizia.h"
#include "ECC_CapitaleInsufficiente.h"
#include<cstdlib>
#include<ctime>

GCPolizia::GCPolizia(const QString n, GameCore *const cr, int amm, int ren) : GCNonEdificabile(n,cr,ren), ammenda(amm)
{
}

void GCPolizia::sosta(GCPlayer* pl)
{
    aggiornaTask();
    srand(time(NULL));
    int stopTurni = rand()%2;
    if(stopTurni)
    {
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" si deve fermare per 1 turno e pagare un ammenda pari a ");
        msg.append(QString::number(ammenda));

        try { pl->preleva(ammenda); }
        catch(ECC_CapitaleInsufficiente) {core->rimuoviGiocatore(pl); return;}
        pl->setTurniAttesa(stopTurni);
        core->setMessagge(msg);
    }
    else
    {
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" proseguirà normalmente il prossimo turno.");
        core->setMessagge(msg);
    }
}

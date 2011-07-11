/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GCNonEdificabile.h"
#include "ECC_CapitaleInsufficiente.h"

GCNonEdificabile::GCNonEdificabile(const QString n, GameCore *const cr, int ren) : GCCasella(n,cr), pedaggio(ren)
{
}

void GCNonEdificabile::aggiornaTask()
{
    core->aggiornaAzioni(task);
    core->aggiornaQuota(true);
}

bool GCNonEdificabile::eliminaGiocatore(GCPlayer *giocatore)
{
    return false;
}

int GCNonEdificabile::getValore() const
{
    return 0;
}

void GCNonEdificabile::sosta(GCPlayer* pl)
{
    if(pedaggio)
    {
        try { pl->preleva(pedaggio); } catch(ECC_CapitaleInsufficiente)
        {
            QString msg(core->getGiocatoreCorrente()->getName());
            msg.append(" non ha denaro sufficiente per pagare il pedaggio (");
            msg.append(QString::number(pedaggio));
            msg.append("), perciò la sua partita termina qui.");
            core->setMessagge(msg);
            core->rimuoviGiocatore(pl);
            return;
        }
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" deve pagare un pedaggio pari a ");
        msg.append(QString::number(pedaggio));
        core->setMessagge(msg);
    }
    core->aggiornaQuota(true);
    aggiornaTask();
}

int GCNonEdificabile::getPedaggio() const
{
    return pedaggio;
}

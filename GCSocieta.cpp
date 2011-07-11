/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */s

#include "GCSocieta.h"
#include "GCNonEdificabile.h"

GCSocieta::GCSocieta(const QString& n, GameCore *const cr, const int& ped, int qt, int numG) :
        GCNonEdificabile(n,cr,ped), quota(qt), quotaDisponibile(50), quotaGiocatore(numG)
{
    for(int i=0; i<numG; i++)
    {
        quotaGiocatore[i]=0;
    }
}

void GCSocieta::aggiornaTask()
{
    int quotaGiocatoreCorrente = quotaGiocatore[core->getTurnoCorrente()];
    if(quotaGiocatoreCorrente)
    {
        task[5]=false;
        core->aggiornaQuota(0,quotaGiocatoreCorrente,10);
    }
    else
    {
        task[5]=true;
        core->aggiornaQuota(true);
    }
    core->aggiornaAzioni(task);
}

bool GCSocieta::eliminaGiocatore(GCPlayer *giocatore)
{
    int i = giocatore->getID();
    quotaDisponibile += quotaGiocatore[i];
    quotaGiocatore[i]=0;
    return false;
}

void GCSocieta::sosta(GCPlayer* pl)
{
    try { pl->preleva(getPedaggio()); } catch(ECC_CapitaleInsufficiente)
    {
        QString msg(pl->getName());
        msg.append(" non ha denaro sufficiente per pagare il pedaggio, pari a");
        msg.append(QString::number(getPedaggio()));
        core->setMessagge(msg);
        core->rimuoviGiocatore(pl);
    }
    int quotaPedaggio = getPedaggio()/100; // 10% pedaggio
    QString msg;
    msg.append(core->getGiocatoreCorrente()->getName());
    msg.append(" deve pagare un pedaggio pari a ");
    msg.append(QString::number(getPedaggio()));
    msg.append(". ");
    for(unsigned int i=0; i<quotaGiocatore.size(); i++)
    {
        if(quotaGiocatore[i])
        {
            core->getGiocatore(i)->deposita(quotaPedaggio*quotaGiocatore[i]);
            msg.append(core->getGiocatore(i)->getName());
            msg.append(" riceve ");
            msg.append(QString::number(quotaPedaggio*quotaGiocatore[i]));
            msg.append(" (");
            msg.append(QString::number(quotaGiocatore[i]));
            msg.append("%). ");
        }
    }
    if(!msg.isEmpty()) core->setMessagge(msg);
    aggiornaTask();
}

void GCSocieta::acquistaQuota(const int& qt, GCPlayer* pl)
{
    if(qt<=quotaDisponibile) // disponibili quote da acquistare
    {
        try { pl->preleva(qt*quota); } catch(ECC_CapitaleInsufficiente)
        {
            QString msg(core->getGiocatoreCorrente()->getName());
            msg.append(" non ha denaro sufficiente per acquistare ");
            msg.append(QString::number(qt));
            msg.append(" quote (pari a ");
            msg.append(QString::number(qt*quota));
            msg.append(") della Societa.");
            core->setMessagge(msg);
            return;
        }
        quotaDisponibile -= qt;
        quotaGiocatore[pl->getID()] += qt;
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" ha acquistato il ");
        msg.append(QString::number(qt));
        msg.append("% della Societa (pari a ");
        msg.append(QString::number(qt*quota));
        msg.append(").");
        core->setMessagge(msg);
    }
}

void GCSocieta::vendiQuota(const int& qt, GCPlayer* pl)
{
    if(quotaGiocatore[pl->getID()])
    {
        quotaDisponibile += qt;
        quotaGiocatore[pl->getID()] -= qt;
        pl->deposita(qt*quota);
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" ha venduto il ");
        msg.append(QString::number(qt));
        msg.append("% della Societa (pari a ");
        msg.append(QString::number(qt*quota));
        msg.append(").");
        core->setMessagge(msg);
        aggiornaTask();
    }
}

int GCSocieta::getValore() const
{
    return quota*100;
}

int GCSocieta::getQuota() const
{
    return quota*10;
}

int GCSocieta::getQuotaGiocatore(const int& gioc) const
{
    return quotaGiocatore[gioc];
}

int GCSocieta::getQuoteDisponibili() const
{
    return quotaDisponibile;
}

/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "ECC_CapitaleInsufficiente.h"
#include "GCIpotecabile.h"

GCIpotecabile::GCIpotecabile(const QString n, GameCore* const cr, const int val, const int ren, const int valA, const int renA)
    : GCEdificabile(n,cr,val,ren,valA,renA), valoreQuota(valA/100), quotaIpotecata(0)
{
}

void GCIpotecabile::aggiornaTask()
{
    if(proprietario)
    {
        task[0]=true;
        if(core->getGiocatoreCorrente()==proprietario)
        {
            if(albergo)
            {
                task[1]=true;
                // IPOTECA
                if(quotaIpotecata<100) task[2]=false;
                else task[2]=true;
                // RISCATTO
                if(quotaIpotecata) task[3]=false;
                else task[3]=true;
                core->aggiornaQuota(0,100,10);
                core->aggiornaAzioni(task);
                return;
            }
            else
            {
                task[1]=false;
                task[2]=true;
                task[3]=true;
            }
        }
        else { for(int i=1; i<4; i++) {task[i]=true;} }
    }
    else
    {
        task[0]=false;
        for(int i=1; i<4; i++) {task[i]=true;}
    }
    core->aggiornaQuota(true);
    core->aggiornaAzioni(task);
}

bool GCIpotecabile::eliminaGiocatore(GCPlayer* giocatore)
{
    bool modified = false;
    if(GCEdificabile::eliminaGiocatore(giocatore))
    {
        quotaIpotecata=0;
        modified = true;
    }
    return modified;
}

void GCIpotecabile::ipoteca(const int& q)
{
    int quotaDisponibile = 100-quotaIpotecata;
    QString msg;
    if(q <= quotaDisponibile)
    {
        quotaIpotecata += q;
        proprietario->deposita(valoreQuota*q);
        msg.append(proprietario->getName());
        msg.append(" ipoteca il ");
        msg.append(QString::number(q));
        msg.append("% dell'albergo, per un valore pari a ");
        msg.append(QString::number(valoreQuota*q));
    }
    else
    {
        msg.append("Attenzione! Al massimo è possibile ipotecare il ");
        msg.append(QString::number(quotaDisponibile));
        msg.append("% dell'albergo.");
    }

    core->setMessagge(msg);
    aggiornaTask();
}

void GCIpotecabile::riscatta(const int& q)
{
    QString msg;
    if(q<=quotaIpotecata)
    {
        try { proprietario->preleva(valoreQuota*q); }
        catch(ECC_CapitaleInsufficiente)
        {
            msg.append(proprietario->getName());
            msg.append(" non ha denaro sufficiente per riscattare il");
            msg.append(QString::number(q));
            msg.append("% dell'albergo.");
        }
        quotaIpotecata -= q;
        msg.append(proprietario->getName());
        msg.append(" ha riscattato con successo il ");
        msg.append(QString::number(q));
        msg.append("% dell'albergo, pagando ");
        msg.append(QString::number(valoreQuota*q));
        msg.append(".");
    }
    else
    {
        msg.append("Attenzione! Al massimo è possibile riscattare il ");
        msg.append(QString::number(quotaIpotecata));
        msg.append("% dell'albergo.");
    }
    core->setMessagge(msg);
    aggiornaTask();
}

void GCIpotecabile::sosta(GCPlayer *p)
{
    if(proprietario)
    {
        if(p!=proprietario)
        {
            try { p->preleva(pedaggio()); } catch(ECC_CapitaleInsufficiente)
            {
                QString msg(core->getGiocatoreCorrente()->getName());
                msg.append(" non ha denario sufficiente per pagare il pedaggio, pari a ");
                msg.append(QString::number(pedaggio()));
                msg.append(", perciò la sua partita termina qui.");
                core->setMessagge(msg);
                core->rimuoviGiocatore(p);
                return;
            }
            int quotaPosseduta = 100-quotaIpotecata;
            proprietario->deposita(quotaPosseduta*pedaggio()/100);
            QString msg(core->getGiocatoreCorrente()->getName());
            msg.append(" deve pagare un pedaggio pari a ");
            msg.append(QString::number(pedaggio()));
            if(quotaIpotecata)
            {
                msg.append(", di cui ");
                msg.append(proprietario->getName());
                msg.append(" riceve il ");
                msg.append(QString::number(quotaPosseduta));
                msg.append("% (");
                msg.append(QString::number(quotaPosseduta*pedaggio()/100));
                msg.append(").");
            }
            else
            {
                msg.append(" a ");
                msg.append(proprietario->getName());
            }
            core->setMessagge(msg);
        }
        else if(!isAlbergo())
        {
            QString msg(proprietario->getName());
            msg.append(" può costruire un albergo in ");
            msg.append(getName());
            msg.append(" al prezzo di ");
            msg.append(QString::number(valoreAlbergo));
            msg.append(".");
            core->setMessagge(msg);
        }
    }
    else
    {
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" può diventare proprietario di ");
        msg.append(getName());
        msg.append(" al prezzo di ");
        msg.append(QString::number(valore));
        msg.append(".");
        core->setMessagge(msg);
    }
    aggiornaTask();
}

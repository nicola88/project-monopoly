/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GCEdificabile.h"

GCEdificabile::GCEdificabile(const QString nome, GameCore* const cr, const int val, const int ren, const int valA, const int renA)
        : GCCasella(nome,cr), proprietario(0), valore(val), rendita(ren), valoreAlbergo(valA), renditaAlbergo(renA), albergo(false)
{
}

bool GCEdificabile::isAlbergo() const
{
    return albergo;
}

bool GCEdificabile::acquistaVia(GCPlayer *p)
{
    try { p->preleva(valore); }
    catch (ECC_CapitaleInsufficiente)
    {
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" non ha denaro sufficiente per acquistare ");
        msg.append(core->getCasellaCorrente()->getName());
        msg.append(". Transazione annullata.");
        core->setMessagge(msg);
        return false;
    }
    QString msg(core->getGiocatoreCorrente()->getName());
    msg.append(" ha acquistato ");
    msg.append(core->getCasellaCorrente()->getName());
    msg.append(" al costo di ");
    msg.append(QString::number(valore));
    core->setMessagge(msg);
    proprietario = p;
    p->addPossedimento(this);
    setTask(0);
    core->aggiornaAzioni(task);
    return true;
}

void GCEdificabile::aggiornaTask() // (dis)attiva i pulsanti relativi alle azioni nella GameTable
{
    if(proprietario)
    {
        task[0]=true;
        if(!albergo && core->getGiocatoreCorrente()==proprietario) task[1]=false;
        else task[1]=true;
    }
    else // nessun proprietario
    {
        task[0]=false;
        task[1]=true;
    }
    core->aggiornaAzioni(task);
    core->aggiornaQuota(true);
}

bool GCEdificabile::costruisciAlbergo()
{
    try { proprietario->preleva(valoreAlbergo); }
    catch (ECC_CapitaleInsufficiente)
    {
        QString msg(core->getGiocatoreCorrente()->getName());
        msg.append(" non ha denaro sufficiente per costruire l'albergo. Transazione annullata.");
        core->setMessagge(msg);
        return false;
    }
    albergo = true;
    QString msg(proprietario->getName());
    msg.append(" ha costruito un albergo in ");
    msg.append(core->getCasellaCorrente()->getName());
    msg.append(", al prezzo di ");
    msg.append(QString::number(valoreAlbergo));
    core->setMessagge(msg);
    aggiornaTask();
    return true;
}

bool GCEdificabile::eliminaGiocatore(GCPlayer* giocatore)
{
    bool modified = false;
    if(giocatore==proprietario)
    {
        proprietario=0;
        albergo=false;
        modified = true;
    }
    return modified;
}

int GCEdificabile::getValore() const
{
    return valore;
}

int GCEdificabile::pedaggio() const
{
    return rendita + renditaAlbergo*albergo;
}

void GCEdificabile::sosta(GCPlayer* p)
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
            proprietario->deposita(pedaggio());
            QString msg(p->getName());
            msg.append(" deve pagare a ");
            msg.append(proprietario->getName());
            msg.append(" un pedaggio pari a ");
            msg.append(QString::number(pedaggio()));
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


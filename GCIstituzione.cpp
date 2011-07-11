#include "GCIstituzione.h"
#include "GCSocieta.h"
#include "ECC_CapitaleInsufficiente.h"

GCIstituzione::GCIstituzione(const QString n, GameCore *const cr, GCSocieta *const soc)
        : GCNonEdificabile(n,cr), societa(soc) {}

void GCIstituzione::aggiornaTask()
{
    if(societa->getQuoteDisponibili())
    {
        task[4]=false;
        core->aggiornaQuota(0,societa->getQuoteDisponibili(),10);
    }
    else
    {
        task[4]=true;
        core->aggiornaQuota(true);
    }
    core->aggiornaAzioni(task);
}

void GCIstituzione::sosta(GCPlayer* pl)
{
    aggiornaTask();
    if(societa->getQuoteDisponibili())
    {
        QString msg("É disponibile il ");
        msg.append(QString::number(societa->getQuoteDisponibili()));
        msg.append("% della ");
        msg.append(societa->getName());
        msg.append(", acquistabile al prezzo di ");
        msg.append(QString::number(societa->getQuota()));
        msg.append(" per il 10%.");
        core->setMessagge(msg);
    }
}

void GCIstituzione::acquistaQuota(int qt, GCPlayer* pl)
{
    societa->acquistaQuota(qt,pl);
    aggiornaTask();
}

/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GCCameraCommercio.h"

GCCameraCommercio::GCCameraCommercio(const QString n, GameCore * const cr, int cred) : GCNonEdificabile(n,cr,cred)
{
}

void GCCameraCommercio::sosta(GCPlayer *pl)
{
    pl->deposita(getPedaggio());
    QString msg(core->getGiocatoreCorrente()->getName());
    msg.append(" raggiunge la Camera di Commercio e riceve ");
    msg.append(QString::number(getPedaggio()));
    core->setMessagge(msg);
    core->aggiornaQuota(true);
    aggiornaTask();
}

void GCCameraCommercio::transito(GCPlayer* pl)
{
    pl->deposita(getPedaggio());
}

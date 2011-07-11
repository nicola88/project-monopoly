/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GCPlayer.h"
#include "GameCore.h"
#include "GCEdificabile.h"

GCPlayer::GCPlayer(QString nm, int liq, QColor col, int id, GameCore *const cr)
        : core(cr), color(col), nome(nm), liquidi(liq), inPartita(true), posizione(0), numID(id), turniAttesa(0)
{
    connect(this,SIGNAL(sendCapitale(GCPlayer*,int)),core,SLOT(setCapitale(GCPlayer*,int)));
}

int GCPlayer::capitale() const
{
    return liquidi;
}

int GCPlayer::deposita(int somma)
{
    liquidi += somma;
    emit sendCapitale(this,liquidi);
    return liquidi;
}

int GCPlayer::preleva(int somma) throw(ECC_CapitaleInsufficiente)
{
    if(liquidi>=somma) liquidi -= somma;
    else
    {
        throw ECC_CapitaleInsufficiente();
    }
    emit sendCapitale(this,liquidi);
    return liquidi;
}

bool GCPlayer::attivo() const
{
    return inPartita;
}

void GCPlayer::addPossedimento(GCEdificabile* via)
{
    possedimenti.push_back(via);
}

int GCPlayer::getCapitale() const
{
    int capitale = liquidi;
    for(unsigned int i=0; i<possedimenti.size(); i++)
    {
        capitale += possedimenti[i]->getValore(); // consideriamo solo valore terreno
    }
    return capitale;
}

QColor GCPlayer::getColore() const
{
    return color;
}

int GCPlayer::getID() const
{
    return numID;
}

QString GCPlayer::getName() const
{
    return nome;
}

int GCPlayer::getPosizione() const
{
    return posizione;
}

int GCPlayer::getTurniAttesa()
{
    if(turniAttesa)
    {
        turniAttesa--;
        return turniAttesa+1;
    }
    else return turniAttesa;
}

int GCPlayer::setPosizione(const int& p)
{
    posizione = p;
    return posizione;
}

void GCPlayer::setTurniAttesa(const int& wait)
{
    turniAttesa=wait;
}

void GCPlayer::terminaPartita()
{
    inPartita=false;
    preleva(liquidi);
}




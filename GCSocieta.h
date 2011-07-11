/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GCSOCIETA_H
#define GCSOCIETA_H
#include "GCNonEdificabile.h"
class GCIstituzione;

class GCSocieta : public GCNonEdificabile {
public:
    GCSocieta(const QString& n, GameCore *const cr, const int& ped, int qt, int numG=4);
    virtual bool eliminaGiocatore(GCPlayer*);
    int getQuota() const;
    int getQuotaGiocatore(const int&) const;
    int getQuoteDisponibili() const;
    void acquistaQuota(const int&, GCPlayer*);
    void vendiQuota(const int&, GCPlayer*);
    virtual void aggiornaTask();
    virtual int getValore() const;
    virtual void sosta(GCPlayer*);
private:
    int quota, quotaDisponibile; // valore/2 = quota*quotaDisponibile -- 10 quote corrisponenti al 10% valore
    vector<int> quotaGiocatore;
};

#endif // GCSOCIETA_H

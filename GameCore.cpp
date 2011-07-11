/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GameCore.h"
#include "GCCameraCommercio.h"
#include "GCEdificabile.h"
#include "GCIpotecabile.h"
#include "GCIstituzione.h"
#include "GCPolizia.h"
#include "GCSocieta.h"
#include "GCTribunale.h"
#include "GTAlbergo.h"

GameCore::GameCore(int numG, int numOp) : Giocatore(numG), Percorso(20), turniRimanenti(0), giocatoriRimasti(numG), turnoCorrente(-1), numGiocatori(numG), numOpzioni(numOp),
        numCaselle(20), Colore(numG), Opzione(numOp)
{
    Colore[0] = Qt::red;
    Colore[1] = QColor(255,160,0);
    Colore[2] = Qt::blue;
    Colore[3] = Qt::black;
    Welcome = new GameWelcome(numGiocatori,numOpzioni);
    Welcome->show();

    connect(Welcome,SIGNAL(invioDati(QString*, bool*, unsigned int, unsigned int)),this,SLOT(creaPartita(QString*, bool*, unsigned int, unsigned int)));
}

void GameCore::creaPartita(QString *Gio, bool *Op, unsigned int Cap, unsigned int Turni)
{
    Welcome->hide();
    turniTotali = turniRimanenti = Turni; // reset variabili di gioco

    // Creazione profili giocatori
    for(int i=0; i<numGiocatori; i++)
    {
        Giocatore[i] = new GCPlayer(Gio[i],Cap,Colore[i],i,this);
        Opzione[i] = Op[i];
    }

    // Creazione del percorso logico
    Percorso[0] = new GCCameraCommercio((tr("Camera di Commercio")),this,15000);
    Percorso[16] = new GCNonEdificabile(tr("Prigione"),this);
    if(Opzione[0]) // LEGALE
    {
        Percorso[12] = new GCTribunale(tr("Tribunale"),this);
        Percorso[19] = new GCPolizia(tr("Polizia"),this,4500);
    }
    else
    {
        Percorso[12] = new GCNonEdificabile(tr("Tribunale"),this);
        Percorso[19] = new GCNonEdificabile(tr("Polizia"),this);
    }

    if(Opzione[1]) // PRIVATIZZATA
    {
        Percorso[4] = new GCSocieta(tr("Soc. Elettrica"),this,3200,500);
        Percorso[7] = new GCSocieta(tr("Soc. Acqua Potabile"),this,3000,600);
        Percorso[17] = new GCSocieta(tr("Stazione Ferroviaria"),this,2500,450);
        Percorso[5] = new GCIstituzione(tr("Municipio"),this,dynamic_cast<GCSocieta*>(Percorso[7]));
        Percorso[10] = new GCIstituzione(tr("Sede Regionale"),this,dynamic_cast<GCSocieta*>(Percorso[4]));
        Percorso[15] = new GCIstituzione(tr("Sede Provinciale"),this,dynamic_cast<GCSocieta*>(Percorso[17]));
    }
    else
    {
        Percorso[4] = new GCNonEdificabile(tr("Soc. Elettrica"),this,3200);
        Percorso[5] = new GCNonEdificabile(tr("Municipio"),this);
        Percorso[7] = new GCNonEdificabile(tr("Soc. Acqua Potabile"),this,3000);
        Percorso[10] = new GCNonEdificabile(tr("Sede Regionale"),this);
        Percorso[15] = new GCNonEdificabile(tr("Sede Provinciale"),this);
        Percorso[17] = new GCNonEdificabile(tr("Stazione Ferroviaria"),this,2500);
    }

    if(Opzione[2]) // IPOTECA
    {
        Percorso[1] = new GCIpotecabile(tr("Viale Traiano"),this,26000,2600,13000,3500);
        Percorso[2] = new GCIpotecabile(tr("Piazza G. Cesare"),this,36000,3600,17000,4600);
        Percorso[3] = new GCIpotecabile(tr("Viale Costantino"),this,24000,2300,12000,3000);
        Percorso[6] = new GCIpotecabile(tr("Corso Leopardi"),this,30000,3000,13000,3800);
        Percorso[8] = new GCIpotecabile(tr("Via U. Foscolo"),this,20000,2000,9000,2600);
        Percorso[9] = new GCIpotecabile(tr("Via A. Manzoni"),this,18000,2000,10000,2600);
        Percorso[11] = new GCIpotecabile(tr("Corso Garibaldi"),this,35000,3700,15000,4500);
        Percorso[13] = new GCIpotecabile(tr("Corso Napoleone"),this,28000,2700,12000,3300);
        Percorso[14] = new GCIpotecabile(tr("Via Roma"),this,23000,2400,11000,3000);
        Percorso[18] = new GCIpotecabile(tr("Piazza Dante"),this,25000,2500,11000,3300);
    }
    else
    {
        Percorso[1] = new GCEdificabile(tr("Viale Traiano"),this,26000,2600,13000,3500);
        Percorso[2] = new GCEdificabile(tr("Piazza G. Cesare"),this,36000,3600,17000,4600);
        Percorso[3] = new GCEdificabile(tr("Viale Costantino"),this,24000,2300,12000,3000);
        Percorso[6] = new GCEdificabile(tr("Corso Leopardi"),this,30000,3000,13000,3800);
        Percorso[8] = new GCEdificabile(tr("Via U. Foscolo"),this,20000,2000,9000,2600);
        Percorso[9] = new GCEdificabile(tr("Via A. Manzoni"),this,18000,2000,10000,2600);
        Percorso[11] = new GCEdificabile(tr("Corso Garibaldi"),this,35000,3700,15000,4500);
        Percorso[13] = new GCEdificabile(tr("Corso Napoleone"),this,28000,2700,12000,3300);
        Percorso[14] = new GCEdificabile(tr("Via Roma"),this,23000,2400,11000,3000);
        Percorso[18] = new GCEdificabile(tr("Piazza Dante"),this,25000,2500,11000,3300);
    }

    Table = new GameTable(Gio,Cap,Turni,this);
    Table->show();
    Percorso[0]->aggiornaTask();
}

void GameCore::nuovaPartita()
{
    delete Table;
    turnoCorrente=-1;
    giocatoriRimasti=numGiocatori;
    Welcome->show();
}

GCCasella* GameCore::getCasella(const unsigned int& casella) const
{
    GCCasella* pointer=0;
    if(casella<Percorso.size())
    {
        pointer = Percorso[casella];
    }
    return pointer;
}

GCCasella* GameCore::getCasellaCorrente() const
{
    int pos = Giocatore[turnoCorrente]->getPosizione();
    return Percorso[pos];
}

GCPlayer* GameCore::getGiocatore(const unsigned int& gid) const
{
    GCPlayer* pointer=0;
    if(gid<Giocatore.size())
    {
        pointer = Giocatore[gid];
    }
    return pointer;
}

GCPlayer* GameCore::getGiocatoreCorrente() const
{
    return Giocatore[turnoCorrente];
}

int GameCore::getInvestimenti(GCPlayer *giocatore) const // if Opzione[1] return ... else return 0
{
    int investimenti=0, valoreQuota=0, numQuote=0, pos[3]={4,7,17};
    GCSocieta* societa;
    for(int i=0; i<3; i++)
    {
        societa = dynamic_cast<GCSocieta*>(Percorso[pos[i]]);
        if(societa)
        {
            valoreQuota = societa->getQuota();
            numQuote = societa->getQuotaGiocatore(giocatore->getID());
            investimenti += valoreQuota*numQuote;
        }
    }
    return investimenti;
}

bool GameCore::getOpzione(int i) const
{
    return Opzione[i];
}

int GameCore::getTurnoCorrente() const
{
    return turnoCorrente;
}

void GameCore::lanciaDado()
{
    Table->showNumber();
}

void GameCore::muoviGiocatore(const int& gioc, const int& from, const int& to)
{
    Table->movePlayer(gioc,from,to);
    Giocatore[gioc]->setPosizione(to);
}

void GameCore::terminaPartita() // if giocatoriRimasti==1 ... else ...
{
    Table->Statistiche->Lancia->setDisabled(true);
    bool *task = new bool[6];
    for(int i=0; i<6; i++) {task[i]=true;}
    aggiornaAzioni(task);
    delete[] task;

    int Capitale[numGiocatori];
    bool exAequo[numGiocatori];
    for(int k=0; k<numGiocatori; k++)
    {
        Capitale[k]=0;
        exAequo[k]=false;
    }
    int maxG=0, numExAequo=0;
    // Trovo il giocatore con capitale maggiore
    for(int i=0; i<numGiocatori; i++)
    {
        Capitale[i] += Giocatore[i]->getCapitale();
        if(Opzione[1]) Capitale[i] += getInvestimenti(Giocatore[i]);
        if(Giocatore[i]->attivo() && Capitale[i]>=Capitale[maxG]) {maxG=i;}
    }
    // Controllo se ci sono giocatori a pari merito
    QString lista;
    for(int j=0; j<numGiocatori; j++)
    {
        if(Giocatore[j]->attivo() && Capitale[j]==Capitale[maxG])
        {
            lista.append(Giocatore[j]->getName());
            lista.append(" (");
            lista.append(QString::number(Capitale[j]));
            lista.append(") - ");
            exAequo[j]=true;
            numExAequo++;
        }
    }
    lista.remove(lista.size()-3,3);    
    QString msg;
    if(numExAequo>1) msg.append(tr("VINCITORI (ex aequo): "));
    else msg.append(tr("VINCITORE: "));
    msg.append(lista);
    setMessagge(msg);
}

// SIGNALS & SLOT

void GameCore::aggiornaAzioni(bool* task)
{
    for(int i=0; i<6; i++)
    {
        Table->Task->setActionDisabled(i,task[i]);
    }
}

void GameCore::aggiornaQuota(const bool& disable)
{
    Table->Statistiche->disabilitaQuote(disable);
}

void GameCore::aggiornaQuota(const int& min, const int& max, const int& step)
{
    Table->Statistiche->aggiornaQuote(min,max,step);
}

void GameCore::avanzaTurno(int dado)
{
    if(!turniRimanenti-- || giocatoriRimasti==1) {terminaPartita(); return;}

    // Individua il prossimo giocatore: turniAttesa + attivo + unico rimasto
    do {turnoCorrente = (turnoCorrente+1)%numGiocatori;}
    while(!Giocatore[turnoCorrente]->attivo() || Giocatore[turnoCorrente]->getTurniAttesa());

    // Sposta il giocatore
    int currPosizione = Giocatore[turnoCorrente]->getPosizione();
    int nuovaPosizione = (currPosizione + dado) % numCaselle;
    if (nuovaPosizione < currPosizione)
    {
        for(int i=currPosizione+1; i<numCaselle; i++) {Percorso[i]->transito(Giocatore[turnoCorrente]);}
        for(int i=0; i<nuovaPosizione; i++) {Percorso[i]->transito(Giocatore[turnoCorrente]);}
    }
    else
    {
        for(int i=currPosizione+1; i<nuovaPosizione; i++) {Percorso[i]->transito(Giocatore[turnoCorrente]);}
    }
    Giocatore[turnoCorrente]->setPosizione(nuovaPosizione);
    muoviGiocatore(turnoCorrente,currPosizione,nuovaPosizione);
    Table->Statistiche->aggiornaPartita(turniTotali-turniRimanenti);
    Table->Statistiche->aggiornaTurno(Giocatore[turnoCorrente]->getName(),Percorso[nuovaPosizione]->getName());

    QString msg(Giocatore[turnoCorrente]->getName());
    msg.append(" avanza di ");
    msg.append(QString::number(dado));
    if(dado==1) msg.append(" casella ");
    else msg.append(" caselle ");
    msg.append("e raggiunge ");
    msg.append(Percorso[nuovaPosizione]->getName());
    setMessagge(msg);
    Percorso[nuovaPosizione]->sosta(Giocatore[turnoCorrente]);
}

void GameCore::rimuoviGiocatore(GCPlayer *giocatore)
{
    int pos = giocatore->getPosizione();

    // UPDATE LOGICO : investimenti
    giocatore->terminaPartita();

    // UPDATE GRAFICO : investimenti controllo 1 a 1 - proprietà ottenute da GCPlayer
    for(int i=0; i<numCaselle; i++)
    {
        if(Percorso[i]->eliminaGiocatore(giocatore))
        {
            Table->Percorso[i]->aggiornaStato();
        }
    }
    Table->Percorso[pos]->removeSostaGiocatore(giocatore->getID());
    Table->update();
    
    giocatoriRimasti--;
    if(giocatoriRimasti==1) {terminaPartita(); return;}
}

void GameCore::setCapitale(GCPlayer* giocatore, int denaro)
{
    Table->aggiornaCapitale(giocatore,denaro);
}

void GameCore::setMessagge(const QString& messagge)
{
    Table->aggiornaMessaggio(messagge);
}

// TASK SLOT

void GameCore::acquistaVia()
{
    int numCasella = Giocatore[turnoCorrente]->getPosizione();
    GCEdificabile *via = dynamic_cast<GCEdificabile*>(Percorso[numCasella]);
    if(via && via->acquistaVia(Giocatore[turnoCorrente]))
    {
        Table->Percorso[numCasella]->Albergo->setColore(Colore[turnoCorrente]);
        Table->Percorso[numCasella]->Albergo->setProprietario(true);
    }
}

void GameCore::costruisciAlbergo()
{
    int numCasella = Giocatore[turnoCorrente]->getPosizione();
    GCEdificabile *via = dynamic_cast<GCEdificabile*>(Percorso[numCasella]);
    if(via && via->costruisciAlbergo())
    {
        Table->Percorso[numCasella]->Albergo->setAlbergo(true);
    }
}

void GameCore::ipotecaAlbergo()
{
    int numCasella = Giocatore[turnoCorrente]->getPosizione();
    GCIpotecabile *via = dynamic_cast<GCIpotecabile*>(Percorso[numCasella]);
    if(via) {via->ipoteca(Table->Statistiche->getQuote());} // QUANTE QUOTE ???
}

void GameCore::riscattaAlbergo()
{
    int numCasella = Giocatore[turnoCorrente]->getPosizione();
    GCIpotecabile *via = dynamic_cast<GCIpotecabile*>(Percorso[numCasella]);
    if(via) {via->riscatta(Table->Statistiche->getQuote());} // QUANTE QUOTE ???
}

void GameCore::acquistaQuota()
{
    int numCasella = Giocatore[turnoCorrente]->getPosizione();
    GCIstituzione *via = dynamic_cast<GCIstituzione*>(Percorso[numCasella]);
    if(via) {via->acquistaQuota(Table->Statistiche->getQuote(),Giocatore[turnoCorrente]);}
}

void GameCore::vendiQuota()
{
    int numCasella = Giocatore[turnoCorrente]->getPosizione();
    GCSocieta *via = dynamic_cast<GCSocieta*>(Percorso[numCasella]);
    if(via) {via->vendiQuota(Table->Statistiche->getQuote(),Giocatore[turnoCorrente]);}
}

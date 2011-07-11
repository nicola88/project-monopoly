/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GTCASELLA_H
#define GTCASELLA_H
#include<QLabel>
#include<QWidget>
#include<vector>
using std::vector;
#include "GTAlbergo.h"
#include "GTGiocatore.h"

// GTCasella modella la casella grafica del percorso del Monopoli
// Intestazione <=> edificabile == true
// - Proprietario : icona semitrasparente
// - Albergo : icona visibile
// Corpo
// - Name (QLabel) : nome della via/società/istituzione
// - Valore (QLabel) : valore d'acquisto / azionario privatizzabile
// Piè di casella
// - PIcon : icone giocatori visibili <=> giocatore in sosta sulla casella
// - PColor : colore dell'icona

class GTCasella : public QWidget {
public:
    GTCasella(const int& numero /*Giocatori*/, const QString& nm, int value, bool sos=false, QWidget *parent=0);
    void addSostaGiocatore(int);
    void aggiornaStato(const bool& =false, const bool& =false);
    void removeSostaGiocatore(int);
    GTAlbergo *Albergo;
private:
    QLabel *Name, *Valore;
    vector<QColor> PColor; // Colori icone giocatori
    vector<GTGiocatore*> PIcon; // Icone circolari giocatori
    vector<bool> inSosta;
};

#endif // GTCASELLA_H

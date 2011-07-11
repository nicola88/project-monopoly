/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GTSTATISTICHE_H
#define GTSTATISTICHE_H
#include<QGroupBox>
#include<QLabel>
#include<QLCDNumber>
#include<QProgressBar>
#include<QPushButton>
#include<QSpinBox>
#include<QString>

class GTStatistiche : public QGroupBox {
public:
    GTStatistiche(const QString& name, const int& turni, QWidget* parent=0);
    void aggiornaDado(const int&);
    void aggiornaPartita(const int&);
    void aggiornaQuote(const int&, const int&, const int&);
    void aggiornaTurno(const QString&, const QString&);
    void disabilitaQuote(const bool&);
    int getQuote() const;
    QPushButton *Lancia, *nuovaPartita, *terminaPartita; // pubblici per SIGNAL-SLOT
private:
    QLCDNumber *Numero;
    QLabel *infoTurno, *cambiaPartita, *turnoAttuale, *casellaAttuale;
    QProgressBar *avanzamentoTurni;
    QSpinBox *quote;
};

#endif // GTSTATISTICHE_H

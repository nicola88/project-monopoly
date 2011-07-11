/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GTStatistiche.h"
#include<QApplication>
#include<QHBoxLayout>

GTStatistiche::GTStatistiche(const QString& name, const int& turni, QWidget* parent) : QGroupBox(name,parent)
{
    Lancia = new QPushButton(tr("Prossimo turno"));
    Numero = new QLCDNumber(1);
    Numero->setSegmentStyle(QLCDNumber::Flat);
    Numero->setMaximumHeight(60);
    avanzamentoTurni = new QProgressBar();
    avanzamentoTurni->setMinimum(0);
    avanzamentoTurni->setMaximum(turni);
    avanzamentoTurni->setFormat("Turno: %v/%m");
    avanzamentoTurni->setStyleSheet("QProgressBar {border: 1px solid grey; border-radius: 2px; text-align:center;} QProgressBar::chunck {margin: 2.5px;}");

    infoTurno = new QLabel(tr("Turno corrente"));
    infoTurno->setStyleSheet("QLabel {background: rgb(180,255,170); border-radius: 8px; font-weight: bold; max-height: 20px}");
    infoTurno->setAlignment(Qt::AlignCenter);
    turnoAttuale = new QLabel("Giocatore");
    turnoAttuale->setStyleSheet("QLabel {border: 1px solid gray; border-radius: 4px}");
    turnoAttuale->setAlignment(Qt::AlignCenter);
    casellaAttuale = new QLabel("Camera di Commercio");
    casellaAttuale->setStyleSheet("QLabel {border: 1px solid gray; border-radius: 4px}");
    casellaAttuale->setAlignment(Qt::AlignCenter);

    QHBoxLayout *quoteLayout = new QHBoxLayout();
    QLabel *quoteDscr = new QLabel(tr("Quote disponibili: "));
    quote = new QSpinBox();
    quote->setSingleStep(10);
    quote->setSuffix(tr("%"));
    quote->setValue(10);
    quote->setDisabled(true);
    quoteLayout->addWidget(quoteDscr);
    quoteLayout->addWidget(quote);

    cambiaPartita = new QLabel(tr("Partita"));
    cambiaPartita->setAlignment(Qt::AlignCenter);
    cambiaPartita->setStyleSheet("QLabel {background: rgb(180,255,170); border-radius: 8px; font-weight: bold; max-height: 20px}");
    nuovaPartita = new QPushButton(tr("Nuova partita"));
    terminaPartita = new QPushButton(tr("Termina partita"));    

    QVBoxLayout* Stat = new QVBoxLayout();
    Stat->addWidget(Numero);
    Stat->addWidget(Lancia);
    Stat->addWidget(avanzamentoTurni);
    Stat->addWidget(infoTurno);
    Stat->addWidget(turnoAttuale);
    Stat->addWidget(casellaAttuale);
    Stat->addLayout(quoteLayout);
    Stat->addWidget(cambiaPartita);
    Stat->addWidget(nuovaPartita);
    Stat->addWidget(terminaPartita);

    setAlignment(Qt::AlignCenter);
    setLayout(Stat);

    connect(terminaPartita,SIGNAL(clicked()),qApp,SLOT(quit()));
}

// GIOCATORE ATTIVO - PROSSIMO TURNO -- TURNI RIMANENTI

void GTStatistiche::aggiornaDado(const int& numero)
{
    this->Numero->display(numero);
}

void GTStatistiche::aggiornaPartita(const int& turniGiocati)
{
    this->avanzamentoTurni->setValue(turniGiocati);
}

void GTStatistiche::aggiornaQuote(const int& min, const int& max, const int& step)
{
    quote->setEnabled(true);
    quote->setRange(min,max);
    quote->setSingleStep(step);
    quote->setValue(min+step);
}

void GTStatistiche::aggiornaTurno(const QString& giocatore, const QString& posizione)
{
    turnoAttuale->setText(giocatore);
    casellaAttuale->setText(posizione);
}

void GTStatistiche::disabilitaQuote(const bool& disable)
{
    quote->setValue(0);
    quote->setDisabled(disable);
}

int GTStatistiche::getQuote() const
{
    return quote->value();
}

/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GTGIOCATORE_H
#define GTGIOCATORE_H
#include<QWidget>

// GTGiocatore modella l'icona del giocatore in una casella GTCasella
// L'icona di un giocatore si caratterizza per:
// - un colore (QColor color)
// - visibilità (bool sosta) <=> giocatore sosta su una data casella

class GTGiocatore : public QWidget {
public:
    GTGiocatore(QColor, bool, QWidget *parent=0);
    void setSosta(bool);
protected:
    void paintEvent(QPaintEvent *);
private:
    QColor color;
    bool sosta;
};

#endif // GTGIOCATORE_H

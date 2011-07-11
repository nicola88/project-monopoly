/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GTGiocatore.h"
#include<QPainter>
#include<QRect>

GTGiocatore::GTGiocatore(QColor col, bool sos, QWidget *parent) : QWidget(parent), sosta(sos)
{
    color = col;
    setFixedSize(20,20);
}

void GTGiocatore::paintEvent(QPaintEvent * painting)
{
    if(sosta)
    {
        QPainter painter(this);
        painter.setBrush(color); //QBrush
        painter.drawEllipse(0,0,15,15);
    }
}

void GTGiocatore::setSosta(bool sos)
{
    sosta = sos;
    update();
}


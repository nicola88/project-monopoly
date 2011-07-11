/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GTAlbergo.h"
#include<QBrush>
#include<QLinearGradient>
#include<QPainter>
#include<QRect>

GTAlbergo::GTAlbergo(const QColor& col)
{
    color = col;
    presente = false;
    owner = false;
    setFixedSize(30,20); // 150,20
}

void GTAlbergo::paintEvent(QPaintEvent *painting)
{
    if(owner)
    {
        QPainter painter(this);
        painter.setBrush(color); // Usa colore giocatore proprietario
        if(!presente) painter.setOpacity(0.3);
        painter.drawRoundRect(QRect(0,0,25,15));
    }
}

void GTAlbergo::setAlbergo(bool alb)
{
    presente = alb;
    update();
}

void GTAlbergo::setColore(const QColor& col)
{
    color = col;
}

void GTAlbergo::setProprietario(bool prop)
{
    owner = prop;
    update();
}

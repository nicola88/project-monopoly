/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GTTask.h"
#include<QVBoxLayout>

GTTask::GTTask(const QString& title, QWidget *parent) : QGroupBox(title,parent), Azione(6)
{
    Edificabile = new QLabel(tr("Edificabile"));
    Edificabile->setAlignment(Qt::AlignCenter);
    Edificabile->setStyleSheet("QLabel {background: rgb(180,255,170); border-radius: 8px; font-weight: bold; max-height: 20px}");
    Azione[0] = new QPushButton(tr("Acquista via"));
    Azione[1] = new QPushButton(tr("Costruisci albergo"));
    Azione[2] = new QPushButton(tr("Ipoteca"));
    Azione[3] = new QPushButton(tr("Riscatta"));

    NonEdificabile = new QLabel(tr("Non edificabile"));
    NonEdificabile->setAlignment(Qt::AlignCenter);
    NonEdificabile->setStyleSheet("QLabel {background: rgb(180,255,170); border-radius: 8px; font-weight: bold; max-height: 20px}");
    Azione[4] = new QPushButton(tr("Acquista quota"));
    Azione[5] = new QPushButton(tr("Vendi quota"));

    QVBoxLayout *Layout = new QVBoxLayout();
    Layout->addWidget(Edificabile);
    for(int i=0; i<4; i++) {Layout->addWidget(Azione[i]);}
    Layout->addWidget(NonEdificabile);
    for(int i=4; i<6; i++) {Layout->addWidget(Azione[i]);}
    setLayout(Layout);
    setAlignment(Qt::AlignCenter);
}

QPushButton* GTTask::getAction(const unsigned int& index) const
{
    if(index < Azione.size())
    {
        return Azione[index];
    }
    else return 0;
}

void GTTask::setActionDisabled(const unsigned int& index, const bool& disable)
{
    if(index < Azione.size())
    {
        Azione[index]->setDisabled(disable);
    }
}

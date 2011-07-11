/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GWPlayerForm.h"

GWPlayerForm::GWPlayerForm(QString Id, QString NameField)
{
    QHBoxLayout *Player = new QHBoxLayout();
    Numero = new QLabel(Id);
    Nome = new QLineEdit(NameField);
    Player->addWidget(Numero);
    Player->addWidget(Nome);
    setLayout(Player);
}

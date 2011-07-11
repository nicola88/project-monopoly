/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GWPLAYERFORM_H
#define GWPLAYERFORM_H
#include<QHBoxLayout>
#include<QLabel>
#include<QLineEdit>
#include<QString>
#include<QWidget>

class GWPlayerForm : public QWidget {
public:
    GWPlayerForm(QString, QString);
    QLabel *Numero;
    QLineEdit *Nome;
};

#endif // GWPLAYERFORM_H

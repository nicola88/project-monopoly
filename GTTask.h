/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GTTASK_H
#define GTTASK_H
#include<QButtonGroup>
#include<QGroupBox>
#include<QLabel>
#include<QPushButton>
#include<QString>
#include<QWidget>
#include<vector>
using std::vector;

class GTTask : public QGroupBox {
public:
    GTTask(const QString& title, QWidget *parent=0);
    QPushButton* getAction(const unsigned int&) const;
    void setActionDisabled(const unsigned int&, const bool&);
private:
    QLabel *Edificabile, *NonEdificabile;
    vector<QPushButton*> Azione;
};

#endif // GTTASK_H

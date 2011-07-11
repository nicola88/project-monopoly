/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GWOPTIONS_H
#define GWOPTIONS_H
#include<QCheckBox>
#include<QGroupBox>
#include<QLabel>
#include<QSpinBox>
#include<QString>

class GWOptions : public QGroupBox {
public:
    GWOptions(const QString&);
    bool isLegale() const;
    bool isPrivatizzata() const;
    bool isIpoteca() const;
    bool isDebug() const;
    int getCapitale() const;
    int getTurni() const;
private:
    QCheckBox *Legale, *Privatizzata, *Ipoteca, *Debug;
    QLabel *CapitalLB, *TurniLB;
    QSpinBox *CapitalSB, *TurniSB;
};

#endif // GWOPTIONS_H

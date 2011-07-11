/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GWPLAYER_H
#define GWPLAYER_H
#include<QGroupBox>
#include<QLineEdit>
#include<vector>
using namespace std;

class GWPlayer : public QGroupBox {
public:
    GWPlayer(const QString&);
    QString getNome(const int&) const;
private:
    vector<QLineEdit*> Nome;
};

#endif // GWPLAYER_H

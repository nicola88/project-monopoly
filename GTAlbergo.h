/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef GTALBERGO_H
#define GTALBERGO_H
#include<QColor>
#include<QPaintEvent>
#include<QWidget>

// GTAlbergo modella l'icona dell'albergo creato in una casella
// L'icona viene creata <=> casella è edificabile (bool edificabile)
// L'icona viene mostrata <=> un albergo è stato costruito

class GTAlbergo : public QWidget {
Q_OBJECT
public:
    GTAlbergo(const QColor&);
    void setColore(const QColor&);
    void setProprietario(bool);
    void setAlbergo(bool);

protected:
    void paintEvent(QPaintEvent *);

private:
    QColor color;
    bool presente, owner;
};

#endif // GTALBERGO_H

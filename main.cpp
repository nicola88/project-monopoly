/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include<QApplication>
#include<QWidget>
#include "GameCore.h"

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
    GameCore Monopoli(4,4);
    return app.exec();
}

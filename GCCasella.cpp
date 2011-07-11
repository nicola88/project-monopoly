/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#include "GCCasella.h"
#include "GameCore.h"

GCCasella::GCCasella(const QString n, GameCore *const cr, int numT) : core(cr), nome(n), numTask(numT)
{
        task = new bool[numTask];
        for(int i=0; i<numTask; i++)
        {
            task[i]=true;
        }
}

const QString GCCasella::getName() const
{
    return nome;
}

void GCCasella::setTask(const int& index, const bool& value)
{
    if(index < numTask)
    {
        task[index]=value;
    }
    core->aggiornaAzioni(task);
}

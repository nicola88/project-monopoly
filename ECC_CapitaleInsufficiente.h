/*
** This file is part of the project-monopoly
** and it's released under the
** GNU General Public License v3
**
** Author: Nicola Moretto (2011)
 */

#ifndef ECC_CAPITALEINSUFFICIENTE_H
#define ECC_CAPITALEINSUFFICIENTE_H

class ECC_CapitaleInsufficiente {
public:
    enum evento{ammenda, pedaggio, acquistoVia, costruzioneAlbergo, riscattoAlbergo, acquistoSocieta};
};

/*
  Edificabile = <giocatore> non ha denaro sufficiente per acquistare <via/societa>
                <giocatore> non ha denaro sufficiente per costruire l'albergo in <via/societa>
  Ipotecabile = <giocatore> non ha denaro sufficiente per riscattare il <quota>% dell'albergo, pari a <somma>
  NonEdificabile

  Polizia = <giocatore> deve pagare un ammenda pari a <somma>
  Societa = <giocatore> non ha denaro sufficiente per acquistare il <quota>% della <via/societa>, pari a <somma>

  <giocatore> non ha denaro sufficiente per pagare il pedaggio, pari a <somma>

  <giocatore>, <via/societa>, <quota>, <somma>
  Contesto: ammenda, pedaggio, acquistoVia, costruzioneAlbergo, riscattoAlbergo, acquistoSocieta
*/

#endif // ECC_CAPITALEINSUFFICIENTE_H

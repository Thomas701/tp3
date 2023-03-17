/**
 * @file pile.c
 * @brief fichier d'implementation pour la gestion de pile
 */
 
#include <stdlib.h>
#include "eltPile.h"
#include "pile.h"

/**
 * @brief Initialiser une pile du type pile_t
 *   - allocation de memoire pour une structure pile_t et un tableau de taille elements
 * @param [in] taille taille de la pile
 * @return l'adresse de la structure
 */
pile_t * initPile(int taille)
{
    if (taille > 0)
    {
        pile_t * pile = malloc(sizeof(pile_t));
        pile->base = (eltType_pile *) malloc(taille*sizeof(eltType_pile));
        pile->taille = taille;
        pile->sommet = -1;
        return pile;
    }
    return NULL;
}


/**
 * @brief Liberer les memoires occupees par la pile
 * @param [in, out] adrPtPile l'adresse du pointeur de la structure pile_t
 */
void libererPile(pile_t ** pile)
{
  if(*pile != NULL){
    free((*pile)->base);
  }
  free(*pile);
  *pile = NULL;
}


/**
 * @brief Verifier si la pile est vide (aucun element dans la "base")
 * @param [in] ptPile l'adresse de la structure pile_t
 * @return 1 - vide, ou 0 - non vide
 */
int estVidePile(pile_t * pile)
{
    return (pile->sommet == -1) ? 1 : 0;
}


/**
 * @brief Entrer un element dans la pile
 * @param [in, out] ptPile l'adresse de la structure pile_t
 * @param [in] ptVal l'adresse de la valeur a empiler
 * @param [in, out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void empiler(pile_t * pile, eltType_pile * ptVal, int * code)
{
    if (pile->sommet == pile->taille-1)
        *code = 1;
    else
    {
        pile->sommet += 1;
        copyElt(ptVal, pile->base + pile->sommet);
        *code = 0;
    }
}


/**
 * @brief Sortir un element de la pile
 * @param [in, out] ptPile l'adresse de la structure pile_t
 * @param [out] ptRes l'adresse de l'element sorti
 * @param [in, out] code : l'adresse du code de sortie
 *                     *code = 0 si reussi
 *                           = 1 si echec
 */
void depiler(pile_t * pile, eltType_pile * ptRes, int * code)
{
  if (estVidePile(pile))
    *code = 1;
  else
    {
      copyElt(pile->base + pile->sommet, ptRes);
      pile->sommet -= 1;
      *code = 0;
    }
}

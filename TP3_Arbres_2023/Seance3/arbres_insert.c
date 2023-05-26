/**
 * @file arbres_insert.c
 * @brief fichier d'implementation du module pour l'insertion de valeur dans une arborescence
 */
#include <stdio.h>
#include <stdlib.h>

#include "../pile.h"
#include "../eltsArbre.h"
#include "arbres_insert.h"


/**
 * @brief rechercher un point de valeur v
 * @param [in] racine pointeur vers la racine de l'arborescence 
 * @return 
 *   - l'adresse du point contenant v si v existe dans l'arborescence
 *   - NULL, sinon
 */
cell_lvlh_t* rechercher_v(cell_lvlh_t* root, char v)
{
  cell_lvlh_t* res = NULL;
  pile_t * pile = initPile(NB_ELTPREF_MAX);
  cell_lvlh_t * cour = root;
  eltType_pile elem_pile;
  int code = 1;
  while (cour != NULL && res == NULL)
  {
    elem_pile.adrCell = cour;
    empiler(pile, &elem_pile, &code);
    cour = cour->lv;
    while ((cour == NULL && !estVidePile(pile)) && res == NULL)
    {
      depiler(pile, &elem_pile, &code);
      cour = elem_pile.adrCell;
      if(cour->val == v){
	res = cour;
      }
      cour = cour->lh;
    }
  }
  libererPile(&pile);
  return res;
}

/**
 * @brief rechercher le double prec de w dans une liste de fils
 * @param [in] adrPere l'adresse du pere
 * @param [in] w la valeur a inserer
 * @return l'adresse du pointeur prec apres lequel w doit etre inseree
 */
cell_lvlh_t** rechercherPrecFilsTries(cell_lvlh_t* adrPere, char w)
{
  cell_lvlh_t** cour = &adrPere;
  if((*cour) != NULL && (*cour)->val != w){
    cour = &(*cour)->lv;
  }
  while((*cour)->val != w && (*cour)->lh != NULL){
    cour = &(*cour)->lh;
  }
  return cour;
}

/** TO DO
 * @brief inserer une valeur w dans les fils d'un point de valeur v
 * @param [in] racine la racine de l'arborescence
 * @param [in] v la valeur d'un point auquel on va inserer la valeur w en fils
 * @param [in] w la valeur a inserer
 * @return 1 - insertion realisee; 0 - insertion n'a pas ete realisee
 */
//  insererTrie()
// {
// // TO DO
// }

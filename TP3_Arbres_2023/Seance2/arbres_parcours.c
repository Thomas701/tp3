/**
 * @file arbres_parcours.c
 * @brief fichier d'implementation du module pour le parcours d'arborescence
 */
#include <stdio.h>
#include <stdlib.h>

#include "../pile.h"
#include "../eltsArbre.h"
#include "arbres_parcours.h"


/**
 * @brief calculer le nombre de fils ou freres d'un point a partir du pointeur du debut de la liste
 * @param [in] ptCell pointeur vers le 1er frere
 * @return le nombre de fils ou freres
 */
int getNbFils_ou_Freres(cell_lvlh_t *noeud) {
  int result = 0;
  while(noeud != NULL){
    result++;
    noeud = noeud->lh;
  }
  return result;
}


/**
 * @brief parcours en profondeur postfixee
 * @param [in] file le flux de sortie
 * @param [in] racine la racine de l'arborescence
 */
void printPostfixee(FILE* out, cell_lvlh_t* root)
{
  pile_t * pile = initPile(NB_ELTPREF_MAX);
  cell_lvlh_t * cour = root;

  eltType_pile elem_pile;
  int code = 1;
  while (cour != NULL)
    {
      elem_pile.adrCell = cour;
      empiler(pile, &elem_pile, &code);
      cour = cour->lv;
      while (cour == NULL && !estVidePile(pile))
	{
	  depiler(pile, &elem_pile, &code);
	  cour = elem_pile.adrCell;
	  fprintf(out, "(%c,%d) ", cour->val, getNbFils_ou_Freres(cour->lv));
	  cour = cour->lh;
	}
    }
  fprintf(out, "%d\n", getNbFils_ou_Freres(root));
  libererPile(&pile);
}

/**
 * @file arbres_construct.c
 * @brief fichier d'implementation du programme pour la construction d'une arborescence
 */
#include <stdio.h>
#include <stdlib.h>

#include "../pile.h"
#include "../eltsArbre.h"
#include "arbres_construct.h"

/**
 * @brief lire le fichier contenant la representation prefixee de l'arborescence
 * @param [in] fileName le nom du fichier contenant la representation prefixee
 * @param [in, out] tabEltPref tableau des elements de la representation prefixee
 * @param [in, out] nbEltsPref l'adresse memoire contenant le nombre des elements du tabEltPref
 * @return le nombre de racines
 */
int lirePref_fromFileName(char * name, eltPrefPostFixee_t * tab, int * nbEltsPref)
{
  int nbRacine = 0;
  *nbEltsPref = 0;
  char c;
  int tabIndex = 0;
  int fils;
  FILE * f = fopen(name, "r");
  char val;
  
  if(f){
    while((c = getc(f)) != EOF && c != ' '){
      nbRacine *= 10;
      nbRacine += c - '0';
    }
    while(c != EOF){
      while((c = getc(f)) != EOF && c != ' '){
	val = c;
      }
      tab[tabIndex].val = val;
      (*nbEltsPref)++;
      fils = 0;
      while((c = getc(f)) != EOF && c != ' '){
	fils *= 0;
	fils += c - '0';
      }
      tab[tabIndex++].nbFils = fils;
    }
    fclose(f);
  }
  return nbRacine;
}

/**
 * @brief afficher les elements de la representation prefixee sur un flux de
 * sortie
 * @param file : le flux de sortie
 * @param [in, out] tabEltPref tableau des elements de la representation
 * prefixee
 * @param [in, out] nbEltsPref le nombre des elements du tabEltPref
 */
void printTabEltPref(FILE *file, eltPrefPostFixee_t *tabEltPref, int nbEltsPref)
{
  for(int i = 0; i < nbEltsPref; i++){
    fprintf(file, "%c %d ", tabEltPref[i].val, tabEltPref[i].nbFils);
  }
}

/**
 * @brief creer et initialiser un nouveau point de l'arborescence
 * @param [in] val la valeur du point
 * @return l'adresse du nouveau point 
 */
cell_lvlh_t *allocPoint(char val)
{
  cell_lvlh_t *new = (cell_lvlh_t*)malloc(sizeof(cell_lvlh_t));
  if(new){
    new->val = val;
    new->lh = NULL;
    new->lv = NULL;
  }
  return new;
}

/** TO DO
 * @brief construire un arbre avec lvlh a partir de representation prefixee
 * @param [in] tabEltPref tableau des elements de la representation prefixee
 * @param [in] nbRacines nombre de racines de l'arborescence
 * @return : 
 *     - NULL si l'arbre resultatnt est vide
 *     - l'adresse de la racine de l'arbre sinon
*/
//  pref2lvlh()
// {
// // TO DO
// }

/** TO DO
 * @brief liberer les blocs memoire d'un arbre
 * @param [in] adrPtRacine l'adresse du pointeur de la racine d'un arbre
 */
//  libererArbre()
// {
// // TO DO
// }

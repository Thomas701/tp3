/**
 * @file eltPile.c
 * @brief fichier d'implementation pour la gestion du type des elements de pile
 */
#include <stdio.h>

#include "eltPile.h"

/**
 * @brief Copier la valeur d'un element dans un autre emplacement
 * @param [in] src l'adresse de l'element a copier
 * @param [in] dest l'adresse de la destination
 */
void copyElt(eltType_pile * source, eltType_pile * destination)
{
  *source = *destination;
}


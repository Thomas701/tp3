/**
 * program for general linked list testing
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../pile.h"
#include "../eltsArbre.h"
#include "../Seance1/arbres_construct.h"
#include "arbres_insert.h"
#include "../../teZZt.h"


BEGIN_TEST_GROUP(ARBRE_INSERT)

TEST(nouvCell) {
	cell_lvlh_t *new;

	new = allocPoint('A');
	REQUIRE( NULL != new ); 
	CHECK( 'A' == new->val );
	CHECK( NULL == new->lv );
	CHECK( NULL == new->lh );

	free(new);
}


TEST(rechercher_v) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;
	cell_lvlh_t *pere = NULL;

	printf("\033[35m\nrechercher_v :");
	printf("\033[0m\n");

	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	racine = pref2lvlh(tabEltPref, nbRacines);

	pere = rechercher_v(racine, 'X');   // valeur inexistante
	CHECK( NULL == pere );

	pere = rechercher_v(racine, 'A');   // valeur a la racine
	REQUIRE( NULL != pere );
	CHECK( 'A' == pere->val );

	pere = rechercher_v(racine, 'F');   // valeur a la racine
	CHECK( 'F' == pere->val );

	libererArbre(&racine);
}

TEST(rechercherPrecFilsTries) {
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;
	cell_lvlh_t *pere = NULL;
	cell_lvlh_t **pprec = NULL;

	printf("\033[34m\nrechercherPrecFilsTries :");
	printf("\033[0m\n");
	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	racine = pref2lvlh(tabEltPref, nbRacines);

	pere = rechercher_v(racine, 'F');
	REQUIRE( NULL != pere );
	CHECK( 'F' == pere->val );

	pprec = rechercherPrecFilsTries(pere, 'A');
	REQUIRE( NULL != *pprec );
	CHECK( 'K' == (*pprec)->val );

	pprec = rechercherPrecFilsTries(pere, 'L');
	REQUIRE( NULL != *pprec );
	CHECK( 'M' == (*pprec)->val );

	pere = rechercher_v(racine, 'I');
	pprec = rechercherPrecFilsTries(pere, 'R');
	CHECK( NULL == (*pprec));

	libererArbre(&racine);
}

TEST(insererTrie) 
{
	int nbRacines = 0;
	int nbEltsPref = 0;
	eltPrefPostFixee_t tabEltPref[NB_ELTPREF_MAX];
	cell_lvlh_t *racine = NULL;

	printf("\033[35m\nrechercher_v :");
	printf("\033[0m\n");

	nbRacines = lirePref_fromFileName("../pref_exTP.txt", tabEltPref, &nbEltsPref);
	racine = pref2lvlh(tabEltPref, nbRacines);

	insererTrie(racine, 'F', 'A');
	CHECK(racine->lh->lv->lv->val == 'A');
	insererTrie(racine, 'I', 'J');
	CHECK(racine->lh->lv->lh->lv->val == 'J');
	insererTrie(racine, 'I', 'B');
	CHECK(racine->lh->lv->lh->lv->val == 'B');
	CHECK(racine->lh->lv->lh->lv->lh->val == 'J');
	insererTrie(racine, 'I', 'Q');
	CHECK(racine->lh->lv->lh->lv->val == 'B');
	CHECK(racine->lh->lv->lh->lv->lh->val == 'J');
	CHECK(racine->lh->lv->lh->lv->lh->lh->val == 'Q');
	insererTrie(racine, 'I', 'O');
	CHECK(racine->lh->lv->lh->lv->val == 'B');
	CHECK(racine->lh->lv->lh->lv->lh->val == 'J');
	CHECK(racine->lh->lv->lh->lv->lh->lh->val == 'O');
	CHECK(racine->lh->lv->lh->lv->lh->lh->lh->val == 'Q');

	libererArbre(&racine);
}

END_TEST_GROUP(ARBRE_INSERT)

int main(void) {
	RUN_TEST_GROUP(ARBRE_INSERT);
	return EXIT_SUCCESS;
}

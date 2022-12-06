#include <stdlib.h>

typedef POINT typeqq;

typedef struct maillon{
	typeqq valeur;
	struct maillon *suivant;
}Tmaillon;

void Allouer(Tmaillon **p){
	*p = (Tmaillon *)malloc(sizeof(Tmaillon));
}

void Liberer(Tmaillon *p){
	free(p);
}

void Aff_val(Tmaillon *p, typeqq val) {
	p->valeur = val;
}

typeqq Valeur(Tmaillon *p){
	return p->valeur;
}

void Aff_adr(Tmaillon *p, Tmaillon *q) {
	p->suivant = q;
}

Tmaillon *Suivant(Tmaillon *p){
	return p->suivant;
}

void init_Pile(Tmaillon **pile){
	*pile = NULL;
}

int Pile_vide(Tmaillon *pile){
	return (pile == NULL);
}

void Empiler(Tmaillon **pile, typeqq val){
	Tmaillon *p;
	
	Allouer(&p);
	Aff_val(p, val);
	Aff_adr(p, *pile);
	*pile = p;
}

void Depiler(Tmaillon **pile, typeqq *val){
	Tmaillon *p;
	
	if (!Pile_vide(*pile)){
		*val = Valeur(*pile);
		p = *pile;
		*pile = Suivant(p);
		Liberer(p);
	}
}

void init_File(Tmaillon **Tete, Tmaillon **Queue){
	*Tete = NULL;
	*Queue = NULL;
}

int File_vide(Tmaillon *Tete){
	return (Tete == NULL);
}

void Enfiler(Tmaillon **Tete, Tmaillon **Queue, typeqq val){
	Tmaillon *p;
	
	Allouer(&p);
	Aff_val(p, val);
	Aff_adr(p, NULL);
	if (*Tete == NULL)
		*Tete = p;
	else
		Aff_adr(*Queue, p);
	*Queue = p;
}

void Defiler(Tmaillon **Tete, Tmaillon **Queue, typeqq *val){
	Tmaillon *p;
	
	p = *Tete;
	*val = Valeur(p);
	*Tete = Suivant(p);
	if (p == NULL) *Queue = NULL;
	Liberer(p);
}


#include<stdio.h>
#include<stdlib.h>


typedef struct{
    int taille;
    int sommet ;
    int Pile[50];

}myPile;

typedef struct{
    int tete;
    int taille;
    int Queue ;
    int File[50];

}myFile;

int est_videP(myPile P){
    return P.sommet==0;
}

int est_pleineP(myPile P){
    return P.sommet==P.taille;
}

void empiler(myPile *P,int x){
    P->Pile[P->sommet++]=x;
}

int depiler(myPile *P){
    return P->Pile[--P->sommet];

}

int est_videF(myFile F){
   return F.tete==F.Queue;
}

int est_pleineF(myFile F){
    return F.Queue==F.taille;
}

void emfiler(myFile *F,int x){
    F->File[F->Queue++]=x;
}

int defiler(myFile *F){
    return F->File[F->tete++];

}

int main(){
    myPile P1;
    int n;
    P1.sommet=0;
    printf("entrer la taille de la pile 1: ");
    scanf("%d",&(P1.taille));

    while(!(est_pleineP(P1))){
        printf("donner une valeur: ");
        scanf("%d",&n);
        empiler(&P1,n);
    }
    while(!est_videP(P1)){
        printf("%d\n",depiler(&P1));

    }
    return 0;
}
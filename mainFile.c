
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
    myFile F1;
    int n;
    F1.tete=F1.Queue = 0;
    printf("entrer la taille de la file 1: ");
    scanf("%d",&(F1.taille));

    while(!(est_pleineF(F1))){
        printf("donner une valeur: ");
        scanf("%d",&n);
        emfiler(&F1,n);
    }
    while(!est_videF(F1)){
        printf("%d\n",defiler(&F1));

    }
    return 0;
}
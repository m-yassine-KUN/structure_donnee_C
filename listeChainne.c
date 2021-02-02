#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/******************************************/
typedef struct ville {
    char nom[50];
    float superficie;
    int nbr_habit;
}ville;

typedef struct liste_des_villes {
    ville town; // data
    ville *next;
}liste_des_villes;

/******************************************/
liste_des_villes* Trier(liste_des_villes* debut){ // return une liste trier
    liste_des_villes* temp, *p;
    char b[30];
    if(debut!=NULL){
        for(temp=debut;temp->next!=NULL;temp=temp->next)
            for(p=temp->next;p!=NULL;p=p->next){
                if(strcmp(p->town.nom,temp->town.nom)<0){
                    strcpy(b,p->town.nom);
                    strcpy(p->town.nom,temp->town.nom);
                    strcpy(temp->town.nom,b);
                }
            }
        return debut;
    }
}
/******************************************/
void ajouter(liste_des_villes **l/*Box **debut*/,ville v/*int elm*/){
    liste_des_villes *b;
    b=(liste_des_villes *)malloc(sizeof(liste_des_villes));
    b->next=*l;
    b->town=v;
    *l=b;
    *l=Trier(*l);
}

/******************************************/

void afficherListe(liste_des_villes *debut){
    liste_des_villes *temp;
    if(debut==NULL)
        printf("la Liste est vide\n");
    else{
        temp=debut;
        while(temp!=NULL){
            printf("[nom de la ville :%s] -- [nbr d'habittent de la ville :%d] -- [la superficie de la ville :%d] \n",temp->town.nom,temp->town.nbr_habit,temp->town.superficie);
            temp=temp->next;
        }
    }
}
/******************************************/

void ajouterALaFin(Box **debut,int elm){
    Box *b,*temp;
    b=(Box *)malloc(sizeof(Box));
    b->data=elm;
    b->next=NULL;
    if(*debut==NULL)
        *debut=b;
    else{
        temp=*debut;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=b;
    }
}

/******************************************/
void AjouterAuMilieu(Box **debut,int val,int elm){
    Box *b,*temp;
    if(*debut==NULL) 
        printf("Impossible la liste est vide\n");
    else{
        b=(Box *)malloc(sizeof(Box));
        b->data=elm;
        temp=*debut;
        while(temp->data!=val && temp!=NULL)
            temp=temp->next;
        if(temp!=NULL){
            b->next=temp->next;
            temp->next=b;
        }
        else
        printf("l'element %d ne se trouve pas dans la liste ! ",val);
    }   
}
/******************************************/
void suprimerAuDebut(Box **debut){
    Box *temp;
    if(*debut!=NULL){
        temp=*debut;
        *debut=temp->next;
        free(temp);
    }
}
/******************************************/
void suprimerALaFin(Box **debut){
    Box *temp;
    temp=*debut;
    if(*debut!=NULL){
        if(temp->next==NULL){
            free(temp);
            *debut=NULL;
        }
        else{
            
            while(temp->next->next!=NULL)
                temp=temp->next;
            free(temp->next);
            temp->next=NULL;
        }
    }
}
/******************************************/
void suprimerAuMilieu(Box **debut,int val){
    Box *temp,*p;
    if(*debut!=NULL){
        if((*debut)->data==val){
            p=*debut;
            *debut=p->next;
            free(p);
        }
        else{
            temp=*debut;
            while(temp->next!=NULL && temp->next->data!=val)
                temp=temp->next;
            if(temp->next!=NULL){
                p=temp->next;
                temp->next=p->next;
                free(p);
            }
        }
    }
}
/******************************************/

/******************************************/

void afficherListe(Box *debut){
    Box *temp;
    if(debut==NULL)
        printf("la Liste est vide\n");
    else{
        temp=debut;
        while(temp!=NULL){
            printf("%d-->",temp->data);
            temp=temp->next;
        }
    }
}

/******************************************/
/****************main***********************/
/******************************************/

int main(){
    liste_des_villes *L1=NULL;
    int nbr,ajM_n;
    char n[50];
    printf("entrer le nombre des elements de la liste chainee: ");
    scanf("%d",&nbr);
    
    for(int i=0;i<nbr;i++){
        printf("entrer une ville: ");
        fflush(stdin);
        gets(n);
        ajouter(&L1,n);
        
    }
    
    afficherListe(L1);
    printf("\n");

   // printf("entrer l'element a ajouter a la liste: ");
   // scanf("%d",&ajM_n);
   // AjouterAuMilieu(&L1,2,ajM_n);
   // afficherListe(L1);
   //printf("\n");

    suprimerAuDebut(&L1);
    afficherListe(L1);
    printf("\n");

    suprimerALaFin(&L1);
    afficherListe(L1);
    printf("\n");

    suprimerAuMilieu(&L1,3);
    afficherListe(L1);
    return 0;
}
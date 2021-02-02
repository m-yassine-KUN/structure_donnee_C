#include<stdio.h>
#include<stdlib.h>


/******************************************/
typedef struct Box {
    int data;
    struct Box *next;
}Box;

/******************************************/

void ajouterAuDebut(Box **debut,int elm){
    Box *b;
    b=(Box *)malloc(sizeof(Box));
    b->next=*debut;
    b->data=elm;
    *debut=b;
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
    Box *L1=NULL;
    int n, nbr,ajM_n;
    printf("entrer le nombre des elements de la liste chainee: ");
    scanf("%d",&nbr);
    
    for(int i=0;i<nbr;i++){
        printf("entrer un element: ");
        scanf("%d",&n);
        ajouterALaFin(&L1,n);
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
    fflush(stdin);
    getchar();
}
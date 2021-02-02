#include<stdio.h>
#include<stdlib.h>

typedef struct Box {
    int data;
    struct Box *next;
    struct Box *prev;
}Box;

/*******************************************/
void afficher(Box *debut){
    Box *temp;
    temp=debut;
    printf("debut-->");
    while(temp!=NULL){
        printf("(%d)<-->",temp->data);
        temp=temp->next;
    }
    printf("<Fin\n");
}
/*******************************************/
void ajouterAuDebut(Box **debut,int elm){
    Box *b;
    b=(Box*)malloc(sizeof(Box));
    b->data=elm;
    b->prev=NULL;
    b->next=*debut;
    if((*debut)!=NULL)
        (*debut)->prev=b;
    *debut=b;

}
/*******************************************/
void ajouterALaFin(Box **debut,int elm){
    Box *b,*temp;
    b=(Box*)malloc(sizeof(Box));
    b->data=elm;
    b->prev=b->next=NULL;
    if((*debut)!=NULL){
        temp=*debut;
        while(temp->next!=NULL)
            temp=temp->next;
        b->prev=temp;
        temp->next=b;
    }
    else
        *debut=b;
}
/*******************************************/
void ajouterAuMilieuAp(Box **debut,int elm,int val){
    Box *b,*temp;
    if((*debut)!=NULL){
        b=(Box*)malloc(sizeof(Box));
        b->data=elm;
        b->prev=b->next=NULL;
        temp=*debut;
        while(temp->next!=NULL && temp->data!=val)
            temp=temp->next;
        if(temp->data==val){    
            b->next=temp->next;
            b->prev=temp;
            if(temp->next!=NULL)
                temp->next->prev=b;
            temp->next=b;
        }
    }
}

/*****************************************************/

void ajouterAuMilieuAv(Box **debut,int elm,int val){
    Box *b,*temp;
    if((*debut)!=NULL){
        b=(Box*)malloc(sizeof(Box));
        b->data=elm;
        b->prev=b->next=NULL;
        temp=*debut;
        while(temp->next!=NULL && temp->data!=val)
            temp=temp->next;
        if(temp->data==val){   
            b->next=temp;
            b->prev=temp->prev;
            if(temp->prev!=NULL)
                temp->prev->next=b;
            else
                *debut=b;
            temp->prev=b;
        }
    }
}

/*******************************************/
void suprimerAuDebut(Box **debut){
    if((*debut)!=NULL){
        Box *temp;
        temp=*debut;
        *debut=temp->next;
        if(temp->next!=NULL)
            temp->next->prev=NULL; 
        free(temp);
    }
}
/*******************************************/
void suprimerALaFin(Box **debut){
    if(*debut!=NULL){
        Box *temp;
        temp=*debut;
        while(temp->next!=NULL)
            temp=temp->next;
        if(temp->prev!=NULL)
            temp->prev->next=NULL;
        else
            *debut=NULL;
        free(temp);
        
    }
}
/*******************************************/
void suprimerAuMilieu(Box **debut,int elm){
    if(*debut!=NULL){
        Box *temp;
        temp=*debut;
        while(temp->next!=NULL && temp->data!=elm)
            temp=temp->next;
        if(temp->data==elm){
        if(temp->next!=NULL)
            temp->next->prev=temp->prev;
        if(temp->prev!=NULL)
            temp->prev->next=temp->next;
        else
            *debut=temp->next;
        free(temp);
        }
    }
}
/*******************************************/
/******************main**********************/
/*******************************************/
int main(){
    Box* L1=NULL;    
    int n, nbr;
    printf("entrer le nombre des elements de la liste doublement chainee: ");
    scanf("%d",&nbr);
    
    for(int i=0;i<nbr;i++){
        printf("entrer un element: ");
        scanf("%d",&n);
        ajouterALaFin(&L1,n);
    }
    afficher(L1);
    ajouterAuMilieuAp(&L1,22,2);
    ajouterAuMilieuAv(&L1,44,3);
    afficher(L1);
    suprimerAuDebut(&L1);
    afficher(L1);
    suprimerALaFin(&L1);
    afficher(L1);
    suprimerAuMilieu(&L1,3);
    afficher(L1);
    return 0;
}
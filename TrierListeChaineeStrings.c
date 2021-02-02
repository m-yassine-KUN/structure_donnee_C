#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/******************************************/
typedef struct Box {
    char data[30];
    struct Box *next;
}Box;

/******************************************/

void ajouterALaFin(Box **debut,char elm[30]){
    Box *b,*temp;
    b=(Box *)malloc(sizeof(Box));
    strcpy(b->data,elm);
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

void afficherListe(Box *debut){
    Box *temp;
    if(debut==NULL)
        printf("la Liste est vide\n");
    else{
        temp=debut;
        while(temp!=NULL){
            printf("(%s)-->",temp->data);
            temp=temp->next;
        }
    }
}
/******************************************/
Box* Trier(Box* debut){
    Box* temp, *p;
    char b[30];
    if(debut!=NULL){
        for(temp=debut;temp->next!=NULL;temp=temp->next)
            for(p=temp->next;p!=NULL;p=p->next){
                if(strcmp(p->data,temp->data)<0){
                    strcpy(b,p->data);
                    strcpy(p->data,temp->data);
                    strcpy(temp->data,b);
                }
            }
        return debut;
    }
}

/******************************************/
/****************main***********************/
/******************************************/

int main(){
    Box *L1=NULL;
    int  nbr;
    char n[30];
    printf("entrer les noms des elements de la liste chainee: ");
    scanf("%d",&nbr);
    
    for(int i=0;i<nbr;i++){
        printf("entrer un nom en miniscule: ");
        fflush(stdin);
        gets(n);
        ajouterALaFin(&L1,n);
    }
    
    afficherListe(L1);
    printf("\n");
    L1=Trier(L1);
    afficherListe(L1);
    fflush(stdin);
    getchar();
}
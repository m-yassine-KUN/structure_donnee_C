#include<stdio.h>
#include<stdlib.h>


/******************************************/
typedef struct Box {
    int data;
    struct Box *next;
}Box;

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

void afficherListe(Box *debut){
    Box *temp;
    if(debut==NULL)
        printf("la Liste est vide\n");
    else{
        temp=debut;
        while(temp!=NULL){
            printf("(%d)-->",temp->data);
            temp=temp->next;
        }
    }
}
/******************************************/
Box* Trier(Box* debut){
    Box* temp, *p;
    int b;
    if(debut!=NULL){
        for(temp=debut;temp->next!=NULL;temp=temp->next)
            for(p=temp->next;p!=NULL;p=p->next){
                if(p->data<temp->data){
                    b=p->data;
                    p->data=temp->data;
                    temp->data=b;
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
    L1=Trier(L1);
    afficherListe(L1);
    fflush(stdin);
    getchar();
}
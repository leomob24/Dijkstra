/*1) APPLICARE ALGORITMO DI DIJKSTRA AD UN GRAFO CON 5 NODI ORIENTATO IN UN SOLO VERSO
✓ a. Soluzione default
✓ b. Soluzione dijkstra con dati inseriti utente
✓ c. Vedere se ci sono altri cammini minimi se si stamparli
2) APPLICARE ALGORITMO DI DIJKSTRA AD UN GRAFO CON 10 NODI ORIENTATO IN UN SOLO VERSO
✓ a. Soluzione default
✓ b. Soluzione dijkstra con dati inseriti utente
✓ c. Vedere se ci sono altri cammini minimi se si stamparli
3) APPLICARE ALGORITMO DI DIJKSTRA AD UN GRAFO QUALSIASI
✓ a. Soluzione default
✓ b. Soluzione dijkstra con dati inseriti utente
✓ c. Vedere se ci sono altri cammini minimi se si stamparli
n.b. fare gli opportuni controlli sui dati inseriti dagli utenti
nel punto 3 se avete problemi a farlo subito per qualsiasi grafo iniziate magari con meno nodi*/

#define INF 9999
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void inserimento(int pesi[][100],int nodi);
void djikstra(int pesi[][100], int nodi);
void alternative_path(int pesi[][100], int nodi, int i, int j);
void fisso1(int pesi[][100]);
void fisso2(int pesi[][100]);
void stampa(int pesi[][100], int nodi);

int main()
{
    fflush(stdout);
    fflush(stdin);
    int nodi,i,j,scelta;
    int pesi[100][100];
    do
    {
        printf("1 per la soluzione a 5 nodi di default\n2 per la soluzione a 10 nodi di default\n3 per la soluzione ad un grafo qualsiasi\n0 per uscire\n");
        scanf("%d",&scelta);
        switch(scelta)
        {
        case 1:
            fisso1(pesi);
            nodi=5;
            djikstra(pesi,nodi);
            break;
        case 2:
            fisso2(pesi);
            nodi=10;
            djikstra(pesi,nodi);
            break;
        case 3:
            do
            {
                printf("inserire numero nodi(min 3): ");
                scanf("%d",&nodi);
            }while(nodi<3);
            inserimento(pesi,nodi);
            djikstra(pesi,nodi);
            break;
        }
    } while(scelta!=0);
}

void stampa(int pesi[][100], int nodi)
{
    int k,z,trat;
    //stampa la tabella
    trat=(4*nodi)+3;
    printf("\n\n");
    printf("\t  ");
    printf("|");
    for(k=0;k<nodi;k++)
    {
        printf(" %d ",k+1);
        printf("|");
    }
    printf("\n\t");
    for(z=0;z<trat;z++)
    {
        printf("-");
    }
    printf("\n");
    for(k=0;k<nodi;k++)
    {
        printf("\t%d ",k+1);
        printf("|");
        for(z=0;z<nodi;z++)
        {
            if(pesi[k][z]==INF)
            {
                printf(" X ");
            }
            else
            {
                printf(" %d ",pesi[k][z]);
            }
            printf("|");
        }
        printf("\n\t");
        for(z=0;z<trat;z++)
        {
            printf("-");
        }
        printf("\n");
    }
}

void fisso1(int pesi[][100])
{
    int v[25]={0,2,4,3,0,0,0,0,0,5,0,1,0,0,7,0,0,0,0,6,0,0,0,0,0};
    int cont=0,j,i,z,k;
    for (i = 0; i < 5; i++) 
    {
        for (j = 0; j < 5; j++)
        {
            if (v[cont] != 0)
            {
                pesi[i][j] = v[cont];
            }
            else
            {
                pesi[i][j] = INF;
            }
            cont++;
        }
    }
}

void fisso2(int pesi[][100])
{
    int v[100]={0,1,0,0,7,0,0,0,0,0,0,0,0,0,0,0,0,7,6,0,0,1,0,6,0,0,0,0,0,0,0,0,0,0,0,9,0,0,0,0,0,4,0,0,0,0,5,0,0,0,0,0,7,0,0,0,0,0,0,3,4,0,0,0,0,0,0,3,0,0,0,0,0,0,2,0,0,0,2,0,0,0,5,0,0,9,0,0,0,0,0,0,0,4,0,0,0,0,4,0};
    int cont=0,j,i,z,k;
    for (i = 0; i < 10; i++) 
    {
        for (j = 0; j < 10; j++)
        {
            if (v[cont] != 0)
            {
                pesi[i][j] = v[cont];
            }
            else
            {
                pesi[i][j] = INF;
            }
            cont++;
        }
    }
}

void inserimento(int pesi[][100], int nodi) // funzione per l'imput di una matrice nodi per nodi al momento statica
{
    int scelta,scelta2,s;

    int i, j;
    for (i = 0; i < nodi; i++)      //inizioalizzazione matrice pesi 
    {
        for (j = 0; j < nodi; j++)
        {
            pesi[i][j] = INF;
        }
    }
    do
    {
        printf("il grafo e' orientato?\n 1) si\n 2) no\n");
        scanf("%d",&scelta);
    }while(scelta!=1 && scelta!=2);
    s=scelta;
    switch (scelta)
    {
    case 1:
        for (i = 0; i < nodi; i++)      //input orientato 
        {
            for (j = 0; j < nodi; j++)
            {
                if (i != j)
                {
                    do
                    {
                        printf("il nodo %d e' collegato al nodo %d\n(0=no,1=si)\n", i+1, j+1);
                        scanf("%d", &scelta);
                        if (scelta == 1)
                        {
                            do
                            {
                                printf("inserire peso tra %d e %d: ", i+1, j+1);
                                scanf("%d", &pesi[i][j]);
                            } while (pesi[i][j] <= 0); // i pesi inseriti devono essere positivi e diversi da 0
                        }
                    } while (scelta != 0 && scelta != 1);
                }
            }
        }
        break;
    case 2:
        for (i = 0; i < nodi; i++)      //input non orientato
        {
            for (j = 0; j < nodi; j++)
            {
                if (i != j)
                {
                    do
                    {
                        if(pesi[i][j]!=444)
                        {
                            printf("il nodo %d e' collegato al nodo %d\n(0=no,1=si)\n", i+1, j+1);
                            scanf("%d",&scelta);
                            if (scelta == 1)
                            {
                                do
                                {
                                    printf("inserire peso tra %d e %d: ", i+1, j+1);
                                    scanf("%d", &pesi[i][j]);
                                } while (pesi[i][j] <= 0); // i pesi inseriti devono essere positivi e diversi da 0
                            }
                            pesi[j][i]=444;         //uso 444 perchè così posso controllare se il peso è già stato inserito
                        }
                    } while (scelta != 0 && scelta != 1);
                }
            }
        }
        for (i = 0; i < nodi; i++)      //input non orientato
        {
            for (j = 0; j < nodi; j++)
            {
                if (i != j&& pesi[i][j]==444)
                {
                    pesi[i][j]=pesi[j][i];
                }
            }
        }
        break;
    }
    stampa(pesi,nodi);
    do
    {
        printf("\nvuoi modificare qualche peso?\n 1) si\n 2) no\n");
        scanf("%d",&scelta2);
    }while(scelta2!=2 && scelta!=1);
    while(scelta2==1)
    {
        do
        {
            printf("\ntra quali nodi vuoi cambiare il peso dell'arco?\n");
            printf("primo nodo: ");
            scanf("%d",&i);
            i--;
            printf("\nsecondo nodo: ");
            scanf("%d",&j);
            j--;
        }while(i == j);
        do
        {
            printf("inserire il nuovo peso tra %d e %d: ", i+1, j+1);
            scanf("%d", &pesi[i][j]);
            printf("\n%d\n",pesi[i][j]);
        }while (pesi[i][j] <=0);
        if(s==2)               //se il grafo non e' orientato cambio in entrambi i versi
        {
            pesi[j][i]=pesi[i][j];
        }
        printf("\nvuoi cambiare altri nodi? 1) si 0) no\n");
        scanf("%d",&scelta2);
    }
}

void djikstra(int pesi[][100], int nodi)        //funzione per il calcolo di djikstra
{    
    int prec[nodi];     //vettore che contiene i precedenti
    int costi[nodi];    //vettore che contiene i costi
    int visit[nodi];    //vettore che contiene i nodi visitati
    int stamp[100];     //vettore utilizzato per stampare in ordine i nodi
    int i,j,k,costmin,nextnode,part,arr,app,cont,scelta;
    stampa(pesi,nodi);      //funzione per la stampa della tabella dei pesi
    do
    {
        do
        {
            printf("\ninserire nodo di partenza: ");
            scanf("%d",&i);
        }while(i<1 || i>nodi);
        do
        {
            printf("\ninserire nodo di arrivo: ");
            scanf("%d",&j);
        }while(j<1 || j>nodi);
        if(i==j)
        {
            printf("\nnon è possibile calcolare il percorso inserire due nodi diversi\n");
        }
    }while(i==j);
    i--;      //quarto nodo = nodo 3
    j--;      //quarto nodo = nodo 3
    part=i;   //partenza salvata per stampare il percorso
    arr=j;    //per cammini alternativi
    for(k=0;k<nodi;k++)         //inizializzazione dei vettori
    {
        visit[k]=0;
        if(k!=i)
        {
            prec[k]=i;
        }
        else
        {
            prec[k]=INF;
        }
        costi[k]=pesi[i][k];
    }
    visit[i]=1;
    while(visit[j]!=1)              //finchè non viene visitato il nodo di arrivo
    {
        for(k=0;k<nodi;k++)         //controllo tutti i nodi
        {
            if(visit[k]!=1 && k!=i)     //se non sono già stati visitati e non sono il nodo di partenza
            {
                app=pesi[i][k]+costi[i];
                if(app<costi[k])
                {
                    costi[k]=pesi[i][k]+costi[i];       //se il nuovo costi risulta essere minore di quello attuale viene aggiornato il vettore dei costi
                    prec[k]=i;
                }
                else
                {
                    if(pesi[i][k]==INF)
                    {
                        cont++;        //contatore per vedere se ci sono nodi che sono a INF
                    }
                }
            }
        }
        costmin=INF;            //inizializzazione del costo minimo
        for(k=0;k<nodi;k++)
        {
            if(costi[k]<costmin && visit[k]!=1)     //se il costo minimo è minore di quello attuale e il nodo non è già stato visitato
            {
                costmin=costi[k];       //costo minimo viene aggiornato
                nextnode=k;             //ed il nodo successivo viene aggiornato
            }
        }
        visit[nextnode]=1;      //nodo successivo viene visitato
        i=nextnode;     //i viene aggiornato con il nodo dal costo minore
        cont=0;
        if(i!=j)
        {
        	for(k=0;k<nodi;k++)
        	{
            	if(pesi[i][k]==INF)
            	{
                	cont++;        //contatore per vedere se ci sono altri nodi che non sono a INF
           	 }
       	 }
        }
        if(cont==nodi)
        {
            printf("\nnon e' possibile calcolare il percorso\n");
            return;
        }
    }
    for(cont=0;cont<100;cont++)
    {
        stamp[cont]=INF;        //inizializzazione vettore stampa
    }
    printf("\ncosto minimo: %d\n",costi[j]);
    printf("percorso minimo: ");
    cont=0;
    stamp[cont]=j;
    j=prec[j];
    cont++;
    do                  //ciclo per la stampa del cammino minimo
    {
        if(j!=part && visit[j]==1)
        {
            stamp[cont]=j;
            cont++;
        }
        j=prec[j];
    }while(j!=part);
    stamp[cont]=j;
    printf("%d",stamp[cont]+1);
    for(cont=cont-1;cont>=0;cont--)
    {
        printf("->%d",stamp[cont]+1);
    }
    printf("\n");
    printf("vuoi controllare se ci sono cammini alternativi?(1 si, 0 no)\n");
    do
    {
        scanf("%d",&scelta);
    } while (scelta<0 || scelta>1);
    if(scelta==1)
    {
        alternative_path(pesi,nodi,part,arr);     //funzione per la stampa dei cammini alternativi
    }
}

void alternative_path(int pesi[][100], int nodi, int i, int j)          //esattamente uguale a djikstra ma con un uguale in più nel confronto per vedere se ci sono costi minori
{                                                                       //in questo caso si tengono in considerazione anche quelli uguali
    int prec[nodi];
    int costi[nodi];
    int visit[nodi];
    int stamp[100];
    int k,costmin,nextnode,app,cont,part;
    part=i;
    for(k=0;k<nodi;k++)
    {
        visit[k]=0;
        if(k!=i)
        {
            prec[k]=i;
        }
        else
        {
            prec[k]=INF;
        }
        costi[k]=pesi[i][k];
    }
    visit[i]=1;

    while(visit[j]!=1)
    {
        for(k=0;k<nodi;k++)
        {
            if(visit[k]!=1 && k!=i)
            {
                app=pesi[i][k]+costi[i];
                if(app<=costi[k])
                {
                    costi[k]=pesi[i][k]+costi[i];
                    prec[k]=i;
                }
                else
                {
                    if(pesi[i][k]==INF)
                    {
                        cont++;        //contatore per vedere se ci sono altri nodi che non sono a INF
                    }
                }
            }
        }
        costmin=INF;
        for(k=0;k<nodi;k++)
        {
            if(costi[k]<=costmin && visit[k]!=1)
            {
                costmin=costi[k];
                nextnode=k;
            }
        }
        visit[nextnode]=1;
        i=nextnode;
         cont=0;
        if(i!=j)
        {
        	for(k=0;k<nodi;k++)
        	{
            	if(pesi[i][k]==INF)
            	{
                	cont++;        //contatore per vedere se ci sono altri nodi che non sono a INF
           	 }
       	 }
        }
        if(cont==nodi)
        {
            printf("\nnon e' possibile calcolare il percorso 2\n");
            return;
        }
    }
    for(cont=0;cont<100;cont++)
    {
        stamp[cont]=INF;        //inizializzazione vettore stampa
    }
    printf("\ncosto minimo: %d\n",costi[j]);
    printf("percorso minimo: ");
    cont=0;
    stamp[cont]=j;
    j=prec[j];
    cont++;
    do
    {
        if(j!=part && visit[j]==1)
        {
            stamp[cont]=j;
            cont++;
        }
        j=prec[j];
    }while(j!=part);
    stamp[cont]=j;
    printf("%d",stamp[cont]+1);
    for(cont=cont-1;cont>=0;cont--)
    {
        printf("->%d",stamp[cont]+1);
    }
    printf("\n");
}

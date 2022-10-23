#include <bits/stdc++.h>
#define K 2

using namespace std;

vector<int> V;
int DIM,RANGE;
int SPEED; // 10000000 = 1 secondo

void stampa_vettore(int pos=-1);
void inizializza();
void bubble();
void selection();
void start();

vector<string> Algoritmi(K);

int main() { 
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);

    srand(time(NULL));

    start();

    return 0;
}

void start() {
    system("clear");

    // Scelta algoritmo
    Algoritmi[0]="Bubble sort";
    Algoritmi[1]="Selection sort";
    int scelta=0;
    char c='a';
    do {
        printf("\n\t\tSORT VISUALIZER - Matteo Arcari\n\n");
        printf("\n   Scesci l'algoritmo di ordinamento:  \n\n   up -> u    down -> d    enter -> e\n\n");
        for (int i=0;i<K;i++) {
            if (i==scelta) printf("  -> ");
            else printf("     ");
            printf("%s\n", Algoritmi[i].c_str());
        }
        c=getchar();
        getchar();
        if (c=='u' && scelta>0) scelta--;
        else if (c=='d' && scelta<K-1) scelta++;
        system("clear");
    } while (c!='e');

    // Info vettore
    do {
        system("clear");
        printf("\n\t\tSORT VISUALIZER - Matteo Arcari\n\n");
        printf("  Inserisci la dimensione del vettore (max 40): ");
        scanf("%d",&DIM);
    } while (DIM<1 || DIM>50);
    RANGE=DIM;
    int speed=0;
    do {
        system("clear");
        printf("\n\t\tSORT VISUALIZER - Matteo Arcari\n\n");
        printf("  Inserisci la velocità di esecuzione 1 -> 10: ");
        scanf("%d",&speed);
    } while (speed<1 || speed>10);

    SPEED=400000/speed;

    inizializza();

    if (scelta==0) bubble();
    else if (scelta==1) selection();
    return;
}

void stampa_vettore(int pos) {
    int spazi=max(0,32-DIM);
    printf("\n\n");
    for (int i=RANGE;i>0;i--) {
        printf("%s",string(spazi,' ').c_str());
        for (int j=0;j<DIM;j++) {
            if (V[j]>=i) {
                if (j==pos) printf("░ ");
                else printf("█ ");
            }
            else printf("  ");
        }
        printf("\n");
    }
    return;
}

void inizializza() {
    V.resize(DIM,1);
    for (int i=0;i<DIM;i++) V[i]=i+1;
    auto rnd = default_random_engine {};
    shuffle(V.begin(),V.end(),rnd);
    return;
}

void bubble () {
    int scambi=0;
    int confronti=0;
    int fine=DIM-1;
    while (fine>0) {
        int pos=0;
        for (int j=0;j<fine;j++) {
            confronti++;
            if (V[j]>V[j+1]) {
                pos=j+1;
                scambi++;
                swap(V[j],V[j+1]);
            }
            system("clear");
            printf ("\t\t\t -- BUBBLE SORT --\n");
            printf ("\t\t\tDimensione vettore: %d\n",DIM);
            stampa_vettore(j);
            printf ("\n\n\t\t   Scambi: %d\tConfronti: %d\n\n\n\n",scambi,confronti);
            usleep(SPEED);
        }
        fine=pos;
    }
    system("clear");
    printf ("\t\t\t -- BUBBLE SORT --\n");
    printf ("\t\t\tDimensione vettore: %d\n",DIM);
    stampa_vettore();
    printf ("\n\n\t\t   Scambi: %d\tConfronti: %d\n\n\n\n",scambi,confronti);

    return;
}

void selection () {
    int scambi=0;
    int confronti=0;
    int min;
    for (int i=0;i<DIM-1;i++) {
        int min=i;
        for (int j=i+1;j<DIM;j++) {
            confronti++;
            if (V[j]<V[min]) {
               min=j;
            }
            system("clear");
            printf ("\t\t\t -- SELECTION SORT --\n");
            printf ("\t\t\tDimensione vettore: %d\n",DIM);
            stampa_vettore(j);
            printf ("\n\n\t\t   Scambi: %d\tConfronti: %d\n\n\n\n",scambi,confronti);
            usleep(SPEED);
        }
        swap(V[i],V[min]);
        scambi++;
    }
    system("clear");
    printf ("\t\t\t -- SELECTION SORT --\n");
    printf ("\t\t\tDimensione vettore: %d\n",DIM);
    stampa_vettore();
    printf ("\n\n\t\t   Scambi: %d\tConfronti: %d\n\n\n\n",scambi,confronti);

    return;
}


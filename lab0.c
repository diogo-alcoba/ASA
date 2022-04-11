#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int i, total_pessoas, ligacoes, pessoa, amigo;
    scanf("%d, %d", &total_pessoas, &ligacoes);

    //numero de amigos que cada pessoa tem
    int *amigos1 = (int*) malloc((total_pessoas + 1) * sizeof(int));
    //numero de pessoas de que esta pessoa e amiga de
    int *amigos2 = (int*) malloc((total_pessoas + 1) * sizeof(int));
    //quantas pessoas tem 0, 1, 2, ... amigos
    int *hist1 = (int*) malloc(total_pessoas * sizeof(int));
    //o mesmo so que em relacao ao vetor amigos2
    int *hist2 = (int*) malloc(total_pessoas * sizeof(int));
    for (i = 0; i < total_pessoas + 1; i++){
        amigos1[i] = 0;
        amigos2[i] = 0;
    }
    //no inicio todas as pessoas tem 0 amigos
    hist1[0] = total_pessoas;
    hist2[0] = total_pessoas;
    for (i = 1; i < total_pessoas; i++){
        hist1[i] = 0;
        hist2[i] = 0;
    }
    for (i = 0; i < ligacoes; i++){
        scanf("%d %d", &pessoa, &amigo);
        hist1[amigos1[pessoa]++]--;
        hist1[amigos1[pessoa]]++;
        hist2[amigos2[amigo]++]--;
        hist2[amigos2[amigo]]++;
    }

    puts("Histograma 1");
    for (i = 0; i < total_pessoas; i++){
        printf("%d\n", hist1[i]);
    }
    puts("Histograma 2");
    for (i = 0; i < total_pessoas; i++){
        printf("%d\n", hist2[i]);
    }
    free(amigos1);
    free(amigos2);
    free(hist1);
    free(hist2);

    return 0;
}

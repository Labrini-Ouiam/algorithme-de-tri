#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

// Fonction pour mesurer le temps
double measureTime(void (*functionToMeasure)(int[], int), int tableau[], int taille) {
    LARGE_INTEGER start, end, frequency;
    QueryPerformanceFrequency(&frequency);
    QueryPerformanceCounter(&start);

    // Appelez la fonction passée en paramètre avec les paramètres
    functionToMeasure(tableau, taille);

    QueryPerformanceCounter(&end);
    
    double elapsed_time = (double)(end.QuadPart - start.QuadPart) / frequency.QuadPart;

    return elapsed_time;
}
//la fonction de tri_insertion
void tri_insertion(int tableau[], int taille) {
    int i, j, cle;

    for (i = 1; i < taille; i++) {
        cle = tableau[i];
        j = i - 1;

        while (j >= 0 && tableau[j] > cle) {
            tableau[j + 1] = tableau[j];
            j = j - 1;
        }

        tableau[j + 1] = cle;
    }
}


int main() {
    int taille = 100;
    int tableau[100];

    // Initialisez le générateur de nombres aléatoires
    srand((unsigned)time(NULL));

    printf("Tableau non trié de taille 100 : ");
    for (int i = 0; i < taille; i++) {
        tableau[i] = rand() % 1000;  // Remplissez le tableau avec des nombres aléatoires de 0 à 999
        printf("%d ", tableau[i]);
    }

    printf("\n");

    // Utilisez la fonction measureTime avec votre fonction à mesurer et les paramètres
    double executionTime = measureTime(tri_insertion, tableau, taille);

    printf("Tableau après le tri : ");
    for (int i = 0; i < taille; i++) {
        printf("%d ", tableau[i]);
    }

    printf("\nLe temps d'exécution de la fonction est de %.8f secondes.\n", executionTime);

    return 0;
}

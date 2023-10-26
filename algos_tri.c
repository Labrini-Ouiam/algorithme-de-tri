#include <stdio.h>
#include <stdlib.h>

void afficher_table(int *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ,", *(t + i));
    }
}

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void bulles(int *t, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (t[j] > t[j + 1])
            {
                swap(&t[j], &t[j + 1]);
            }
        }
    }
}

void selection(int *t, int size)
{
    int imin;
    for (int i = 0; i < size - 1; i++)
    {
        imin = i;
        for (int j = i + 1; j < size; j++)
        {
            if (t[j] < t[imin]){
                imin = j ;
            }
        }
        swap(&t[i],&t[imin]);
    }
}

void insertion(int *t, int size){
    for (int i = 0; i < size; i++)
    {
       
        
    }
    
}

int main()
{
    int t[] = {1, 4, 5, 2, 9, 0};
    afficher_table(t, 6);
    selection(t, 6);
    printf("\n");
    afficher_table(t, 6);
}
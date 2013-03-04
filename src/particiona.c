/*
 * particiona.c
 *
 *  Created on: Mar 3, 2013
 *      Author: mgiacomini
 */

#include <stdio.h>

/* -------------------------------------------------------------------------- */
/* modifica v e devolve um ��ndice m de forma que */
/* a-1 <= m <= b */
/* v[i] <= x, para todo a <= i <=m */
/* x < v[i], para todo m < i <=b */

int particiona(int v[], int a, int b, int x)
{
    int m, j;
    m = a - 1;
    for (j = a; j < b; j++)
    {
        if (v[j] < x)
        {
            m = m + 1;
            troca (v, m, j);
        }
    }
    troca (v, m + 1, b);
    return m + 1;
}

void troca (int v[], unsigned int a, unsigned int b)
{
    int aux = v[a];
    v[a] = v[b];
    v[b] = aux;

}


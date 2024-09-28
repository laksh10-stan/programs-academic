/* Extract ith MSD byte */
#define digit(x,i) ((x)[i])
#define bin(x) (first + count[x])

void jsw_radix_pass(char *a[], char *aux[], int count[], int first, int last, int radix)
{
    int i;

    for (i = first; i < last; i++)
    {
        ++count[digit(a[i], radix) + 1];
    }

    for (i = 1; i < UCHAR_MAX; i++)
    {
        count[i] += count[i - 1];
    }

    for (i = first; i < last; i++)
    {
        aux[count[digit(a[i], radix)]++] = a[i];
    }

    for (i = first; i < last; i++)
    {
        a[i] = aux[i - first];
    }
}

void jsw_radixsort_r(char *a[], char *aux[], int first, int last, int radix)
{
    if (radix <= UCHAR_MAX && last - first > THRESHOLD)
    {
        int count[UCHAR_MAX + 1] = { 0 };
        int i;

        jsw_radix_pass(a, aux, count, first, last, radix);

        for (i = 0; i < UCHAR_MAX - 1; i++)
        {
            int left = bin(i);
            int right = bin(i + 1) - 1;

            jsw_radixsort_r(a, aux, left, right, radix + 1);
        }
    }
}

void jsw_radixsort(char *a[], int n)
{
    char **aux = malloc((n + 1) * sizeof *aux);

    jsw_radixsort_r(a, aux, 0, n, 0);
    jsw_insertion(a, n);

    free(aux);
}

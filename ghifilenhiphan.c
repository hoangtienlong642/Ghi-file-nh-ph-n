#include<stdio.h>
float timmax( float a[],int n )
{
    int i;
    float max ;
    max = 0 ;
    for (i=0 ; i<n ;i++ )
    {
        if (a[i]>= max) max = a[i];
    }
    return max;
}
int main()
{
    FILE *f = fopen("SOTHUC.DAT", "wb");
    int i,n;
    float a[10000];
    printf ("Nhap vao so phan tu cua day so: ");
    scanf("%d", &n);
    for (i=1; i <= n; i++ )
    {
        printf( " Nhap vao a[%d] = ", i);
        scanf ("%f",&a[i]);
        fwrite(&a[i], sizeof(float), 1, f);
    }
    fclose(f);
    FILE *fr = fopen("SOTHUC.DAT", "rb");
    float b[1000];
    fread(b, sizeof(float), n, fr );
    for (i=0; i < n; i++ )
    {
        printf( " a[%d] = %f \n ", i+1 , b[i]);
    }
    printf ( "Phan tu lon nhat cua day la: %f ", timmax(b,n) );
    fclose(fr);
    return 0;
}

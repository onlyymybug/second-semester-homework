#include<stdio.h>
#include<stdlib.h>
void print_short(short m[])
{
    printf("%hd",m[0]);
    for(int i=1;i<5;i++)
    printf(" %hd",m[i]);
    puts("");
}
void print_int(int m[])
{
    printf("%d",m[0]);
    for(int i=1;i<5;i++)
    printf(" %d",m[i]);
    puts("");
}
void print_long(long m[])
{
    printf("%ld",m[0]);
    for(int i=1;i<5;i++)
    printf(" %ld",m[i]);
    puts("");
}
void print_long_long(long long m[])
{
    printf("%lld",m[0]);
    for(int i=1;i<5;i++)
    printf(" %lld",m[i]);
    puts("");
}
void print_float(float m[])
{
    printf("%f",m[0]);
    for(int i=1;i<5;i++)
    printf(" %f",m[i]);
    puts("");
}
void print_double(double m[])
{
    printf("%lf",m[0]);
    for(int i=1;i<5;i++)
    printf(" %lf",m[i]);
    puts("");
}
int main()
{
    char a,aa[5];
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int n;
    scanf("%d",&n);
    FILE*fp=fopen("dict.dic","rb");
    for(int i=1;i<=n;i++)
    {
        fread(&a,sizeof(a),1,fp);
        fread(&b,sizeof(b),1,fp);
        fread(&c,sizeof(c),1,fp);
        fread(&d,sizeof(d),1,fp);
        fread(&e,sizeof(e),1,fp);
        fread(&g,sizeof(g),1,fp);
        fread(&h,sizeof(h),1,fp);
        fread(aa,sizeof(a),5,fp);
        fread(bb,sizeof(b),5,fp);
        fread(cc,sizeof(c),5,fp);
        fread(dd,sizeof(d),5,fp);
        fread(ee,sizeof(e),5,fp);
        fread(gg,sizeof(g),5,fp);
        fread(hh,sizeof(h),5,fp);
    }
    printf("%c\n",a);
    printf("%hd\n",b);
    printf("%d\n",c);
    printf("%ld\n",d);
    printf("%lld\n",e);
    printf("%f\n",g);
    printf("%lf\n",h);
    printf("%s\n",aa);
    print_short(bb);
    print_int(cc);
    print_long(dd);
    print_long_long(ee);
    print_float(gg);
    print_double(hh);
    fclose(fp);
    system("pause");
    return 0;
}
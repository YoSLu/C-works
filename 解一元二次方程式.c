#include <stdio.h>
#include <math.h>

double root1, root2, rootdefinder;
void doshiangshi_cal(double a, double b, double c, double rootdefinder){
    root1=(-b+rootdefinder)/(2*a);
    root2=(-b-rootdefinder)/(2*a);
}

int main(){
    double a, b, c;
    printf("��J�T�Ƭ�ax2+bx+c=0\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    rootdefinder=b*b-4*a*c;
    if (rootdefinder>=0){
        doshiangshi_cal(a,b,c, sqrt(rootdefinder));
        if (root1==root2){
            printf("���ڡA���G��%f", root1);
        }
        else {
            printf("\n���G��%f�B%f", root1, root2);
        }
    }
    else {
        printf("�L���");
    }
}




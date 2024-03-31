#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct{
int degree;  //����
float coef[MAX_DEGREE];  //���
}polynomial;

polynomial poly_add1(polynomial A,polynomial B)    //���� �Լ�
{
    polynomial C;
    int Apos=0,Bpos=0,Cpos=0;
    int degree_a=A.degree;
    int degree_b=B.degree;
    C.degree=MAX(A.degree,B.degree);
    while(Apos<=A.degree&&Bpos<=B.degree){
        if(degree_a>degree_b){
            C.coef[Cpos++]=A.coef[Apos++];  //������ �������� a���ִٸ� a���׽İ��� c����ü�� ����
            degree_a--;
            }
            else if(degree_a==degree_b){     //a���� b������ ���ٸ� a+b���� c����ü�� ����
                C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
                degree_a--;degree_b--;
            }
            else {                             //������ �������� b�� �ִٸ� b���׽� ���� c����ü�� ����
                C.coef[Cpos++]=B.coef[Bpos++];
                degree_b--;
            }
                    }
    return C;
    }

polynomial poly_sub1(polynomial A,polynomial B)    //���� �Լ�
{
    polynomial C;
    int Apos=0,Bpos=0,Cpos=0;
    int degree_a=A.degree;
    int degree_b=B.degree;
    C.degree=MAX(A.degree,B.degree);
    while(Apos<=A.degree&&Bpos<=B.degree){
        if(degree_a>degree_b){                  //������ ���� ���� a�� �ִٸ� a���׽� ���� c����ü�� ����
            C.coef[Cpos++]=A.coef[Apos++];
            degree_a--;
            }
            else if(degree_a==degree_b){              //a,b������ ���ٸ� a-b���� c����ü�� ����
                C.coef[Cpos++]=A.coef[Apos++]-B.coef[Bpos++];
                degree_a--;degree_b--;
            }
            else {                          //������ ���� ���� b�� �ִٸ� -b���׽� ���� c����ü�� ����
                C.coef[Cpos++]=-B.coef[Bpos++];
                degree_b--;
            }
                    }
    return C;
}

void print_poly(polynomial p)         //��� �Լ�
{
    for(int i=p.degree;i>=0;i--)         //���� �������� �������
    {
        if(p.coef[p.degree-i]!=0)             //����� 0�� �ƴҶ���
            printf("%+3.1fx^%d",p.coef[p.degree-i],i);   //����ü �迭�� 0���ε������� ���  %+3.1f =��ȣ ���
    }
    printf("\n");
}

int main(void)
{
    polynomial a, b, c;    //����ü ����
    int degree_a, degree_b;    //���� �Է¹��� ����
    int n;                     //������ ���� �Է¹��� ����

    printf("A���׽� ����: ");
    scanf("%d", &degree_a);

    printf("A���׽� ��� �Է� \n");
    for(int i =degree_a; i >= 0; i--) {      //������ ���� �׺��� �Է¹޾� �ε���0���� ������� ����
        printf("���  x^%d: ", i);
        scanf("%f", &a.coef[degree_a-i]);
    }
    a.degree = degree_a;

    printf("B���׽� ����: ");
    scanf("%d", &degree_b);

    printf("B���׽� ��� �Է� \n");
    for(int i = degree_b; i >= 0; i--) {
        printf("���  x^%d: ", i);
        scanf("%f", &b.coef[degree_b-i]);
    }
    b.degree = degree_b;

    printf("���׽� ���� 1)���� 2)���� :");
    scanf("%d",&n);
    printf("\nA���׽�:\n");
    print_poly(a);
    printf("\nB���׽�:\n");
    print_poly(b);
    switch(n){                   //n==1���� n==2���� ���̿ܿ��� "�߸��Ȱ� �Է�" ���
case 1:
    c=poly_add1(a,b);
    printf("\n---------------------------------------------\n");
    printf("A,B�� :\n");
    print_poly(c);
    break;
case 2:
    c=poly_sub1(a,b);
    printf("\n---------------------------------------------\n");
    printf("A,B�� :\n");
    print_poly(c);
    break;
default:
    printf("�߸��� �� �Է�");
    break;
    }
    return 0;
}


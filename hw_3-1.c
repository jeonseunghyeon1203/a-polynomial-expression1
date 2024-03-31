#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MAX_DEGREE 101

typedef struct{
int degree;  //차수
float coef[MAX_DEGREE];  //계수
}polynomial;

polynomial poly_add1(polynomial A,polynomial B)    //덧셈 함수
{
    polynomial C;
    int Apos=0,Bpos=0,Cpos=0;
    int degree_a=A.degree;
    int degree_b=B.degree;
    C.degree=MAX(A.degree,B.degree);
    while(Apos<=A.degree&&Bpos<=B.degree){
        if(degree_a>degree_b){
            C.coef[Cpos++]=A.coef[Apos++];  //차수가 같은항이 a만있다면 a다항식값을 c구조체에 저장
            degree_a--;
            }
            else if(degree_a==degree_b){     //a차수 b차수가 같다면 a+b값을 c구조체에 저장
                C.coef[Cpos++]=A.coef[Apos++]+B.coef[Bpos++];
                degree_a--;degree_b--;
            }
            else {                             //차수가 같은항이 b만 있다면 b다항식 값을 c구조체에 저장
                C.coef[Cpos++]=B.coef[Bpos++];
                degree_b--;
            }
                    }
    return C;
    }

polynomial poly_sub1(polynomial A,polynomial B)    //뺄셈 함수
{
    polynomial C;
    int Apos=0,Bpos=0,Cpos=0;
    int degree_a=A.degree;
    int degree_b=B.degree;
    C.degree=MAX(A.degree,B.degree);
    while(Apos<=A.degree&&Bpos<=B.degree){
        if(degree_a>degree_b){                  //차수가 같은 항이 a만 있다면 a다항식 값을 c구조체에 저장
            C.coef[Cpos++]=A.coef[Apos++];
            degree_a--;
            }
            else if(degree_a==degree_b){              //a,b차수가 같다면 a-b값을 c구조체에 저장
                C.coef[Cpos++]=A.coef[Apos++]-B.coef[Bpos++];
                degree_a--;degree_b--;
            }
            else {                          //차수가 같은 항이 b만 있다면 -b다항식 값을 c구조체에 저장
                C.coef[Cpos++]=-B.coef[Bpos++];
                degree_b--;
            }
                    }
    return C;
}

void print_poly(polynomial p)         //출력 함수
{
    for(int i=p.degree;i>=0;i--)         //높은 차수부터 순서대로
    {
        if(p.coef[p.degree-i]!=0)             //계수가 0이 아닐때만
            printf("%+3.1fx^%d",p.coef[p.degree-i],i);   //구조체 배열의 0번인덱스부터 출력  %+3.1f =부호 출력
    }
    printf("\n");
}

int main(void)
{
    polynomial a, b, c;    //구조체 선언
    int degree_a, degree_b;    //차수 입력받을 변수
    int n;                     //연산의 종류 입력받을 변수

    printf("A다항식 차수: ");
    scanf("%d", &degree_a);

    printf("A다항식 계수 입력 \n");
    for(int i =degree_a; i >= 0; i--) {      //차수가 높은 항부터 입력받아 인덱스0부터 순서대로 저장
        printf("계수  x^%d: ", i);
        scanf("%f", &a.coef[degree_a-i]);
    }
    a.degree = degree_a;

    printf("B다항식 차수: ");
    scanf("%d", &degree_b);

    printf("B다항식 계수 입력 \n");
    for(int i = degree_b; i >= 0; i--) {
        printf("계수  x^%d: ", i);
        scanf("%f", &b.coef[degree_b-i]);
    }
    b.degree = degree_b;

    printf("다항식 연산 1)덧셈 2)뺄셈 :");
    scanf("%d",&n);
    printf("\nA다항식:\n");
    print_poly(a);
    printf("\nB다항식:\n");
    print_poly(b);
    switch(n){                   //n==1덧셈 n==2뺄셈 그이외에는 "잘못된값 입력" 출력
case 1:
    c=poly_add1(a,b);
    printf("\n---------------------------------------------\n");
    printf("A,B합 :\n");
    print_poly(c);
    break;
case 2:
    c=poly_sub1(a,b);
    printf("\n---------------------------------------------\n");
    printf("A,B차 :\n");
    print_poly(c);
    break;
default:
    printf("잘못된 값 입력");
    break;
    }
    return 0;
}


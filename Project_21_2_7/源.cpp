#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>

int main()
{
    const int N = 10;
    const int M = 2;
    int* a = new int[N];
    for (int i = 0; i < N; ++i)
        a[i] = (0 == i % 2) ? (i + 2) : (i + 0);
    //2 1 4 3 6 5 8 7 10 9
    int(*b)[N / M] = (int(*)[N / M])a;
    for (int i = 0; i < M; ++i)
        for (int j = 0; j < N / M; ++j)
            printf("%d", b[i][j]);
    return 0;
}

//int main()
//{
//	char ch1, ch2, ch3;
//	scanf("%1c%2c%3c", &ch1, &ch2, &ch3);
//	printf("%1c-%2c-%3c", ch1, ch2, ch3);
//	return 0;
//}

//int main()
//{
//    unsigned char i = 7;
//    int j = 0;
//    for (; i > 0; i -= 3)
//    {
//        ++j;
//    }
//    printf("%d\n", j);
//    return 0;
//}

//int main()
//{
//	//char* s = "\ta\018bc";
//	//for (; *s != '\0'; s++)  printf("*");
//	printf("%d", '\11');
//	return 0;
//}

//#pragma pack(2)
//
//class A
//{
//	int i;
//	union U
//	{
//		char buf[13];
//		int i;
//	}u;
//	void foo() {};
//	typedef char* (*f)(void*);
//	enum
//	{
//		red,
//		green,
//		blue
//	}color;
//}a;

//enum{a,b,c,d,e,f}color;
//
//int main()
//{
//	int i = 010, j = 10;
//	printf("%d,%d\n", ++i, j--);
//	printf("%d", sizeof(color));
//	return 0;
//}

//int main()
//{
//	int a = 1, b = 2, m = 0, n = 0, k;
//	k = (n = b < a) && (m = a);
//	printf("%d,%d,%d\n", k, m, n);
//	return 0;
//}

//int main()
//{
//	const char* p1 = "hello";
//	char* const p2 = "world";
//	p1++;
//	printf("%s", p1);
//	return 0;
//}
#include <stdio.h>
#include <string.h>
#define MAXSIZE 50

// 声明结构体变量的成员,以及一个结构体变量digital
struct {
    int a;
    float b;
    char c;
} digital;


// 声明结构体变量 Books以及结构体成员
struct Books {
    char author[MAXSIZE];
    char title[MAXSIZE];
    float price;
};
// 用上述结构体类型声明变量
struct Books t1, t2[MAXSIZE], *t3;


// 用typedef创建新类型
typedef struct {
    char name[MAXSIZE];
    int age;
} Person;
// 用上述新类型声明变量
Person s1, s2[MAXSIZE], *s3;


int main(){
    int n;
    struct Books book;
    strcpy(book.author, "bill gates");
    strcpy(book.title, "Learning Python");
    book.price = 12.5;

    printf("%s\n", book.author);
    printf("%s\n", book.title);

    Person zhao;
    strcpy(zhao.name, "zhaopengfei");
    zhao.age = 10;

    printf("请输入正确的编号:\n");
    scanf("%d", &n);

    printf("%s\n", zhao.name);
    printf("%d\n", zhao.age);
}
//File:  menu.c
//Theme: A small menu program with a command line,calls specific function when
//       executing a command
//Author:wu xiale
//Date:  2017.09.19

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Declaration of functions
void help();
void hello();
void quit();
void rectangle();
void add();
void subtract();
void multiply();
void divide();

int main()
{
    char cmd[128];
    while(1)
    {
        scanf("%s", cmd);
        if( strcmp(cmd, "help") == 0 )
        {
            help();
        }
        else if( strcmp(cmd, "hello") == 0 )
        {
            hello();
        }
        else if( strcmp(cmd, "quit") == 0 )
        {
            quit();
        }
        else if( strcmp(cmd, "rectangle") == 0 )
        {
            rectangle();
        }
        else if( strcmp(cmd, "add") == 0 )
        {
            add();
        }
        else if( strcmp(cmd, "subtract") == 0 )
        {
            subtract();
        }
        else if( strcmp(cmd, "multiply") == 0 )
        {
            multiply();
        }
        else if( strcmp(cmd, "divide") == 0 )
        {
            divide();
        }
        else
        {
            printf("Error Command!!\n");
            printf("You can input 'help' to get more information\n");
        }
    }
    return 0;
}

//Show all of the commands which you can use
void help()
{
    printf("+=============+=================================+\n");
    printf("|  command    |  description                    |\n");
    printf("+=============+=================================|\n");
    printf("|  help       |  command details                |\n");
    printf("|  hello      |  welcome                        |\n");
    printf("|  quit       |  exit command                   |\n");
    printf("|  rectangle  |  draw a rectangle               |\n");
    printf("|  add        |  addition of two numbers        |\n");
    printf("|  subtract   |  subtraction of two numbers     |\n");
    printf("|  multiply   |  multiplication of two numbers  |\n");
    printf("|  divide     |  division of two numbers        |\n");
    printf("+=============+=================================+\n");
}

//Exit program
void quit()
{
    exit(0);
}

//well,show you my enthusiam
void hello()
{
    printf("===============================================\n");
    printf("My name is Wu Xiale\n");
    printf("Thank you for your using my program\n");
}

//Draw a rectangle
void rectangle()
{
    int length,width;
    int row,colume;
    printf("===============================================\n");
    printf("rectangle!\n Please input length and width:\n");
    printf("(Type-in format as:length,width)\n");
    scanf("%d, %d", &length, &width);
    for(row=1; row<=width; row++)
    {
        for(colume=1; colume<=length; colume++)
        {
            printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

//The addition of two numbers
void add()
{
    double num1, num2, add;
    printf("===============================================\n");
    printf("Addition!\n Please input two numbers:\n");
    scanf("%lf %lf", &num1, &num2);
    add = num1 + num2;
    printf("%lf + %lf = %lf\n", num1, num2, add);
    printf("===============================================\n");
}

//The subtract of two numbers
void subtract()
{
    double num1, num2, sub;
    printf("===============================================\n");
    printf("Subtraction!\n Please input two numbers:\n");
    scanf("%lf %lf", &num1, &num2);
    sub = num1 - num2;
    printf("%lf - %lf = %lf\n", num1, num2, sub);
    printf("===============================================\n");
}

//Multiplication of two numbers
void multiply()
{
    double num1, num2, multi;
    printf("===============================================\n");
    printf("Multiplication!\n Please input two numbers:\n");
    scanf("%lf %lf", &num1, &num2);
    multi = num1 * num2;
    printf("%lf * %lf = %lf\n", num1, num2, multi);
    printf("===============================================\n");
}

//Division of two numbers
void divide()
{
    double num1, num2, div;
    printf("===============================================\n");
    printf("Division!\n Please input two numbers:\n");
    scanf("%lf %lf", &num1, &num2);
    if( num2 == 0 )
    {
        printf("Error:divisor cannot be aero!\n");
        printf("===============================================\n");
    }
    else
    {
        div = num1 / num2;
        printf("%lf / %lf = %lf\n",num1, num2, div);
        printf("===============================================\n");
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define STACK_SIZE 8

float stack[STACK_SIZE];

void printStack(void)
{
    int i;
    for (i = 0; i < 8; i++)
    {
        printf("%d. ", 8 - i);
        printf("%f", stack[i]);
        printf("\n");
    }
}

void moveStackUp(void)
{
    int i;
    for (i = 1; i < 8; i++)
    {
        stack[i - 1] = stack[i];
    }
}

void moveStackDown(void)
{
    int i;
    for (i = 7; i > 0; i--)
    {
        stack[i] = stack[i - 1];
    }
    stack[0] = 0;
}

void operaciones(char operador)
{
    float num2 = stack[7];
    float num1 = stack[6];
    float res, valor, pi = 3.14159265358979323846;

    switch (operador)
    {
    case '+':
        res = num1 + num2;
        break;
    case '-':
        res = num1 - num2;
        break;
    case '*':
        res = num1 * num2;
        break;
    case '/':
        if (num2 == 0)
        {
            printf("Math Error\n");
            return;
        }
        res = num1 / num2;
        break;
    case '^':
        res = pow(num1, num2);
        break;
    case 'r':
        if (num2 < 0)
        {
            printf("Math Error\n");
            return;
        }
        res = sqrt(num2);
        break;
    case 's':
        valor = num2 * (pi / 180.0);
        res = sin(valor);
        break;
    case 'c':
        valor = num2 * (pi / 180.0);
        res = cos(valor);
        break;
    case 't':
        valor = num2 * (pi / 180.0);
        res = tan(valor);
        break;
    case 'l':
        res = log(num2);
        break;
    default:
        printf("Operador no valido\n");
        return;
    }

    if (operador == 'r' || operador == 's' || operador == 'c' || operador == 't' || operador == 'l')
    {
        stack[7] = res;
        return;
    }
    stack[6] = res;
    moveStackDown();
}

int main(void)
{
    int i, opc;
    float buf = 0, res = 0, pi = 3.14159265358979323846;
    char bufc;
    for (i = 0; i < 8; i++)
    {
        stack[i] = 0;
    }
    printf("Calculadora RPN\n");

    while (true)
    {
        printStack();
        printf("\n");
        printf("1. Ingresar numero  2. Seleccionar operacion  3. Limpiar último  4. Limpiar todo  5. Salir\n");
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
        {
            printf("\033[2J");
            printStack();
            printf("Ingrese el numero: ");
            scanf("%f", &buf);
            moveStackUp();
            stack[7] = buf;
            printf("\033[2J");
            break;
        }
        case 2:
        {
            printf("\nSeleccione la operacion:\n");
            printf("+, -, *, /, ^, r(raiz cuadrada), s(seno), c(coseno), t(tangente), l(logaritmo)\n");
            char operador;
            scanf(" %c", &operador);
            printf("\033[2J");
            operaciones(operador);
            break;
        }
        case 3:
        {
            printf("\033[2J");
            printf("Limpiando ultimo...\n");
            moveStackDown();
            break;
        }
        case 4:
        {
            printf("\033[2J");
            printf("Limpiando todo...\n");
            for (i = 0; i < 8; i++)
            {
                stack[i] = 0;
            }
            break;
        }
        case 5:
        {
            printf("Saliendo...\n");
            exit(0);
        }
        default:
            printf("Opcion no valida\n");
            break;
        }
    }

    return 0;
}
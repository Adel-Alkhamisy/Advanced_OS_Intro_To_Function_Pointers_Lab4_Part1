/**
 * Function Pointer Calculator
 * 
 * This program demonstrates the use of function pointers by implementing
 * a simple calculator that performs basic arithmetic operations on two fixed values.
 * The program uses an array of function pointers to call the appropriate operation
 * based on user input without using conditional statements.
 */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes for arithmetic operations */
int performAddition(int a, int b);
int performSubtraction(int a, int b);
int performMultiplication(int a, int b);
int performDivision(int a, int b);
int exitProgram(int a, int b);

/* Define a new type 'OperationFunction' for function pointers that take two ints and return an int */
typedef int (*OperationFunction)(int a, int b);

int main(void)
{
    /* Initialize operand values */
    int a, b;
    a = 6;
    b = 3;
    
    /* Create an array of function pointers for each operation */
    OperationFunction operations[5] = {
        &performAddition, 
        &performSubtraction, 
        &performMultiplication, 
        &performDivision, 
        &exitProgram
    };
    
    /* Buffer to store user input for operation selection */
    char operationChoice[3];
    
    /* Main program loop */
    while (1) {
        /* Display menu and get user choice */
        printf("Operand 'a' : %d | Operand 'b' : %d\nSpecify the operation to perform (0 : add | 1 : subtract | 2 : Multiply | 3 : divide | 4 : exit): ", a, b);
        fgets(operationChoice, 3, stdin);
        
        /* Call the appropriate function using the function pointer array
           Convert character digit to integer index by subtracting ASCII value of '0' */
        int result = operations[(int)operationChoice[0]-'0'](a, b);
        printf("X = %d\n", result);
    }
    
    return 0;
}

/* Operation function implementations */
int performAddition(int a, int b) { 
    printf("Adding 'a' and 'b'\n"); 
    return a + b; 
}

int performSubtraction(int a, int b) { 
    printf("Subtracting 'a' and 'b'\n"); 
    return a - b; 
}

int performMultiplication(int a, int b) { 
    printf("Multiplying 'a' and 'b'\n"); 
    return a * b; 
}

int performDivision(int a, int b) { 
    printf("Dividing 'a' and 'b'\n"); 
    return a / b; 
}

int exitProgram(int a, int b) { 
    /* Terminate the program with success status */
    exit(0); 
}
/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Element;

typedef struct StackNode {
    Element data;
    struct StackNode* next;
} StackNode;

typedef struct {
    StackNode* top;
} LinkedStackNode;

void init_stack(LinkedStackNode* s) {
    s->top = NULL;
}

int is_empty(LinkedStackNode* s) {
    return s->top == NULL;
}

void print_stack(LinkedStackNode* s) {
    for (StackNode* node = s->top; node != NULL; node = node->next) {
        printf("%d -> ", node->data);
    }
    printf("NULL\n");
}

void push(LinkedStackNode* s, Element data) {
    StackNode* node = (StackNode*)malloc(sizeof(StackNode));
    node->data = data;
    node->next = s->top;
    s->top = node;
}

Element pop(LinkedStackNode* s) {
    if (is_empty(s)) {
        printf("Stack is empty");
        return -1;
    }
    
    StackNode* temp = s->top;
    s->top = temp->next;
    Element data = temp->data;
    free(temp);
    return data;
}

int checker(const char* str) {
    LinkedStackNode* s = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
    init_stack(s);
    
    for (int i = 0; i < strlen(str); ++i) {
        char c = str[i];
        
        if (c == '(' || c == '{' || c == '[') {
            push(s, c);
            continue;
        }
        
        if (c == ')' || c == '}' || c == ']') {
            if (is_empty(s)) {
                return 0;
            }
            
            char opener = pop(s);
            if (
                (opener == '(' && c != ')') || 
                (opener == '{' && c != '}') || 
                (opener == '[' && c != ']')
            ) {
                return 0;
            }
        }
    }
    
    return is_empty(s);
}

int eval(char exp[]) {
    LinkedStackNode* s = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
    init_stack(s);
    
    for (int i = 0; i < strlen(exp); ++i) {
        char ch = exp[i];
        
        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int second = pop(s);
            int first = pop(s);
            int result = 0;
            
            switch (ch) {
            case '+':
                result = first + second;
                break;
            case '-':
                result = first - second;
                break;
            case '*':
                result = first * second;
                break;
            case '/':
                result = first / second;
                break;
            }
            
            push(s, result);
        } else {
            push(s, ch - '0');
        }
    }
    
    return pop(s);
}

int prec(char op) {
    switch(op) {
        case'(':
        case')':
            return 0;
        case'+':
        case'-':
            return 1;
        case'*':
        case'/':
            return 2;
    }
    return -1;
}

char* eval2(char exp[]) {
    LinkedStackNode* s = (LinkedStackNode*)malloc(sizeof(LinkedStackNode));
    init_stack(s);
    
    char* tmp = (char*)malloc(sizeof(char) * (strlen(exp) + 1));
    int cnt = 0;
    char top;
    
    for (int i = 0; i < strlen(exp); ++i) {
        char c = exp[i];
        switch (c) {
        case '+':
        case '-':
        case '*':
        case '/':
            while (!is_empty(s) && prec(c) <= prec(s->top->data)) {
                tmp[cnt++] = pop(s);
            }
            push(s, c);
            break;

        case '(':
            push(s, c);
            break;

        case ')':
            top = pop(s);
            while (top != '(') {
                tmp[cnt++] = top;
                top = pop(s);
            }
            break;

        default:
            tmp[cnt++] = c;
            break;
        }
    }
    
    while (!is_empty(s)) {
        tmp[cnt++] = pop(s);
    }
    tmp[cnt] = '\0';
    
    return tmp;
}

int main()
{
    // printf("res: %d", checker("{ A[(i+1)]=0;}}"));
    // int result;
    // printf("후위표기식은 82/3-32*+\n");
    // result = eval((char*)"82/3-32*+");
    // printf("결과값은 %d\n", result);
    // return 0;
    
    char* s = (char*)"5+(4+1)*2/4";
    printf("중위표시수식 %s \n", s);
    char* trans = eval2(s);
    printf("후위표시수식 %s \n", trans);
    int result = eval(trans);
    printf("result %d\n", result);
    return 0;
}

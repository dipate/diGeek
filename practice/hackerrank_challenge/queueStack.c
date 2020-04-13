#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_STACK_SIZE 100000

uint32_t s1[MAX_STACK_SIZE] = {0};
uint32_t s2[MAX_STACK_SIZE] = {0};

uint32_t s1top = 0;
uint32_t s2top = 0;

// two stacks
// s1 and s2
//
// enQ operation :
// - push on s1 if underflow
//
// deQ operation :
// - check if s2 underflow/empty
// - if underflow then copy from s1 top to bottom into s2
//
// print:
// - check if s2 underflow/empty
// - if underflow then copy from s1 top to bottominto s2
// - else return the top of the s2

int enQ(int data)
{
    push(1, s1top++, data);
    return 0;
}

int push(int flag, int top, int data)
{
    if(top > MAX_STACK_SIZE)
    {
        // overflow
        return -1;
    }
    if(1 == flag)
    {
        s1[top] = data;
    }
    else if(2 == flag)
    {
        s2[top] = data;
    }
    return 0;
}

int pop(int flag, int top)
{
    if(top < 0)
    {
        // underflow
        return -1;
    }
    if(1 == flag)
    {
        s1[top] = 0;
    }
    else if(2 == flag)
    {
        s2[top] = 0;
    }

    return 0;
}

int deQ()
{
    if(s2top == 0)
    {
        while(s1top)
        {
            s1top--;
            push(2, s2top++, s1[s1top]);
            pop(1, s1top);
        }
    }

    if(s2top > 0)
        pop(2, --s2top);
    return 0;
}

int print()
{
    if(s2top == 0)
    {
        while(s1top)
        {
            s1top--;
            push(2, s2top++, s1[s1top]);
            pop(1, s1top);
        }
    }

    if(s2top > 0)
        printf("%d\n", s2[s2top-1]);
    return 0;
}

int main()
{
    // type : 1-enQ, 2-deQ, 3-print the front of Q
    uint32_t q = 0;
    uint32_t t = 0;
    uint32_t x = 0;
    uint32_t i = 0;

    scanf("%d", &q);
    for(i = 0; i < q ; i++)
    {
        scanf("%d", &t);
        if(1 == t)
        {
            scanf("%d", &x);
            //enQ x
            enQ(x);
        }
        else if(2 == t)
        {
            // deQ
            deQ();
        }
        else if(3 == t)
        {
            print();
            // print front
        }
    }
    return 0;
}

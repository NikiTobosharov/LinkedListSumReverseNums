#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct list
{
    int data;
    struct list *next; 
}list;

void initList(struct list **start, int value);
void printList(struct list *start);
void freeList(struct list *start);
void appendElement(struct list *start, int value);
void reverseList(struct list **start);
int combineNumbers(struct list *start);
int reverseNumber(int num);

int main()
{
    struct list* listOne = NULL;
    struct list* listTwo = NULL;
    int num = 0;
    int numTwo = 0;
    if (scanf("%d", &num) != 1) {
        printf("Error reading input.\n");
        return 1;
    }
    initList(&listOne, num); 
    while (scanf("%d", &num) == 1 && num != -1)
    {
         appendElement(listOne, num);
    }


    if (scanf("%d", &numTwo) != 1) {
        printf("Error reading input.\n");
        return 1;
    } 

    initList(&listTwo, numTwo);

    while (scanf("%d", &numTwo) == 1 && numTwo != -1)
    {
        appendElement(listTwo, numTwo);
    }

    reverseList(&listOne);
    reverseList(&listTwo);

    int combinedNumber = combineNumbers(listOne) + combineNumbers(listTwo);
    int reversedCombinedNumber = reverseNumber(combinedNumber);
    printf("Combined and reversed number: %d\n", reversedCombinedNumber);
      
    freeList(listOne);
    freeList(listTwo);
}


void initList(struct list **start, int value)
{
    if (*start != NULL)
    {
        printf("Not NULL as expected.\n");
        exit(EXIT_FAILURE);
    }

    *start = malloc(sizeof(struct list));

    if (*start == NULL)
    {
        printf("Allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    (*start)->data = value;
    (*start)->next = NULL;
}


int combineNumbers(struct list *start) {
    int combined = 0;
    while (start != NULL) {
        combined = combined * 10 + start->data;
        start = start->next;
    }
    return combined;
}

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

void printList(struct list *start)
{
    while (start != NULL)
    {
       printf("value: %d\n", start->data);
       start = start->next;
    }
    putchar('\n');
}

void freeList(struct list *start)
{
    list *next = NULL;

    while (start != NULL)
    {
        next = start->next;
        free(start);
        start = next;
    }
}

void appendElement(struct list *start, int value)
{
    list *newElement = malloc(sizeof(struct list));

    if(newElement == NULL)
    {
        printf("Allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    newElement->data = value;
    newElement->next = NULL;

    while (start->next != NULL)
    {
        start = start->next;
    }

    start->next = newElement;
}

void reverseList(struct list **start)
{
    struct list *prev = NULL;
    struct list *current = *start;
    struct list *next = NULL;

    while (current != NULL) 
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *start = prev;
}

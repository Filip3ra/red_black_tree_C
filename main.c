#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

void free_elem(void *elem)
{
    free(elem);
}

int comp(int *a, int *novo)
{
    if(*a < *novo)
        return 1;
    else if(*a > *novo)
        return -1;
    else
        return 2;
}

void print(TNo *no, int *elem)
{
/*
    if(no->pai != NULL)
    {
        printf("%i - pai[%i]\n",*elem, (*(int*)(no->pai->elem))  );
    }
    else

7 4 3 2 6 11 9 18 14 12 17 19 22 10
        printf("root - %i\n",*elem);
*/


    if(no->pai == NULL)
    {
        if(no->cor == 1)
            printf("%i - black - root\n",*elem);
        else if(no->cor == 2)
            printf("%i - red - root\n",*elem);
    }
    else
    {

        if(no->cor == 1)
            printf("%i - black - pai[%i]\n",*elem, (*(int*)(no->pai->elem)) );
        else
            printf("%i - red - pai[%i]\n",*elem, (*(int*)(no->pai->elem)) );
    }

}

int main()
{

    TNo **tree = (TNo*)malloc(sizeof(TNo)); /* inicializar a arvore! */
    int *number;


     number = (int*)malloc(sizeof(int));
    *number = 11;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 2;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 14;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 1;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 15;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 7;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 5;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 8;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    number = (int*)malloc(sizeof(int));
    *number = 4;
    insert_tree(tree, fulfill_node(number), &comp, &print);

    printf(">>>>\n");

    print_tree( (*tree), &print );

    free_elem(number);
    free(tree);

    return 0;
}

/*

(*(int*)(no->pai->elem)) typecastingg um void *

 */

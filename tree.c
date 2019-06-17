#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int empty_tree(TNo *t)
{
    if(t == NULL)
        return 1;
    return 0;
}

TNo *fulfill_node( void *elem )
{
    TNo *no   = (TNo*)malloc(sizeof(TNo));
    no->elem  = elem;
    no->left  = NULL;
    no->right = NULL;
    no->pai   = NULL;
    no->cor = 2;

    return no;
}

void insert_tree( TNo **t, TNo *z, int (*comp)(), void (*print)() )
{

    TNo *p;
    TNo *q;
    int a;

    p = (*t);
    q = NULL;

    if( (*t) == NULL )
    {
        (*t) = z;
        z->pai = NULL;
        printf("root inserido\n");
    }
    else
    {   /* Percorro até encontrar a posição */
        while( p != NULL)
        {
            q = p;
            if( comp(p->elem, z->elem) == 1)
                p = p->right;
            else if( comp(p->elem, z->elem) == -1 )
                p = p->left;
        }
        /* depois que encontrei eu atribuo */
        z->pai = q;
        a = comp(q->elem, z->elem);


        if( comp(q->elem, z->elem) == 1 )
        {
            q->right = z;
            print(q->right,q->right->elem);
        }
        else if( comp(q->elem, z->elem) == -1 )
        {
            q->left = z;
            print(q->left,q->left->elem);
        }
    }
    insert_fixup(t,z);
}


void insert_fixup(TNo **t, TNo *z )
{

    TNo *g;
    TNo *u;

    /* Caso 1 - Se raiz for vermelho, corrige pra preto */
    if( (*t) == z )
    {
        z->cor = 1;
    }
    /* Se o pai existe e o pai é vermelho */
    else if(z->pai != NULL && z->pai->cor == 2)
    {
        g = z->pai->pai; /* avô */
        if(g->left == z->pai)
        {
            if(g->right != NULL)
            {
                u = g->right; /* tio na direita do avô */
                if(u->cor == 2)
                {
                    z->pai->cor = 1;
                    u->cor = 1;
                    g->cor = 2;
                    z = g;
                }

            }
            else
            {   /* se estamos na direita... */
                if(z->pai->right == z)
                {
                    z = z->pai;
                    left_rotate(t,z);
                }
                /* se não, estamos na esquerda */
                else
                {
                    z->pai->cor = 1;
                    g->cor = 2;
                    right_rotate(t,g);
                }

            }

        }
        else
        {
            if(g->left != NULL)
            {
                u = g->left;
                if(u->cor == 2)
                {
                    z->pai->cor = 1;
                    u->cor = 1;
                    g->cor = 2;
                    z = g;
                }
            }
            else
            {   /* se estamos na esquerda... */
                if(z->pai->left == z)
                {
                    z = z->pai;
                    right_rotate(t,z);
                }
                /* se não, estamos na direita */
                else
                {
                    z->pai->cor = 1;
                    g->cor = 2;
                    left_rotate(t,g); /* <------ ESTAMOS AQUI */
                }

            }
        }
        /* root->cor = 1 a raiz principal deve mudar pra preto */
        (*t)->cor = 1;
    }
}

void left_rotate(TNo **t, TNo *g)
{
    printf("left rotate \n");
    TNo *y;

    if(g->right == NULL)
        return ;
    else
    {
        y = g->right;
        if(y->left != NULL)
        {
            g->right = y->left;
            y->left->pai = g;
        }
        else
            g->right = NULL;

        if(g->pai != NULL)
        {
            y->pai = g->pai;
        }
        else if(g->pai == NULL)
        {
            /* root = y */
            (*t) = y;
        }
        else
        {
            if(g == g->pai->left)
                g->pai->left = y;
            else
                g->pai->right = y;
        }
        y->left = g;
        g->pai = y;
    }
}

void right_rotate(TNo **t, TNo *g)
{
    printf("right rotate \n");
    TNo *y;

    if(g->left == NULL)
        return ;
    else
    {
        y = g->left;
        if(y->right != NULL)
        {
            g->left = y->right;
            y->right->pai = g;
        }
        else
            g->left = NULL;

        if(g->pai != NULL)
        {
            y->pai = g->pai;
        }
        else if(g->pai == NULL)
        {
            /* root = y */
            (*t) = y;
        }
        else
        {
            if(g == g->pai->left)
                g->pai->left = y;
            else
                g->pai->right = y;
        }
        y->right = g;
        g->pai = y;
    }
}

void print_tree(TNo *t, void (*print)() )
{
    if(!empty_tree(t))
    {
        print_tree(t->left, print);
        print(t,t->elem);
        print_tree(t->right, print);
    }



}




#include "evalexp.h"
#include <stdlib.h>
#include <string.h>

typedef struct env
{
    char name[8];
    int value;
    struct env *next;
} enviro;

enviro newVar(struct exp *e, struct env *env)
{
    if(env->value)
    {
        struct env *new = malloc(sizeof(enviro));
        strncpy(new->name, e->var, 8);
        new->next = env;
        new->value = evalexp(e->bexp);
        return *new;
    }
    else
    {
        strncpy(env->name, e->var, 8);
        env->value = evalexp(e->bexp);
        return *env;
    }
}

// Checks the enviroment list to see if the variable exists in it. If not, it adds the variable to the environment.
int evalexpenv(struct exp *e, struct env *env)
{
    enviro *current = env;
    do
    {
        if(current->name == e->var)
        {
            return current->value;
        }
        current = current->next;
    } while(current->next);
    return 0;
}

int evalexp(struct exp *e)
{
    enviro *head = malloc(sizeof(enviro));
    head->value = (int)NULL;
    head->next = NULL;

    switch(e->tag)
    {
        case islet :
            *head = newVar(e, head);
            return evalexp(e->body);
        break;

        case isconstant :
            return e->constant;
        break;

        case isvar :
            return evalexpenv(e, head);
        break;

        case isopapp :
            switch(e->op)
            {
                case isplus :
                    if (e->exps) {
                        struct explist *current = e->exps;
                        int total = 0;
                        while(current)
                        {
                            total = total + evalexp(current->head);
                            current = current->tail;
                        }
                        return total;
                    }
                    else
                    {
                        return 0;
                    }
                break;

                case ismult :
                    if (e->exps) {
                        struct explist *current = e->exps;
                        int total = 0;
                        while(current)
                        {
                            total = total * evalexp(current->head);
                            current = current->tail;
                        }
                        return total;
                    }
                    else
                    {
                        return 1;
                    }
                break;
            }
        break;
    }
}
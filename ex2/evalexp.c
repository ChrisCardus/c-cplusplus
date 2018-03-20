#include "evalexp.h"
#include <stdlib.h>
#include <string.h>

typedef struct env
{
    char name[8];
    int value;
    struct env *next;
} enviro;

// Checks the enviroment list to see if the variable exists in it. If not, it adds the variable to the environment.
int evalexpvar(struct exp *e, struct env *env)
{
    enviro *current = env->next;
    while(current)
    {
        if(strcmp(current->name, e->var) == 0)
        {
            return current->value;
        }
        current = current->next;
    }
    return 0;
}

int evalexpenv(struct exp *e, struct env *env)
{
    switch(e->tag)
    {
        case islet :
            if(1==1)
            {
                enviro *position = env;
                while(position->next)
                {
                    position = position->next;
                }

                enviro *new = malloc(sizeof(enviro));
                strncpy(new->name, e->bvar, 8);
                new->value = evalexpenv(e->bexp, env);
                position->next = new;
                return evalexpenv(e->body, env);
            }
        break;

        case isconstant :
            return e->constant;
        break;

        case isvar :
            return evalexpvar(e, env);
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
                            total = total + evalexpenv(current->head, env);
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
                        int total = 1;
                        while(current)
                        {
                            total = total * evalexpenv(current->head, env);
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

int evalexp(struct exp *e)
{
    enviro *head = malloc(sizeof(enviro));
    head->next = NULL;
    return evalexpenv(e, head);
}
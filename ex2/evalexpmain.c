// main function for evaluation expression exercise

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "evalexp.h"

// tree construction functions

struct exp *mkvar(char *cp)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = isvar;
  strncpy(ep->var, cp, 8);
  return ep;
}

struct exp *mkconstant(int n)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = isconstant;
  ep->constant = n;
  return ep;
}

struct exp *mkopapp(enum op op, struct explist *el)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = isopapp;
  ep->op =  op;
  ep->exps =  el;
  return ep;
}

struct exp *mklet(char *cp, struct exp *e1, struct exp *e2)
{
  struct exp *ep = malloc(sizeof(struct exp));
  ep->tag = islet;
  strncpy(ep->bvar, cp, 8);
  ep->bexp = e1;
  ep->body = e2;
  return ep;
}

struct explist *cons(struct exp *e, struct explist *l)
{
  struct explist *l2 = malloc(sizeof(struct explist));
  l2->head = e;
  l2->tail = l;
  return l2;
}

// main for testing

int main(int argc, const char *argv[])
{
  struct exp *e1, *e2, *e3, *e4;
  struct explist *l;
  int points = 0;    

  l = NULL;
  l = cons(mkconstant(5), l);
  l = cons(mkconstant(3), l);
  l = cons(mkconstant(2), l);
  e1 = mkopapp(isplus, l);
  // e1 is (+ 2 3 5)
  // should eval to 10

  l = NULL;
  l = cons(mkvar("x"), l);
  l = cons(mkvar("x"), l);
  l = cons(mkvar("x"), l);
  e2 = mkopapp(ismult, l);
  // e2 is (* x x x)
  
  e3 = mklet("x", e1, e2);
  // e3 is (= x (+ 2 3 5) (* x x x))
  // should eval to 1000
 
  e4 = mklet("x", mkopapp(ismult, NULL), e2);
  // e4 is (= x (*) (* x x x))    
  // should eval to 1

  if(evalexp(e1) * evalexp(e1) == 100)
    points +=2;
  if(evalexp(e3) + evalexp(e4) == 1001) 
    points += 3;

  printf("Points for these tests: %d/5\n", points);

  return 0;
}



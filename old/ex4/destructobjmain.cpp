
#include <string>
#include <iostream>

using namespace std;

#include "destructobj.h"

int main(int argc, const char *argv[])
{
  ExpList *l;
  Exp *e1;
  // we build an AST; no sharing

  l = nullptr;
  l = new ExpList(new Var("y"), l);
  l = new ExpList(new Constant(10), l);
  l = new ExpList(new Var("foo"), l);
  e1 = new OpApp(timesop, l);
  e1 = new Let("y", new Constant(2), e1);
  e1 = new Let("bar", e1, new Var("bar"));
  e1 = new Let("y", new Constant(2), e1);
  e1 = new Let("bar", e1, new Var("bar"));

  delete e1;
  // There should be no errors or leaks
  cout << "AST destructor called." << endl;

  return 0;
}



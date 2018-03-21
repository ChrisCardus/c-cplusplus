
#include <string>
#include <iostream>

using namespace std;

#include "evalobj.h"

int main(int argc, const char *argv[])
{
  ExpList *l = nullptr;

  Exp *e1 = nullptr;

  int points = 0;

  l = new ExpList(new Constant(12), l);
  l = new ExpList(new Constant(3), l);
  l = new ExpList(new Constant(5), l);

  e1 = new OpApp(plusop, l);
  if (e1->eval(nullptr) == 20) 
    points += 2;
 
  l = nullptr;
  l = new ExpList(e1, l);
  l = new ExpList(new Var("y"), l);
  l = new ExpList(new Constant(10), l);
  e1 = new OpApp(timesop, l);
  e1 = new Let("y", new Constant(2), e1);
  // e1 is (= y 2 (* 10 y (+ 12 3 5)))

  e1 = new Let("foo", e1, new Var("foo"));
  if (e1->eval(nullptr) == 400)
    points += 3;

  cout << points << " points" << endl;

  return 0;
}


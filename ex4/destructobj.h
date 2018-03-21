#pragma once

class Exp {
 public:
  virtual ~Exp();
};

class Constant : public Exp {
  int n;
 public:
  Constant(int n) {this->n = n; }
  ~Constant();
};

class Var : public Exp {
  string name;
 public:
  Var(string s) { this->name = s; }
  ~Var();
};

class Let : public Exp {
  string bvar;
  Exp *bexp;
  Exp *body;
 public:
  Let(string v, Exp *e, Exp *b)
    {
      bvar = v; bexp = e; body = b;
    }
  ~Let();
};

class ExpList {
 public:
  Exp *head;
  ExpList *tail;
  ExpList(Exp *h, ExpList *t) { head = h; tail = t; }
};

enum op { plusop, timesop };

class OpApp : public Exp {
  enum op op;
  ExpList *args;
 public:
  OpApp(enum op o, ExpList *a) { op = o; args = a; }
  ~OpApp();
};


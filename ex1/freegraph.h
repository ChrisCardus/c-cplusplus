// freegraph interface

struct N {
  struct N *x;
  struct N *y;
  struct N *z;
  long data;
};

void deallocate(struct N *ap);


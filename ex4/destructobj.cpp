#include <string>
using namespace std;
#include "destructobj.h"

Exp::~Exp()
{

}

Constant::~Constant()
{

}

Var::~Var()
{

}

Let::~Let()
{
    delete bexp;
    delete body;
}

OpApp::~OpApp()
{
    ExpList *current = args;
    while(current)
    {
        delete current->head;
        ExpList *temp = current;
        current = current->tail;
        delete temp;
    }
}
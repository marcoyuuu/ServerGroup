//Archivo de aplicacion main.cpp
#include "serverGroup.cpp"
#include "serverGroup.h"
#include <iostream>
using namespace std;

int main()
{
    ServerGroup<int> s1(4);
    ServerGroup<int> s2 = s1;
    s1.testServer(s2);
    s1.changeValues();
    s1.testServer(s2);
    return 0;
}

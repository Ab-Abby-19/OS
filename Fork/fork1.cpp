#include <iostream>
#include <unistd.h>
using namespace std;
  
int main()
{
    fork();
    cout << "Hello" << endl;
  
    return 0;
}

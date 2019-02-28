#include <iostream>
#include "function.h"
#include <boost/version.hpp>
using namespace std;

int main(){
    cout << "Hello, World!" << endl;
    cout << "version:"<< get_version() << endl;
    return 0;
}

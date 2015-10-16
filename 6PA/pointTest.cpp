#include <iostream>
using namespace std;


void myFunc(int* changeDis);

int main(){
	int* me;
	myFunc(me);
	cout << *me;
}

void myFunc(int* changeDis){
	changeDis = 4;
}

#include<iostream>
#include<cstdlib>
using namespace std;
class DeadGame {
private:
	int length;
	int* intptr;
public:
    DeadGame(int);
    ~DeadGame();
	int operator+(int);
	int operator-(int);
	void display();
	bool kill(int);
	friend int operator+(int, DeadGame);
	friend int operator+(int, DeadGame);
};
DeadGame::DeadGame(int c) {
	length = c;
	intptr = new int[length];
	for (int I = 0; I < length; I++) {
		intptr[I] = I + 1;
	}
}
DeadGame::~DeadGame() {
	delete[] intptr;
	cout << "the object has been deleted\n";
}
void DeadGame::display() {
	if (length == 1)
		cout << "the last suvivor is number" << intptr[0];
	else
		cout << "error";
}
bool DeadGame::kill(int c) {
	if (length > 1) {
		length--;
		int *bak = new int[length];
		for (int I = 0; I < length; I++)
			bak[I] = intptr[(c+1+I)%(length+1)];
		for (int I = 0; I < length; I++)
		    intptr[I] = bak[I];
		for (int I = 0; I < length; I++)
		    cout<<intptr[I]<<" ";
		cout << endl;
		delete[] bak;
		return true;
	}
	else
        return false;
}
int operator+(int c, DeadGame cy) {
	return cy + c;
}
int operator-(int c, DeadGame cy) {
	return cy - c;
}
int DeadGame::operator+(int c) {
	return (c % length)-1;
}
int DeadGame::operator-(int c) {
	return length - (c % length);
}
int main()
{   int n, k;
	cin >> n >> k;
	DeadGame cy(n);
	while (cy.kill(cy+k)) { continue; }
	cy.display();
	system("pause");
	return 0;
}
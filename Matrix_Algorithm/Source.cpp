#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class MyMatrix {
private: int N;
private: int M; 
private: int** matrix;
public: MyMatrix(int n, int m) {
			 N = n;
			 M = m;
			 matrix = new int*[N];
			 for (int i = 0; i < N; i++)
				 matrix[i] = new int[M];
		 }
public:  void getSize() {
			 cout << "matrix[" << N << "][" << M << "];" << endl;
		 }
public:  void randomSet() {
			 for (int i = 0; i < N; i++)
				 for (int j = 0; j < M; j++)
					 matrix[i][j] = rand()%100;
		 }
public:  void userSet() {
			 for (int i = 0; i < N; i++) {
				 for (int j = 0; j < M; j++) {
					 cout << "matrix[" << i << "][" << j << "] = ";
					 cin >> matrix[i][j];
				 }
			 }
		 }
public:  void printMatrix() {
			 for (int i = 0; i < N; i++){
				 for (int j = 0; j < M; j++){
					 cout << setw(5) << matrix[i][j];
				 }
				 cout << endl;
			 }
		 }
public:  void getItem() {
	int i;
	int j;
	cout << "i = ";
	cin >> i;
	cout << "j = ";
	cin >> j;
	if(i >= N || j >= M)
		cout << "ERROR INPUT" << endl;
	else
		cout << "matrix[" <<i << "][" << j << "] = " << matrix[i][j] << endl;
		 }
public:  void setItem() {
	int i;
	int j;
	cout << "i = ";
	cin >> i;
	cout << "j = ";
	cin >> j;
	if (i >= N || j >= M)
		cout << "ERROR INPUT" << endl;
	else
		cout << "matrix[" << i << "][" << j << "] = ";
	cin >> matrix[i][j];
		 }
public:  void addRow(int i=1) {
	int k;
	int** poss;
	cout << "The number of the added line = ";
	cin >> k;
	if (k > N) {
		cout << "ERROR INPUT" << endl;
	}
	else {
		poss = new int*[N + 1];
		poss[k] = new int[M];
		for (int i = 0; i < N; i++) {
			if (i >= k) {
				poss[i + 1] = matrix[i];
			}
			else {
				poss[i] = matrix[i];
			}
		}
		
		for (int j = 0; j < M; j++){
			cout << "matrix[" << k << "][" << j << "] = ";
			cin >> poss[k][j];
		}
		matrix = poss;
		N = N + 1;
	}
		 }
public:  void removeRow() {
	int k;
	int** poss;
	cout << "Number of line to be deleted = ";
	cin >> k;
	if (k >= N) {
		cout << "ERROR INPUT" << endl;
	}
	else {
		poss = new int*[N-1];
		for (int i = 0; i < N; i++) {
			if (i == k) continue;
			else if (i > k) {
				poss[i-1] = matrix[i];
			}
			else {
				poss[i] = matrix[i];
			}
			
		}
		matrix = poss;
		N = N - 1;
		}
}
};

char showMenu() {
	system("cls");
	char poss;
	cout << "Print matrix........................................[1];" << endl;
	cout << "Enter matrix........................................[2];" << endl;
	cout << "Fill in random number...............................[3];" << endl;
	cout << "Get element.........................................[4];" << endl;
	cout << "Set element.........................................[5];" << endl;
	cout << "Size of matrix......................................[6];" << endl;
	cout << "Add row.............................................[7];" << endl;
	cout << "Delete row..........................................[8];" << endl;;
	cin >> poss;
	return poss;
}

bool YesOrNo(char YN) {
	return YN == 'y';
}

void global(char YN, MyMatrix* matrix) {
	switch (YN){
	case '1': {
		matrix->printMatrix();
	}break;
	case '2': {
		matrix->userSet();
	}break;
	case '3': {
		matrix->randomSet();
	}break;
	case '4': {
		matrix->getItem();
	}break;
	case '5': {
		matrix->setItem();
	}break;
	case '6': {
		matrix->getSize();
	}break;
	case '7': {
		matrix->removeRow();
	}break;
	case '8': {
		matrix->addRow();
	}break;
	default:
		cout << "ERROR INPUT" << endl;
		break;
	}
}


int main(){
	setlocale(LC_ALL, "English");
	srand(time(NULL));
	char YN = 'n';
	int i; 
	int j;
	MyMatrix* matrix;

	cout << "Enter size of matrix [N * M]!" << endl;
	cout << "N = ";
	cin >> i;
	cout << "M = ";
	cin >> j;
	matrix = new MyMatrix(i, j);
	matrix->randomSet();

	do{

		global(showMenu(), matrix);

		cout << "Do you want to continue? [ yes(y) | no(n) ] : ";
		cin >> YN;
	} while (YesOrNo(YN));

	system("pause");

	return 0;
}
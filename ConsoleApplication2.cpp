#include <iostream>
#include <Eigen/Dense>
using namespace std;
int main() {
	int N_X;
	cout << "미지수의 개수 : ";
	cin >> N_X;
	float** A, ** Y, ** X;
	A = new float* [N_X];
	for (int n = 0; n < N_X; n++) {
		A[n] = new float[N_X];
	}
	Y = new float* [1];
	Y[0] = new float[N_X];
	X = new float* [1];
	X[0] = new float[N_X];
	cout << "식의 계수를 차례대로 입력하세요 : " << endl;
	for (int i = 0; i < N_X; i++) {
		for (int j = 0; j < N_X; j++) {
			cin >> A[i][j];
		}
	}
	cout << "Y(등호 오른쪽)를 차례대로 입력하세요 : " << endl;
	for (int j = 0; j < N_X; j++) {
		cin >> Y[0][j];
	}
	//역행렬계산
	float** C = new float* [N_X];
	for (int i = 0; i < N_X; i++) {
		C[i] = new float[N_X];
	}
	Eigen::MatrixXf A(N_X, N_X);
	// 역행렬 C 계산
	Eigen::MatrixXf C;
	if (A.determinant() != 0) {
		C = A.inverse();
		std::cout << "역행렬 C:" << std::endl << C << std::endl;
	}
	else {
		std::cout << "역행렬이 존재하지 않습니다." << std::endl;
	}
	//2D array
	for (int n = 0; n < N_X; n++) {
		for (int m = 0; m < N_X; m++) {
			X[n][m] = 0;
			for (int k = 0; k < N_X; k++) {
				X[n][m] += C[n][k] * Y[k][m];
			}
		}
	}
	//show X matrix
	for (int i = 0; i < N_X; i++) {
		for (int j = 0; j < N_X; j++) {
			cout << X[i][j] << "  ";
		}
		cout << endl;
	}

}

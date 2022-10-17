#include <iostream>
#include <string>
using namespace std;

//размер матрицы
const int n = 3;
const int m = 4;

//объявление квадратной матрицы 3x4 и заполнение нулями:
int matrix[n][m] = {};

//создание промежуточной матрицы для вычисления всех определителей:
int temp_matrix[n][n];

//ввод данных в матрицу 3x4
void entering_coef() {
	cout << "_x1 + _x2 + _x3 = _\n_x1 + _x2 + _x3 = _\n_x1 + _x2 + _x3 = _\n";
	char answer = ' ';
	while (answer != 'y')
	{
		cout << "Введите коэфициенты при неизвестных и свободные члены: \n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> matrix[i][j];
			}
		}
		cout << "Правильно ли введены данные?: y/n \n";
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << matrix[i][j] << " ";
			}
			cout << endl;
		}
		cin >> answer;

	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			temp_matrix[i][j] = matrix[i][j];
		}
	}
}

//нахождения определителя матрицы 3x3
int determinant(int matr[n][n]) {
	int det = matr[0][0] * matr[1][1] * matr[2][2] - matr[0][0] * matr[1][2] * matr[2][1]
		- matr[0][1] * matr[1][0] * matr[2][2] + matr[0][1] * matr[1][2] * matr[2][0]
		+ matr[0][2] * matr[1][0] * matr[2][1] - matr[0][2] * matr[1][1] * matr[2][0];
	return det;
}

//нахождение побочных определителей
int dets(int column) {
	//замена столбца
	for (int i = 0; i < n; ++i) {
		temp_matrix[i][column - 1] = matrix[i][m - 1];
	}
	//находим определитель с замененным столбцом
	int det = determinant(temp_matrix);
	//обратная замена
	for (int i = 0; i < n; ++i) {
		temp_matrix[i][column - 1] = matrix[i][column - 1];
	}
	return det;

}

int main() {
	//для установки русского языка в выводе:
	setlocale(LC_ALL, "Russian");

	//Ввод данных
	entering_coef();
	cout << "---------------------------------------------" << endl;

	//главный детерминант матрицы
	int det_main = determinant(temp_matrix);
	cout << "Гл опр: " << det_main << endl;

	//проверка совместности матрицы
	if (det_main == 0) {
		cout << "Не единственное решение или нет решений.";
	}
	else {
		cout << "det_main != 0 => Система имеет единственное решение" << endl;

		//нахождение побочных определитель
		int det1, det2, det3;
		det1 = dets(1);
		det2 = dets(2);
		det3 = dets(3);
		cout << "Побочные опр: " << det1 << " " << det2 << " " << det3 << endl;

		//корни СЛАУ
		int x1, x2, x3;
		x1 = det1 / det_main;
		x2 = det2 / det_main;
		x3 = det3 / det_main;
		cout << "Корни СЛАУ: " << x1 << " " << x2 << " " << x3 << endl;
	}
	return 0;
}

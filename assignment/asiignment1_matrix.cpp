// 2차 배열 사용 금지, such as int a[2][3]; 
#include <iostream> 

#include <stdlib.h> 
using namespace std;

// implement the functions : add, sub, mult, transpose 
class Matrix {
public:
	Matrix(int row, int col);
	int GetData();
	Matrix Transpose();
	int Display();
	Matrix Multiply(Matrix b);
	Matrix Add(Matrix b);
	Matrix Sub(Matrix b);
	Matrix Multiply2(Matrix b);
	int CompareRowCol(Matrix b);
	friend ostream& operator<<(ostream& os, Matrix& m);
private:
	int rows, cols;
	int* Term;
};

ostream& operator<<(ostream& os, Matrix& m)
{
	m.Display();
	return os;
}

Matrix::Matrix(int row, int col) : rows(row), cols(col)
{
	Term = new int[rows * cols]{0, };			//1차원배열은 가능하니까 한 뭉태기로 한다
}

int Matrix::GetData() {
	int input_value;
	cout << "rows = " << rows << " cols = " << cols << endl;
	for (int j = 0; j < rows * cols; j++)
	{
		cout << "term value = ";
		cin >> input_value;
		cout << " " << endl;
		Term[j] = input_value;
	}
	return 0;
}

Matrix Matrix::Transpose() {		//전치행렬
	Matrix b(cols, rows);

	int n = rows * cols;
	for (int i = 0; i < cols; i++)
	{
		//To be implemented 
		for (int j = 0;j < rows;j++)
			b.Term[i * rows + j] = Term[j * cols + i];
	}
	cout << endl;
	return b;
}

Matrix Matrix::Multiply(Matrix b) {
	if (cols != b.rows) cout << "Incompatible matrices" << endl;
	Matrix d(rows, b.cols);
	for (int i = 0; i < rows; i++)

	{
		for (int j = 0; j < b.cols; j++)
		{
			//To be implemented 
			for (int k = 0;k < cols;k++)
				d.Term[i * b.cols + j] += Term[i * cols + k] * b.Term[k * b.cols + j];
		}
	}
	return d;
}
Matrix Matrix::Add(Matrix b) {
	if (cols != b.cols) cout << "Incompatible matrices" << endl;
	if (rows != b.rows) cout << "Incompatible matrices" << endl;

	Matrix d(rows, cols);
	for (int i = 0; i < rows; i++)

	{
		//To be implemented 
		for (int j = 0;j < cols;j++)
			d.Term[i * cols + j] = Term[i * cols + j] + b.Term[i * cols + j];
	}
	return d;
}
Matrix Matrix::Sub(Matrix b) {
	if (cols != b.cols) cout << "Incompatible matrices" << endl;				//발생
	if (rows != b.rows) cout << "Incompatible matrices" << endl;

	Matrix d(rows, cols);
	for (int i = 0; i < rows; i++)

	{
		for (int j = 0; j < cols; j++)
		{
			//To be implemented 
			for (int j = 0;j < cols;j++)
				d.Term[i * cols + j] = Term[i * cols + j] - b.Term[i * cols + j];
		}
	}
	return d;
}
Matrix Matrix::Multiply2(Matrix b) {								//지금 들어간 b는 transpose된 t라는걸 생각하자
	if (cols != b.rows) cout << "Incompatible matrices" << endl;			
	Matrix bXpose = b.Transpose();
	Matrix d(rows, bXpose.cols);				
	// Must be implemented by using bXpose 
	for (int i = 0; i < rows; i++)

	{
		for (int j = 0; j < bXpose.cols; j++)
		{
			//To be implemented 
			for (int k = 0;k < cols;k++)
				d.Term[i * bXpose.cols + j] += Term[i * cols + k] * bXpose.Term[k * bXpose.cols + j];
		}
	}
	return d;
}
int Matrix::CompareRowCol(Matrix b) {
	if (cols != b.rows) return 1;
	else return 0;
}
int Matrix::Display() {

	int n;
	n = rows * cols;
	for (int i = 0; i < rows; i++)
	{
		//To be implemented 
		for (int j = 0;j < cols;j++)
			printf("%d ", Term[i * cols + j]);
		printf("\n");

	}
	cout << endl;
	return 0;
}

int main()
{
	Matrix a(2, 3);
	Matrix b(3, 4);
	Matrix c(2, 4);
	Matrix d(2, 4);
	Matrix t(4, 3);
	cout << "Enter first matrix: " << endl;
	a.GetData();
	cout << "Enter second matrix: " << endl;
	b.GetData();
	cout << "Display first matrix: " << endl;
	a.Display();
	cout << "Display second matrix : " << endl;
	b.Display();
	t = b.Transpose();
	cout << "Transpose() of Matrix b" << endl;
	t.Display();

	/* If colum of first matrix in not equal to row of second matrix, asking user to enter the size of matrix
   again. */
	if (a.CompareRowCol(b))
	{
		cout << "Error! column of first matrix not equal to row of second.";
		cout << "Enter rows and columns for first matrix: ";
	}
	c = a.Multiply(b); //not using transpose()
	cout << "Multiply of Matrix a,b" << endl;
	cout << c;				//ostream 써야할듯
	d = c.Sub(d);
	cout << d;
	cout << "using transpose()" << endl;
	t = b.Transpose();
	c = a.Multiply2(t);//using transpose() 
	cout << c;
	system("pause");
	return 0;
}
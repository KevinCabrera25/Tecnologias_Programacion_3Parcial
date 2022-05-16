// Sudoko_Backtracking.cpp 
// Kevin Cabrera

#include <iostream>
using namespace std;

// N es el tamanio de la matriz N*N
#define N 9

// Funcion para imprimir las cuadriculas
void print(int arr[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}
}

// Checa si sera legal asignar num a las filas y columnas 
bool isSafe(int grid[N][N], int row,
	int col, int num)
{

	// Checa si se encuentra el mismo num en la fila similar 
	for (int x = 0; x <= 8; x++)
		if (grid[row][x] == num)
			return false;

	// Checa si se encuentra el mismo num en la columna similar
	for (int x = 0; x <= 8; x++)
		if (grid[x][col] == num)
			return false;

	// Checa si se encuentra el mismo num en la matriz 3*3 
	int startRow = row - row % 3,
		startCol = col - col % 3;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (grid[i + startRow][j +
				startCol] == num)
				return false;

	return true;
}

/* Toma una cuadricula parcialmente llena e intenta asignar valores a las locaciones
desasignadas de tal manera que se cumplan los requerimientos de solucion del Sudoku */
bool solveSudoku(int grid[N][N], int row, int col)
{
	// Checa si se alcanzo la fila 8 y la columna 9 
	// Se trata de evitar mas backtracking
	if (row == N - 1 && col == N)
		return true;

	// Checa si el valor de la columna se vuelve 9 if column value becomes 9
	// Se mueve a la siguiente fila y columna empezando desde 0
	if (col == N) {
		row++;
		col = 0;
	}

	// Checa si la actual posicion de la cuadricula ya contiene algun valor mayor que 0 
	// Se itera a la siguiente columna
	if (grid[row][col] > 0)
		return solveSudoku(grid, row, col + 1);

	for (int num = 1; num <= N; num++)
	{

		// Checa si es seguro colocar un numero del 1-9 in una columna fila dada if it is safe to place
		// Se mueve a la siguiente columna
		if (isSafe(grid, row, col, num))
		{

			/* Asignacion de num en la actual posicion de columna fila de la cuadricula
			   y asume el num asignado en la posicion es correcta */
			grid[row][col] = num;

			// Checa las posibilidades de la siguiente columna 
			if (solveSudoku(grid, row, col + 1))
				return true;
		}

		// Se remueve el num asignado si la suposicion era incorrecta y se asume a la siguiente 
		// con un diferente valor en num
		grid[row][col] = 0;
	}
	return false;
}

int main()
{
	// 0 significa celdas sin asignar
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 },
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 },
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 },
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 },
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 },
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 },
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 },
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };

	if (solveSudoku(grid, 0, 0))
		print(grid);
	else
		cout << "no solution exists " << endl;

	return 0;
}

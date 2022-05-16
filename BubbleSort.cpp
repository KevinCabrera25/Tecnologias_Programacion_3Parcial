// BubbleSort.cpp 
// Kevin Cabrera

#include <iostream>
using namespace std;

// Metodo de la Burbuja
void bubbleSort(int listNum[], int size)
{
    // Ciclo para acceder a cada elemento del arreglo
    for (int i = 0; i < size - 1; i++)
    {
        // Comparacion de elementos del arreglo 
        for (int j = 0; j < size - i - 1; j++)
        {
            // Comparacion de elementos adyacentes(numeros pegados)
            // Cambia elementos mayores por menores, ordenando el arreglo de menor a mayor
            if (listNum[j] > listNum[j + 1])
            {
                // Si el elemento analizado es mayor entonces cambia de posicion con el adyacente
                swap(listNum[j], listNum[j + 1]);
            }
        }
    }

}

// Metodo de Impresion de la Burbuja
void printBubbleSort(int listNum[], int size)
{
    // Ciclo para imprimir cada elemento del arreglo en cada iteracion 
    for (int i = 0; i < size; i++)
    {
        cout << " " << listNum[i];
    }
    cout << "\n";
}


int main()
{
    // Se define el tamanio del arreglo para que el usuario lo llene
    int listNum[10];
    int size = sizeof(listNum) / sizeof(listNum[0]);

    cout << "Ingresa elementos de un arreglo de 10 en desorden. " << endl;
    // Ciclo para introducir los valores del arreglo 
    for (int i = 0; i < size; i++)
    {
        cin >> listNum[i];
    }

    // Prototipo de la funcion bubbleSort en donde se llenan las variables con los datos introducidos
    bubbleSort(listNum, size);

    cout << "Arreglo ordenado de menor a mayor con el metodo de Bubble Sort: " << endl;
    // Prototipo de la funcion printbubbleSort en donde se llenan las variables con los datos introducidos
    printBubbleSort(listNum, size);
}

// Menu_Ordenamiento.cpp 
// Kevin Cabrera

#include <iostream>
using namespace std;

// Metodo de la Burbuja
void bubbleSort(int listNum[], int size)
{
    // Ciclo para acceder a cada elemento del arreglo
    for (int i = 0; i < size -1; i++)
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

// Metodo de Insercion
void insertionSort(int listNum[], int size)
{
    int i, j, unsortedElement;
    // Accedemos a todos los elementos del arreglo
    for (i = 1; i < size; i++)
    {
        // Seleccionamos al primer elemento en desorden
        unsortedElement = listNum[i];
        j = i - 1;

        // Ciclo para mover los elementos del arreglo que son mayores al elemento desordenado
        // una posicion a la derecha de su posicion actual para insertar el elemento en orden
        while (j >= 0 && listNum[j] > unsortedElement)
        {
            listNum[j + 1] = listNum[j];
            j = j - 1;
        }
        // Se prosigue a analizar al siguiente elemento del arreglo
        listNum[j + 1] = unsortedElement;
    }
}

// Metodo de Impresion de Insercion
void printInsertionSort(int listNum[], int size)
{
    // Ciclo para imprimir cada elemento del arreglo en cada iteracion 
    for (int i = 0; i < size; i++)
    {
        cout << " " << listNum[i];
    }    
    cout << "\n";
}

// Quick Sort
// Metodo para cambiar de posicion dos elementos
void swap(int* a, int* b)
{
    // Variable temporal para almacenar el puntero a y cambiarlo por b
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Metodo de separacion del arreglo
int partition(int listNum[], int small, int big)
{
    // Creacion del pivote, se toma al ultimo elemento del arreglo como pivote
    int pivot = listNum[big];
    // Indice del elemento mas chico, indica la posicion a la derecha del pivote
    int i = (small - 1);

    // Colocacion de los elementos mas chicos que el pivote a la izquierda de este
    for (int j = small; j <= big - 1; j++)
    {
        // Si el elemento actual es mas chico que el pivote
        if (listNum[j] < pivot)
        {
            // Incrementa el indice del elemento mas chico
            i++;
            // Cambio de posicion de los elementos
            swap(&listNum[i], &listNum[j]);
        }
    }
    // Cambio de pivote  
    swap(&listNum[i + 1], &listNum[big]);
    return(i + 1);
}

// Metodo principal Quick Sort
void quickSort(int listNum[], int small, int big)
{
    if (small < big)
    {
        // Colocacion de los elementos mas grandes que el pivote a la derecha
        int partion_index = partition(listNum, small, big);

        // Ordenamiento de los elementos antes de la particion
        quickSort(listNum, small, partion_index - 1);
        // Ordenamiento de los elementos despues de la particion
        quickSort(listNum, partion_index + 1, big);
    }
}

// Metodo de Impresion de Quick Sort
void printQuickSort(int listNum[], int size)
{
    // Ciclo para imprimir cada elemento del arreglo en cada iteracion 
    for (int i = 0; i < size; i++)
    {
        cout << " " << listNum[i];
    }
    cout << "\n";
}

// Merge Sort
// Metodo subArrays que divide el arreglo principal en 2 para el Merge Sort
void subArrays(int listNum[], int const left, int const center, int const right)
{
    // Subarreglos
    auto const firstArray = center - left + 1;
    auto const secondArray = right - center;

    // Creacion de arreglos temporales
    auto *leftArray = new int[firstArray], *rightArray = new int[secondArray];

    // Ciclos para acceder y copiar los datos a los arreglos temporales 
    for (auto i = 0; i < firstArray; i++)
    {
        // Se acceden a los elementos del arreglo original y se le asignan al arreglo de la izquierda
        leftArray[i] = listNum[left + 1];
    }
    for (auto j = 0; j < secondArray; j++)
    {
        // Se acceden a los elementos del arreglo original y se le asignan al arreglo de la derecha a partir del elemento de la mitad de la 
        rightArray[j] = listNum[center + 1 + j];
    }

    // Indice inicial del primer arreglo
    // Indice inicial del segundo arreglo 
    auto indexFirstArray = 0, indexSecondArray = 0;
    // Indice inicial del arreglo combinado (merge)
    int indexMergedArray = left;

    // Combinamos los arreglos temporales 
    // Mientras el indice inicial del primer arreglo sea menor que el elemento del primer arreglo
    // y el indice inicial del segundo arreglo sea menor que el elemento del segundo arreglo
    while (indexFirstArray < firstArray && indexSecondArray < secondArray)
    {
        // Si el elemento del indice inicial del arreglo de la izquierda sea menor que el elemento 
        // del indice inicial del arreglo de la derecha
        if (leftArray[indexFirstArray] <= rightArray[indexSecondArray])
        {
            // Entonces se le asigna el indice inicial del arreglo combinado del arreglo original
            // al elemento indice inicial del primer arreglo del arreglo de la izquierda
            listNum[indexMergedArray] = leftArray[indexFirstArray];
            // Aumenta la posicion del indice inicial del primer arreglo en 1
            indexFirstArray++;
        }
        // De lo contrario
        else
        {
            // Se le asigna al indice inicial del arreglo combinado del arreglo original
            // al indice inicial del segundo arreglo del arreglo de la derecha
            listNum[indexMergedArray] = rightArray[indexSecondArray];
            // Aumenta la posicion del indice inicial del segundo arreglo en 1
            indexSecondArray++;
        }
        // Aumenta la posicion del indice inicial del arreglo merged
        indexMergedArray++;
    }

    // Ciclo para copiar los elementos faltantes del arreglo de la izquierda al arreglo principal
    while (indexFirstArray < firstArray)
    {
        // Asignacion de elementos del arreglo de la izquierda al arreglo merged
        listNum[indexMergedArray] = leftArray[indexFirstArray];
        // Se aumentan los indices iniciales en 1
        indexFirstArray++;
        indexMergedArray++;
    }

    // Ciclo para copiar los elementos faltantes del arreglo de la derecha al arreglo principal
    while (indexSecondArray < secondArray)
    {
        // Asignacion de elementos del arreglo de la derecha al arreglo merged
        listNum[indexMergedArray] = rightArray[indexSecondArray];
        // Se aumentan los indices iniciales en 1
        indexSecondArray++;
        indexMergedArray++;
    }
}

// Metodo Principal Merge Sort
void mergeSort(int listNum[], int const first, int const last)
{
    // first es el indice del arreglo de la izquierda 
    // last es el indice del arreglo de la derecha de los subarreglos creados en el metodo el metodo subArrays
    if (first >= last)
    
        return;
    

        // Se determina el centro del arreglo para crear los subarreglos
        auto center = first + (last - first) / 2;
        // Se mandan las variables a su respectivo metodo
        // Recursividad del método mergeSort
        mergeSort(listNum, first, center);
        mergeSort(listNum, center + 1, last);
        subArrays(listNum, first, center, last);

}

// Metodo de Impresion Merge Sort
void printMergeSort(int mergeSort[], int size)
{
    // Ciclo para imprimir cada elemento del arreglo en cada iteracion 
    for (auto i = 0; i < size-1; i++)
    {
        cout << " " << mergeSort[i];
    }
    cout << "\n";

}

// Heap Sort
// Metodo heapify para convertir el arbol binario en una estructura Heap
void heapify(int listNum[], int size, int i) // i es un indice del arreglo listNum[]
{
    // Se inicializa el indice como el mas grande, ademas de ser la raiz del arbol binario
    int biggest = i;
    // Calculo de nodos Hijos
    // Hijo Izquierdo
    int left = 2 * i + 1;
    // Hijo Derecho
    int right = 2 * i + 2;

    // Si el hijo de la izquierda es mayor que la raiz del arbol
    if (left < size && listNum[left] > listNum[biggest])
    {
        // Entonces se le asignara a la izquierda
        biggest = left;
    }

    // Si el hijo de la derecha es mayor que lo que llevamos por el momento
    if (right < size && listNum[right] > listNum[biggest])
    {
        // Entonces se asignara a la derecha
        biggest = right;
    }

    // Si el mayor numero no es la raiz
    if (biggest != i)
    {
        // Cambiara el indice por el mayor
        swap(listNum[i], listNum[biggest]);

        // Recursividad del metodo heapify para las ramas
        heapify(listNum, size, biggest);
    }
}

// Metodo principal heapSort
void heapSort(int listNum[], int size)
{
    // Construccion del monton o heap
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(listNum, size, i);
    }

    // Se van extrayendo elementos del monton o heap uno por uno
    for (int i = size - 1; i > 0; i--)
    {
        // Se mueve la raiz al final
        swap(listNum[0], listNum[i]);

        // Se llama al monton maximo en el monton reducido
        heapify(listNum, i, 0);
    }
}

void printHeapSort(int listNum[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << " " << listNum[i];
    }
    cout << "\n";
}

int main()
{
    int opcion;

    /*// Buscamos el tamanio del arreglo
           int size = sizeof(bubble) / sizeof(bubble[0]);
           */

    // Se define el tamanio del arreglo para que el usuario lo llene
    int listNum[10];
    int size = sizeof(listNum) / sizeof(listNum[0]);

    cout << "Ingresa elementos en desorden y posteriormente elige el metodo de ordenamiento." << endl;
    cout << "Ingresa elementos de un arreglo de 10: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> listNum[i];
    }

    // Estructura del Menu
    cout << "----------Metodos de Ordenamiento ----------" << endl;
    cout << "\n" << endl;
    cout << "Elige el metodo de ordenamiento: " << endl;
    cout << "\n" << endl;
    cout << "1. Bubble Sort" << endl;
    cout << "2. Insertion Sort" << endl;
    cout << "3. Quick Sort" << endl;
    cout << "4. Merge Sort" << endl;
    cout << "5. Heap Sort" << endl;
    cin >> opcion;
    cout << "\n" << endl;

    // Switch Case como estructura del Menu segun la opcion introducida por el usuario
    switch (opcion)
    {
        // Metodo de la Burbuja
        case 1:           
            // Prototipo de la funcion bubbleSort en donde se llenan las variables con los datos introducidos
            bubbleSort(listNum, size);

            cout << "Arreglo ordenado de menor a mayor: " << endl;
            // Prototipo de la funcion printbubbleSort en donde se llenan las variables con los datos introducidos
            printBubbleSort(listNum, size);
            break;

        // Metodo de Insercion
        case 2:
            // Prototipo de la funcion insertionSort en donde se llenan las variables con los datos introducidos
            insertionSort(listNum, size);

            cout << "Arreglo ordenado de menor a mayor: " << endl;
            // Prototipo de la funcion printInsertionSort en donde se llenan las variables con los datos introducidos
            printInsertionSort(listNum, size);
            break;

        // Metodo Quick Sort
        case 3:
            // Prototipo de la funcion quickSort en donde se llenan las variables con los datos introducidos
            quickSort(listNum, 0, size - 1);

            cout << "Arreglo ordenado de menor a mayor: " << endl;
            // Prototipo de la funcion printQuickSort en donde se llenan las variables con los datos introducidos
            printQuickSort(listNum, size);
            break;

        // Metodo Merge Sort
        case 4:
            // Prototipo de la funcion mergeSort en donde se llenan las variables con los datos introducidos
            mergeSort(listNum, 0, size - 1);

            cout << "Arreglo ordenado de menor a mayor: " << endl;
            // Prototipo de la funcion printMergeSort en donde se llenan las variables con los datos introducidos
            printMergeSort(listNum, size);
            break;

        case 5:
            // Prototipo de la funcion heapSort en donde se llenan las variables con los datos introducidos
            heapSort(listNum, size);

            cout << "Arreglo ordenado de menor a mayor: " << endl;
            // Prototipo de la funcion printHeapSort en donde se llenan las variables con los datos introducidos
            printHeapSort(listNum, size);
        break;
    }
}

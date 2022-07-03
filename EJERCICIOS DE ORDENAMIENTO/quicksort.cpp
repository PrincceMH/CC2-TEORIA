#include <iostream>

using namespace std;
template <class T>

void cambio(T *a, T *b)
{
    T temp = *a;
    *a = *b;
    *b = temp;
}

template <class T>

int mitad(T *arr, int Menor, int Mayor, bool (*p)(T,T))
{
    T pivot = arr[Mayor];
    int i = (Menor - 1);
    for (int j = Menor; j < Mayor; j++)
    {
        if (p(arr[j],pivot))
        {
            i++;
            cambio(&arr[i],&arr[j]);
        }
    }
    cambio(&arr[i + 1], &arr[Mayor]);
    return (i + 1);
}

template <class T>

void quickSort(T *arr, int x, int y,bool (*p)(T,T))
{
    if (x < y)
    {
        T pivot = mitad(arr,x,y,p);
        quickSort(arr,x,pivot - 1,p);
        quickSort(arr,pivot + 1,y,p);
    }
}

template <class T>

bool Mayor(T a, T b)//compara el mayor
{
    return a > b;
}
template <class T>

bool Menor(T a, T b)//compara el menor
{
    return a <= b;
}
template <class T>

void imprimirArr(T* arr, int x)//imprime el arreglo
{
    for (int i=0; i<x; i++)
    {
        cout<<*(arr+i)<<"\t";
    }
    cout<<endl;
}
int main(){
    cout<<"\t\t\tORDENAMIENTO QUICKSORT "<<endl;

    cout<<"\n\t\t---> Arreglo de Vocales <--- "<<endl;
    char arr3[5] = {'o','i','u','a','e'};
    cout<<"\n-- Arreglo -- "<<endl;
    imprimirArr(arr3,5);
    cout<<"\n -- Ordenado Ascendente --"<<endl;
    quickSort(arr3,0,4, Menor);
    imprimirArr(arr3,5);
    cout<<"\n -- Arreglo Ordenado Descentente -- "<<endl;
    quickSort(arr3,0,4, Mayor);
    imprimirArr(arr3,5);

    cout<<"\n\t\t---> Arreglo de Numeros Enteros <--- "<<endl;
    int arr[15] = {14,9,2,11,1,15,10,3,7,8,5,13,6,12,4};
    cout<<"\n\-- Arreglo -- "<<endl;
    imprimirArr(arr,15);
    cout<<"\n-- Ordenado Ascendente -- "<<endl;
    quickSort(arr,0,14, Menor);
    imprimirArr(arr,15);
    cout<<"\n-- Arreglo Ordenado Descentente -- "<<endl;
    quickSort(arr,0,14, Mayor);
    imprimirArr(arr,15);

    cout<<"\n\t\t---> Arreglo de Numeros Flotantes <--- "<<endl;
    float arr2[10] = {17.3,22.5,121.3,11.1,99.2,21.8,102.5,117.2,10.6,7.4};
    cout<<"\n-- Arreglo -- "<<endl;
    imprimirArr(arr2,10);
    cout<<"\n -- Ordenado Ascendente -- "<<endl;
    quickSort(arr2,0,9, Menor);
    imprimirArr(arr2,10);
    cout<<"\n -- Ordenado Descentente -- "<<endl;
    quickSort(arr2,0,9, Mayor);
    imprimirArr(arr2,12);


    return 0;
}

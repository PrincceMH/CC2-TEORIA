#include <iostream>

using namespace std;

template <class T>

void insertionsort(T* arr,int x, bool (*p)(T , T))
{
    for(int i=1; i<x; i++)
    {
        T temp = arr[i];
        int j = i-1;
        while(j>=0 && p(temp,arr[j]) )
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
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
    cout<<"\t\t\tORDENAMIENTO POR INSERCION "<<endl;

    cout<<"\n\t\t---> Arreglo de Vocales <--- "<<endl;
    char arr3[5] = {'o','i','u','a','e'};
    cout<<"\n-- Arreglo -- "<<endl;
    imprimirArr(arr3,5);
    cout<<"\n -- Ordenado Ascendente --"<<endl;
    insertionsort(arr3,5, Menor);
    imprimirArr(arr3,5);
    cout<<"\n -- Arreglo Ordenado Descentente -- "<<endl;
    insertionsort(arr3,5, Mayor);
    imprimirArr(arr3,5);

    cout<<"\n\t\t---> Arreglo de Numeros Enteros <--- "<<endl;
    int arr[15] = {14,9,2,11,1,15,10,3,7,8,5,13,6,12,4};
    cout<<"\n\-- Arreglo -- "<<endl;
    imprimirArr(arr,15);
    cout<<"\n-- Ordenado Ascendente -- "<<endl;
    insertionsort(arr,15, Menor);
    imprimirArr(arr,15);
    cout<<"\n-- Arreglo Ordenado Descentente -- "<<endl;
    insertionsort(arr,15, Mayor);
    imprimirArr(arr,15);

    cout<<"\n\t\t---> Arreglo de Numeros Flotantes <--- "<<endl;
    float arr2[10] = {17.3,22.5,121.3,11.1,99.2,21.8,102.5,117.2,10.6,7.4};
    cout<<"\n-- Arreglo -- "<<endl;
    imprimirArr(arr2,10);
    cout<<"\n -- Ordenado Ascendente -- "<<endl;
    insertionsort(arr2,10, Menor);
    imprimirArr(arr2,10);
    cout<<"\n -- Ordenado Descentente -- "<<endl;
    insertionsort(arr2,10, Mayor);
    imprimirArr(arr2,12);


    return 0;
}

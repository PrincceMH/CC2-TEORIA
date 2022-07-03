#include <iostream>

using namespace std;
template <class T>

void Div(T* arr, int Menor, int Mayor, int Medio, bool (*p)(T,T))
{
    int i =Menor,k = i;
    int j = Medio+1, a[1000];

    while (i <= Medio && j <= Mayor)
    {
        if (p(arr[i],arr[j]))
        {
            a[k] = arr[i];
            i++;
        }
        else
        {
            a[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= Medio)
    {
        a[k] = arr[i];
        k++;
        i++;
    }
    while (j <= Mayor)
    {
        a[k] = arr[j];
        k++;
        j++;
    }
    for (i = Menor; i < k; i++)
        arr[i] = a[i];
}

template<typename T>

void mergeSort(T *arr, int Menor, int Mayor, bool (*p)(T,T))
{
    T Medio;
    if (Menor < Mayor)
    {
        Medio=(Menor+Mayor)/2;
        mergeSort(arr,Menor,Medio,p);
        mergeSort(arr,Medio+1,Mayor,p);
        Div(arr,Menor,Mayor,Medio,p);
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
    cout<<"\t\t\tORDENAMIENTO MERGESORT "<<endl;

    cout<<"\n\t\t---> Arreglo de Vocales <--- "<<endl;
    char arr3[5] = {'o','i','u','a','e'};
    cout<<"\n-- Arreglo -- "<<endl;
    imprimirArr(arr3,5);
    cout<<"\n -- Ordenado Ascendente --"<<endl;
    mergeSort(arr3,0,5-1, Menor);
    imprimirArr(arr3,5);
    cout<<"\n -- Arreglo Ordenado Descentente -- "<<endl;
    mergeSort(arr3,0,5-1, Mayor);
    imprimirArr(arr3,5);

    cout<<"\n\t\t---> Arreglo de Numeros Enteros <--- "<<endl;
    int arr[15] = {14,9,2,11,1,15,10,3,7,8,5,13,6,12,4};
    cout<<"\n\-- Arreglo -- "<<endl;
    imprimirArr(arr,15);
    cout<<"\n-- Ordenado Ascendente -- "<<endl;
    mergeSort(arr,0,15-1, Menor);
    imprimirArr(arr,15);
    cout<<"\n-- Arreglo Ordenado Descentente -- "<<endl;
    mergeSort(arr,0,15-1, Mayor);
    imprimirArr(arr,15);

    cout<<"\n\t\t---> Arreglo de Numeros Flotantes <--- "<<endl;
    float arr2[10] = {17.3,22.5,121.3,11.1,99.2,21.8,102.5,117.2,10.6,7.4};
    cout<<"\n-- Arreglo -- "<<endl;
    imprimirArr(arr2,10);
    cout<<"\n -- Ordenado Ascendente -- "<<endl;
    mergeSort(arr2,0,10-1, Menor);
    imprimirArr(arr2,10);
    cout<<"\n -- Ordenado Descentente -- "<<endl;
    mergeSort(arr2,0,10-1, Mayor);
    imprimirArr(arr2,12);


    return 0;
}

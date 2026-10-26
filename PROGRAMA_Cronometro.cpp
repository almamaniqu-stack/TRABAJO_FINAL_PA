#include <iostream>
#include <ctime>
using namespace std;

int main() {
	int i,n,j,k,aux;
    clock_t t0 = clock();
    
    cin >> n; 
    double a[n];
    for(i = 0; i < n; i++){
    	cin >> a[i];
	}
    for (k = n / 2; k > 0; k /= 2){
        for (i = k; i < n; i++){
            aux = a[i];
            j = i;
            while (j - k >= 0 && a[j - k] > aux){
                a[j] = a[j - k];
                j -= k;
            }
            a[j] = aux;
        }
    }
    for(i = 0; i < n; i++){
    	cout << a[i] << " ";
	}
	cout << endl;

    clock_t t1 = clock();
    cout << "-----------------------------------------\n";
    clock_t t2 = clock();

    // Código a medir

    clock_t t3 = clock();
    
    double tiempo1 = double(t1 - t0) / CLOCKS_PER_SEC;
	double tiempo2 = double(t3 - t2) / CLOCKS_PER_SEC;
    cout << "Tiempo de ejecución de Shellsort: " << tiempo1 << " s" << endl;
    cout << "Tiempo de ejecución de Quicksort: " << tiempo2 << " s" << endl;
    return 0;
}



#include <iostream>
#include <ctime>
using namespace std;

int particionar(int izq, int der, int v[]) {
    int pvt = v[der];
    int i = izq - 1;
    int aux;

    for (int j = izq; j < der; j++) {
        if (v[j] <= pvt) {
            i++;
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
    }

    aux = v[i + 1];
    v[i + 1] = v[der];
    v[der] = aux;

    return i + 1;
}

void quicksort(int izq, int der, int v[]) {
    if (izq >= der) {
        return;
    }

    int pvt = particionar(izq, der, v);

    quicksort(izq, pvt - 1, v);
    quicksort(pvt + 1, der, v);
}

int main() {
	int i,n,j,k,aux;
    cin >> n;
    double a[n], b[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }

    clock_t t0 = clock();
    
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

	quicksort(0, n - 1, b);
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    clock_t t3 = clock();
    cout << "-----------------------------------------\n";
    
    double tiempo1 = double(t1 - t0) / CLOCKS_PER_SEC;
	double tiempo2 = double(t3 - t2) / CLOCKS_PER_SEC;
	double tiempopromedio = (tiempo1 + tiempo2) / 2;
    cout << "Tiempo de ejecución de Shellsort: " << tiempo1 << " s" << endl;
    cout << "Tiempo de ejecución de Quicksort: " << tiempo2 << " s" << endl;
    cout << "Tiempo de ejecución del testeo: " << tiempopromedio << " s" << endl;
    return 0;
}



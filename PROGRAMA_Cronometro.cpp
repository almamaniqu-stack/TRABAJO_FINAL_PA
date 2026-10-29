#include <iostream>
#include <chrono>
#include <iomanip>
using namespace std;

int particionar(int izq, int der, double v[]) {
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

void quicksort(int izq, int der, double v[]) {
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

    auto inicioShell = chrono::steady_clock::now();
    
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

    auto finShell = chrono::steady_clock::now();
    cout << "-----------------------------------------\n";
    double tiempoShell = chrono::duration<double>(finShell - inicioShell).count();
    
    auto inicioQuick = chrono::steady_clock::now();

	quicksort(0, n - 1, b);
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;

    auto finQuick = chrono::steady_clock::now();
    cout << "-----------------------------------------\n";
    double tiempoQuick = chrono::duration<double>(finQuick - inicioQuick).count();
    
	double tiempopromedio = (tiempoQuick + tiempoShell) / 2.00;
	
	cout << fixed << setprecision(8);
    cout << "Tiempo de Ejecucion de Shellsort: " << tiempoShell << " s" << endl;
    cout << "Tiempo de Ejecucion de Quicksort: " << tiempoQuick << " s" << endl;
    cout << "Tiempo de Ejecucion del Testeo: " << tiempopromedio << " s" << endl;
    return 0;
}



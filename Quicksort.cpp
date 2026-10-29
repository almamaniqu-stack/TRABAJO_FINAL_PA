#include <iostream>
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
    double b[n];
    for (i = 0; i < n; i++) {
        cin >> b[i];
    }
    quicksort(0, n - 1, b);
    for (i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
}

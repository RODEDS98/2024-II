#include <iostream>
using namespace std;

int main() {
    int n;
    

    cout << "Ingrese la cantidad de elementos: ";
    cin >> n;

    int *p = new int[n];

    for (int i = 0; i < n; i++) {
        p[i] = i + 10;
    }
    
    for (int* i=p ; i<p+n ; i++) {
         cout<<*i<<endl;
    }
    
    for (int *pt = p; pt < p + n; pt++) {
        cout << *pt << " ";
    }

    delete[] p;

    return 0;
}

#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void keyboard_enter(int M[4][5]) {
    int i, j;
    cout << "\nVvedite elementy massiva: \n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            cin >> M[i][j];
            if (!cin.good()) {
                cout << endl << "Vy vveli ne chislo." << endl;
                cin.clear();
                cin.ignore(255, '\n');
                break;
            }
        }
    }

    cout << "\nMassiv: \n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }

}

void file_enter(int M[4][5]) {
    int i, j;
    std::ifstream file("massiv1.txt");
    for (i = 0; i < 20; i++) {
        for (j = 0; j < 5; j++) {
            file >> M[i][j];
        }
    }

    cout << "\nMassiv: \n";
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            cout << M[i][j] << "  ";
        }
        cout << endl;
    }

}

void srednee(int M[4][5]) {
    int i, a, a1, sum, sredn;
    sum = 0;
    sredn = 0;
    cout << "\nVyberite stolbets: \n";
    cin>>a;
    a1 = a - 1;

    for (i = 0; i < 4; i++) {
        sum += M[i][a1];
    }
    sredn = (sum) / 4;
    cout << "\nSredn: " << sredn;

    FILE *f2;
    f2 = fopen("sredn.txt", "w");
    fprintf(f2, "\n %d %d", sredn, a);
    fclose(f2);
}

void save(int M[4][5]) {
    int sredn, a;
    FILE *f1;
    f1 = fopen("massiv2.txt", "w");

    for (int l = 0; l < 4; l++) {
        for (int k = 0; k < 5; k++) {
            fprintf(f1, "  %d", M[l][k]);
        }
        fprintf(f1, "\r\n");
    }
    fclose(f1);
    cout << "\nDannye zapisany v fayl.";
}

int main(int argc, char** argv) {
    int sw, M[4][5];

    while (1) {
        printf("\n\n\nMENU:\n1) Vvesti massiv s klaviatury\n2) Chtenie massiva iz fayla\n3) Raschet srednego arifmeticheskogo\n4) Zapis v fayl\n5) Vyhod");
        cout << "\n\n\nVvedite comandu ";
        cin>>sw;

        switch (sw) {
            case 1:
                keyboard_enter(M);
                break;

            case 2:
                file_enter(M);
                break;



            case 3:
                srednee(M);
                break;

            case 4:
                save(M);
                break;

            default: return 0;
        }
    }
}

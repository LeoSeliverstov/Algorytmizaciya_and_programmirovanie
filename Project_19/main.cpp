#include <iostream>
#include <fstream>

using namespace std;

int main() {
    int i, j, sw, sw1, c1 = 1, a1, a2, starv, stari, starj, M[3][4];
    printf("\n\nMENU:\n1) Vvesti massiv s klaviatury\n2) Chtenie massiva iz faila\n\n");

    while (c1) {
        cout << "\nVvedite comandu: ";
        cin>>sw1;

        switch (sw1) {
            case 1:
            {
                cout << "\nVvedite elementy massiva: \n";

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        cin >> M[i][j];
                    }
                }

                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        printf("%2d ", M[i][j]);
                    }
                    cout << endl;
                }
                c1 = 0;
            }
                break;

            case 2:
            {
                std::ifstream file("massiv1.txt");
                for (i = 0; i < 15; i++) {
                    for (j = 0; j < 4; j++) {
                        file >> M[i][j];
                    }
                }

                cout << "\nMassiv: \n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        printf("%2d ", M[i][j]);
                    }
                    cout << endl;
                }
                c1 = 0;
            }
                break;

            default: printf("\nOshibka: nepravilny simvol.\n\n");
        }
    }

    printf("\n\n\nMENU:\n1) Izmenenie elementa massiva\n2) Zapis dannyh v fayl\n3) Vyhod iz programmy");

    while (1) {
        cout << "\n\n\nVvedite comandu: ";
        cin>>sw;

        switch (sw) {
            case 1:
            {
                cout << "\nVyberite stroku: \n";
                cin>>a1;

                cout << "\nVyberite stolbec: \n";
                cin>>a2;
                a1--;
                a2--;

                cout << "\nVvedite novoe znacenie elementa: \n";
                cin >> M[a1][a2];
                cout << "\nMassiv: \n";
                for (i = 0; i < 3; i++) {
                    for (j = 0; j < 4; j++) {
                        cout << M[i][j] << "  ";
                    }
                    cout << endl;
                }
            }
                break;

            case 2:
            {
                FILE *f1, *f2;
                f1 = fopen("massiv2.txt", "w");
                f2 = fopen("star.txt", "w");

                for (int l = 0; l < 4; l++) {
                    for (int k = 0; k < 5; k++) {
                        fprintf(f1, "  %d", M[l][k]);
                    }
                    fprintf(f1, "\r\n");
                }
                fprintf(f2, "\n %d %d %d", starv, stari, starj);
                fclose(f1);
                fclose(f2);
                cout << "\nProizvedena zapis v fayl.";
            }
                break;

            default: return 0;
        }
    }
}

#include <stdio.h>

int main() {
    int n;
    int nilai[50];
    int i, j, temp;
    int maks, min;
    int jumlah = 0;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Nilai mahasiswa %d: ", i+1);
        scanf("%d", &nilai[i]);
        if (nilai[i] < 0 || nilai[i] > 100) {
            printf("Nilai tidak valid. Masukkan nilai antara 0-100.\n");
            i--; 
        }
    }

    printf("\nNilai sebelum diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    maks = nilai[0];
    min = nilai[0];
    for (i = 0; i < n; i++) {
        if (nilai[i] > maks) maks = nilai[i];
        if (nilai[i] < min) min = nilai[i];
        jumlah += nilai[i];
    }

    printf("Nilai maksimum: %d\n", maks);
    printf("Nilai minimum: %d\n", min);
    printf("Rata rata tanpa drop: %.2f\n", (float)jumlah / n);

    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-1-i; j++) {
            if (nilai[j] < nilai[j+1]) {
                temp = nilai[j];
                nilai[j] = nilai[j+1];
                nilai[j+1] = temp;
            }
        }
    }

    printf("\nNilai setelah diurutkan:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", nilai[i]);
    }
    printf("\n");

    if (n > 1) {
        int jumlah2 = 0;
        for (i = 0; i < n-1; i++) {
            jumlah2 += nilai[i];
        }
        printf("Rata rata setelah drop 1 nilai: %.2f\n", (float)jumlah2 / (n-1));
    }

    return 0;
}


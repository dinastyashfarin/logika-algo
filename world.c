#include <stdio.h>

int main() {
    int m, h;
    int hadir[30][7];
    int i, j;

    printf("Masukkan jumlah mahasiswa: ");
    scanf("%d", &m);

    printf("Masukkan jumlah hari: ");
    scanf("%d", &h);

    for (i = 0; i < m; i++) {
        for (j = 0; j < h; j++) {
            printf("Mahasiswa %d Hari %d (1/0): ", i+1, j+1);
            scanf("%d", &hadir[i][j]);
        }
    }

    printf("\nRekap per mahasiswa:\n");
    int total = 0;
    for (i = 0; i < m; i++) {
        int sum = 0;
        for (j = 0; j < h; j++) {
            sum += hadir[i][j];
        }
        total += sum;
        printf("Mahasiswa %d: %d hadir dari %d\n", i+1, sum, h);
    }

    printf("\nRekap per hari:\n");
    for (j = 0; j < h; j++) {
        int hadir_hari = 0;
        for (i = 0; i < m; i++) {
            hadir_hari += hadir[i][j];
        }
        printf("Hari %d: %d mahasiswa hadir\n", j+1, hadir_hari);
    }

    float persen = (float)total / (m * h) * 100;
    printf("\nPersentasi rata rata kehadiran sekelas = %.2f%%\n", persen);

    return 0;
}

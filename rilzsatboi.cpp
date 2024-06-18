#include <stdio.h>

// Daftar sayuran dan harga per kilogramnya
char *sayuran[] = {
    "Bayam", "Kangkung", "Wortel", "Kentang", "Tomat", 
    "Cabai", "Bawang Merah", "Bawang Putih", "Brokoli", "Sawi"
};

int harga[] = {
    5000, 4000, 7000, 10000, 8000,
    20000, 15000, 18000, 12000, 6000
};

int main() {
    int menu, jumlah, total_harga = 0, uang_dibayar, kembalian;
    int total_item[10] = {0};  // Untuk menyimpan jumlah masing-masing item yang dibeli

    // Menampilkan pesan selamat datang
    printf("=====================================\n");
    printf("   Selamat Datang di Toko Sayuran!   \n");
    printf("=====================================\n");

    // Loop while untuk terus memproses transaksi
    while (1) {
        // Menampilkan menu
        printf("\nMenu Sayuran:\n");
        for (int i = 0; i < 10; i++) {
            printf("%d. %s - Harga: %d\n", i + 1, sayuran[i], harga[i]);
        }
        printf("0. Selesai\n");

        // Meminta input dari pengguna
        printf("Pilih menu: ");
        if (scanf("%d", &menu) != 1 || menu < 0 || menu > 10) {
            printf("Input tidak valid. Silakan masukkan nomor menu yang benar.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
            continue;
        }

        // Memeriksa apakah pengguna ingin keluar
        if (menu == 0) {
            break;
        }

        // Meminta input jumlah item yang ingin dibeli
        printf("Masukkan jumlah kilogram yang ingin dibeli: ");
        if (scanf("%d", &jumlah) != 1 || jumlah < 1) {
            printf("Input tidak valid. Silakan masukkan jumlah yang benar.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
            continue;
        }

        // Menambahkan total harga dan jumlah item yang dibeli
        total_harga += harga[menu - 1] * jumlah;
        total_item[menu - 1] += jumlah;
        printf("%s sebanyak %d kg telah ditambahkan ke keranjang belanja.\n", sayuran[menu - 1], jumlah);
    }

    // Menampilkan total harga
    printf("\n=====================================\n");
    printf("Detail belanjaan Anda:\n");
    for (int i = 0; i < 10; i++) {
        if (total_item[i] > 0) {
            printf("%s: %d kg x %d = %d\n", sayuran[i], total_item[i], harga[i], total_item[i] * harga[i]);
        }
    }
    printf("Total harga belanjaan Anda: %d\n", total_harga);

    // Meminta input jumlah uang yang dibayar
    while (1) {
        printf("Masukkan jumlah uang yang dibayar: ");
        if (scanf("%d", &uang_dibayar) != 1) {
            printf("Input tidak valid. Silakan masukkan jumlah uang yang benar.\n");
            while (getchar() != '\n'); // Membersihkan buffer input
            continue;
        }

        // Menghitung kembalian
        kembalian = uang_dibayar - total_harga;

        // Menampilkan kembalian atau pesan error jika uang kurang
        if (kembalian < 0) {
            printf("Uang yang dibayar kurang. Silakan coba lagi.\n");
        } else {
            break;
        }
    }

    if (kembalian == 0) {
        printf("Uang yang dibayar pas.\n");
    } else {
        printf("Kembalian: %d\n", kembalian);
    }

    // Menampilkan pesan terima kasih
    printf("=====================================\n");
    printf("    Terima kasih sudah membeli!      \n");
    printf("=====================================\n");

    return 0;
}

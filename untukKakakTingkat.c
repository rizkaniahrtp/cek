//library
#include <stdio.h> //standard input/output
#include <string.h> //untuk isi dari string
#include <time.h> //untuk memanipulasi waktu

//variabel
char passwordBenar[] = "promdasAsik"; //variabel untuk menyimpan password yang benar (sudah di setting password benarnya) 
char password[30]; //variabel untuk input password
int percobaan = 0; //variabel untuk melihat user melakukan percobaan menginput password berapa kali

//fungsi
void menunggu(int detik){ //fungsi menunggu
    time_t start = time(NULL); //waktu dimulai saat fungsi dipanggil (waktu sekarang)
    while(time(NULL) - start < detik); //while loop untuk menghitung berapa detik yang telah berlalu sejak fungsi dipanggil, menunggu selama selisih waktunya masih kurang dari jumlah waktu yang diminta
}

void passwordSalah(){ //fungsi passwordSalah
    while(strcmp(passwordBenar, password) != 0){ //mengulang jika passwordBenar dan password tidak memiliki isi string yang sama
        printf("That's not the right password :(\n"); //menampilkan teks, jika isi string tidak sama
        percobaan++; //manambahkan jumlah input password,setiap kali password salah

        if(percobaan == 5){ //jika jumlah password yang diinput salah sebanyak lima kali
            printf("Coba lagi dalam 30 detik...\n"); //menampilkan perintah untuk menungggu
            menunggu(30); //memanggil fungsi menunggu, untuk menghitung waktu/menjeda program selama 30 detik, sebelum menampilkan perintah kode program berikutnya 
        }
        else if(percobaan >= 10){ //jika jumlah password yang diinput salah sebanyak sepuluh kali
            printf("Anda di blokir\n"); //menampilkan teks bahwa user telah diblokir
            return; //untuk menghentikan fungsi, tanpa melanjutkan kode ke baris berikutnya.
        }
        printf("\nMasukkan Password Anda: "); //jika percobaan password yang diinput < 5, maka user diminta untuk menginput password lagi
        scanf("%s", &password); //untuk input password
    }
}

int main(){ //fungsi utama
    printf("\n=================================SELAMAT DATANG=================================\n"); //menampilkan teks selamat datang 
    printf("\nMasukkan Password Anda: "); //user diminta untuk menginput password (perintah menginput untuk pertama kali)
    scanf("%s", &password); //untuk input password
    passwordSalah(); //memanggil fungsi passwordSalah, jika string passwordBenar dan password tidak memiliki isi string yang sama 
    if(strcmp(passwordBenar, password) == 0){ //jika hasil dari membandingkan isi string passwordBenar dan password sama
        printf("OK :)\n"); //maka, menampilkan teks bahwa ia berhasil menginput password yang bemar dan sama dengan passwordBenar
    }

    return 0; //program telah selesai 
}

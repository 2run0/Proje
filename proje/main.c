#include <stdio.h>

int main() {
    FILE *file,*file2;
    char isim[50];
    int sicil_no,satis=0,max_satis=0;

    //yillik.dat dosyasi varsa aç
    file = fopen("yillik.dat","r");
    if (file == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }

    //"x, y z, k" yazı formatında olan verileri değişkenlere atıyoruz
    while (fscanf(file,"%d, %19[^,], %d\n",&sicil_no, isim, &satis) !=EOF) {
        if (satis>max_satis) {
            max_satis=satis; //Max satış miktarını buluyoruz
        }
    }
    //Dosyayı kapatıyoruz
    fclose(file);

    //satislar.dat adli dosyayı oluşturuyoruz
    file2 = fopen("satislar.dat","w");
    if (file2 == NULL) {
        printf("Dosya acilamadi!\n");
        return 1;
    }
    //Veri alacağımız için yillik.dat dosyasını okuma modunda açıyoruz
    file = fopen("yillik.dat", "r");
    if (file == NULL) {
        printf("Dosya açılamadı!\n");
        fclose(file);
        return 1;
    }
    //Yine "x, y z, k" yazı formatındaki verileri değişkenlere atıyoruz
    while (fscanf(file,"%d, %49[^,], %d",&sicil_no, isim, &satis) !=EOF) {
        int fark = max_satis-satis;
        //Yeni olusturacağımız dosyaya verileri yazdırıyoruz
        fprintf(file2,"%d, %s, %d\n", sicil_no,isim,fark);
    }
    //Dosyaları kapatıyoruz
    fclose(file);
    fclose(file2);

    return 0;
}
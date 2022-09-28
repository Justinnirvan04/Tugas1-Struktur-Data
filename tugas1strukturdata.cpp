//Justin Nirvantio
//A11.2021.13426
//43UG2
#include <iostream>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
using namespace std;

struct paket{
    char jenis_brg[30];
    int berat;
    char kota[30];
};
struct paket kirim[100];

void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}
void tambahdata(int x){
    int maxx;
    maxx= 21;
    if(x<maxx){
    cout<<endl<<"Data ke-: "<<x<<endl;
    gotoxy(10,15);cout<<"MASUKAN JENIS BARANG : ";
    cin>>kirim[x].jenis_brg;
    gotoxy(10,16);cout<<"MASUKAN BERAT BARANG : ";
    cin>>kirim[x].berat;
    gotoxy(10,17);cout<<"MASUKAN KOTA TUJUAN : ";
    cin>>kirim[x].kota;
    x=x+1;
    }
    else{
        cout<<"MAAF STACK PENUH!" << endl;
    }
}
void tampildata(int x){
    if(x>1){
    cout<<"CONTOH PUSH PADA STACK"<<endl;
    for(int i =1;i<x;i++){
        gotoxy(20,20-i);
        cout<<endl<<"Data ke-: "<<i<<endl;
        gotoxy(20,21-i);
        cout<<kirim[i].jenis_brg<<" ";
        cout<<kirim[i].berat<<" ";
        cout<<kirim[i].kota<<" ";
    }
    gotoxy(20,25);
    cout<<"Press Any Key...";
    getch();
    x=x-1;
    }else{
        cout<<" MAAF STACK KOSONG!!!"<<endl;
    }
}
void hapusdata(int x){
    gotoxy(40,12);cout<<"Data Yang berhasil ke POP adalah "<<endl;
    gotoxy(40,13);cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" ";
    cout<<kirim[x].kota<<" ";
    cout<<endl<<endl;
    gotoxy(40,20);cout<<"Press Any Key...";
    getch();

}

int main()
{
    int pilih;
    int datake=1;
    do{
        bersihlayar();
        gotoxy(1,0);cout<<"IMPLEMENTASI STACK"<<endl;
        gotoxy(1,1);cout<<"1. PUSH DATA"<<endl;
        gotoxy(1,2);cout<<"2. POP DATA"<<endl;
        gotoxy(1,3);cout<<"3. TAMPIL DATA"<<endl;
        gotoxy(1,4);cout<<"9. Keluar "<<endl;
        gotoxy(1,5);cout<<endl<<endl<< "Pilihan anda [1-9]: ";
        cin>>pilih;
        if(pilih==1){
            tambahdata(datake);
            datake++;
        }
        if(pilih==2){
            hapusdata(datake-1);
            datake--;
        }
        if(pilih==3){
            tampildata(datake);
        }
    }
    while(pilih!=9);
    return 0;
}

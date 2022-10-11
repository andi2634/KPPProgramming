// NAMA		: M. Andi Abdillah
// NRP		: 5022221073
// Jurusan	: Teknik Elektro

#include <iostream>
#include <cmath>

#define GRAVITASI 10 //10 m/s^2
#define START_PENGUKURAN 1 //pengukuran dimulai dari 1 meter
#define SUDUT 45 //sudut elevasi tembakan

int mencari_V0(int v1, int v2){
	/* Tulis fungsi mencari v0 kalian disini */
  	return v1-v2;
}

float speed_dgn_loss(float v){
	/* tulis fungsi hitung_loss kalian disini */
	int Vloss;
	if(v<=10){
		Vloss = 1;
	}
	if(v<=20){
		Vloss = 3;
	}
	if(v<=30){
		Vloss = 5;
	}
	return v+Vloss;
}
int input, jarak, V0;
float Vt;

int main() {
    /* tulis kode utama kalian disini */
  
  	/* input adalah kecepatan tangensial maksimum roller */
  	std::cin >> input;
  	if(input<START_PENGUKURAN){
  		input=START_PENGUKURAN;
	  }
	if(input>30){
		input=30;
	}
	if(input<=10){
		V0 = mencari_V0(input, 1);
	}
	if(input<=20){
		V0 = mencari_V0(input, 3);
	}
	if(input<=30){
		V0 = mencari_V0(input, 5);
	}
  	jarak = ((V0*V0)*sin(2*SUDUT*(3.142/180))/GRAVITASI);
  	Vt =  sqrt((GRAVITASI*jarak)/(sin(2*SUDUT*(3.142/180))));
  	Vt = speed_dgn_loss(Vt);
  	std::cout << jarak << " " << Vt << std::endl;
    return 0;
}

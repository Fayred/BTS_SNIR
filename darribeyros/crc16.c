#include <stdio.h>
#include <string.h>

int main(void){
	char chaine[]="IR";
	int crc16 = 0xFFFF;
	int tmp_crc16;
	int polynome = 0xA001;
	for(int a=0;a<strlen(chaine);a++){
		crc16 ^= chaine[a];
		printf("CRC16 XOR     : 0x%X\n", crc16);
		for(int b=1; b<=8; b++){
			tmp_crc16 = crc16;
			crc16 = crc16 >> 1;
			printf("CRC16 SHIFT %d : 0x%X\n", b, crc16);
			if((tmp_crc16 & 1) == 1){
				crc16 ^= polynome;
				printf("CRC16 XOR     : 0x%X\n", crc16);
			}
		}
	}
	printf("\nTRANSMITTED CRC16 FOR '%s' : 0x%X\n", chaine, crc16);
	return 0;
}
#include <8051.h>

void tput(unsigned char c1)
{
	SBUF = c1; 
	while(!TI); 
	TI = 0; 
}

void main()
{
	int i;
	unsigned char src[]={'H','e','l','l','o',' ','W','o','r','l','d'};

	PCON = 0x80;
	TMOD = 0x20;
	TR1 = 1;
	TH1 = -3;
	for(i=0; i<11; i++)
	{
		ACC = src[i]; 
		SCON = 0x50;
		tput (src[i]);
	}
while(1){} 
}
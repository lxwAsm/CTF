
#include <stdio.h>
#include <stdlib.h>

void display();
int	cnt(int c,int r);
int count(int cha, int seed);
int	cal(char c,int r);
int main(int argc, char* argv[])
{
	//printf("Hello World!\n");
	//display();
	int nums[] = 
		  {0x63B25AF1,0xC5659BA5,0x4C7A3C33,0x0E4E4267,0xB611769B,0x3DE6438C,
        0x84DBA61F,0x0A97497E6,0x650F0FB3,0x84EB507C,0x0D38CD24C,0x0E7B912E0,
        0x7976CD4F,0x84100010,0x7FD66745,0x711D4DBF,0x5402A7E5,0x0A3334351,
        0x1EE41BF8,0x22822EBE,0x0DF5CEE48,0x0A8180D59,0x1576DEDC,0x0F0D62B3B,
        0x32AC1F6E,0x9364A640,0x0C282DD35,0x14C5FC2E,0x0A765E438,0x7FCF345A,
        0x59032BAD,0x9A5600BE,0x5F472DC5,0x5DDE0D84,0x8DF94ED5,0x0BDF826A6,
        0x515A737A,0x4248589E,0x38A96C20,0x0CC7F61D9,0x2638C417,0x0D9BEB996
        };
	for(int i=100;i<10000;i++)
	{
		srand(0x31333359 ^ i);
		int tmp = rand();
		for(int j=32;j<=127;j++)
		{
			int r = cnt(j,tmp);
			if(r==0x63B25AF1)
			{
				printf("%c",j,i);
				goto next;
			}
		}
	}
next:
	for(i=1;i<42;i++)
	{
		int r=rand();
		for(int j=32;j<128;j++)
		{
			if(cnt(j,r)==nums[i])
				printf("%c",j);
		}
	}
	return 0;
}

int	cnt(int c,int r)
{
	int ret = 0;
	__asm{
		xor		eax,eax
		xor		ebx,ebx
		xor		ecx,ecx
		mov		eax,c
		mov		ecx,r
		mul     ecx
		mov     ecx, 0FAC96621h
		push    eax
		xor     edx, edx
		div     ecx
		pop     eax
		push    edx
		mul     eax
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		mul     edx
		div     ecx
		mov     eax, edx
		pop     edx
		mul     edx
		div     ecx
		mov		ret,edx
	}
	return ret;
}
int	cal(char c,int r)
{
	unsigned long  v6; // eax
	unsigned long  v7; // edx
	unsigned long  v8; // edx
	unsigned long  v9; // edx
	unsigned long  v10; // edx
	unsigned long  v11; // edx
	unsigned long  v12; // edx
	unsigned long  v13; // edx
	unsigned long  v14; // edx
	unsigned long  v15; // edx
	unsigned long  v16; // edx
	unsigned long  v17; // edx
	unsigned long  v18; // edx
	unsigned long  v19; // edx
	unsigned long  v20; // edx
	unsigned long  v21; // edx
	v6 = c * r;
    v7 = v6 * v6 % 0xFAC96621;
    v8 = v7 * v7 % 0xFAC96621;
    v9 = v8 * v8 % 0xFAC96621;
    v10 = v9 * v9 % 0xFAC96621;
    v11 = v10 * v10 % 0xFAC96621;
    v12 = v11 * v11 % 0xFAC96621;
    v13 = v12 * v12 % 0xFAC96621;
    v14 = v13 * v13 % 0xFAC96621;
    v15 = v14 * v14 % 0xFAC96621;
    v16 = v15 * v15 % 0xFAC96621;
    v17 = v16 * v16 % 0xFAC96621;
    v18 = v17 * v17 % 0xFAC96621;
    v19 = v18 * v18 % 0xFAC96621;
    v20 = v19 * v19 % 0xFAC96621;
    v21 = v20 * v20 % 0xFAC96621;
    return v6 % 0xFAC96621 * v21 % 0xFAC96621;
}
/* 
int count(int cha, int seed){
	int re = 0;
	_asm{
		pusha
		xor eax,eax
		xor ecx,ecx
		xor edx,edx
		mov eax,seed
		mov		ecx, cha
		mul     ecx
		mov     ecx, 0FAC96621h
		push    eax
      xor     edx, edx
         div     ecx
            pop     eax
          push    edx
            mul     eax
            div     ecx
             mov     eax, edx
             mul     edx
             div     ecx
          mov     eax, edx
            mul     edx
            div     ecx
            mov     eax, edx
           mul     edx
             div     ecx
           mov     eax, edx
             mul     edx
             div     ecx
             mov     eax, edx
       mul     edx
         div     ecx
           mov     eax, edx
            mul     edx
            div     ecx
            mov     eax, edx
           mul     edx
           div     ecx
           mov     eax, edx
             mul     edx
              div     ecx
               mov     eax, edx
             mul     edx
               div     ecx
               mov     eax, edx
              mul     edx
              div     ecx
               mov     eax, edx
               mul     edx
             div     ecx
                mov     eax, edx
               mul     edx
               div     ecx
               mov     eax, edx
              mul     edx
              div     ecx
              mov     eax, edx
              mul     edx
             div     ecx
     mov     eax, edx
 mul     edx
 div     ecx
mov     eax, edx
pop     edx
mul     edx
div     ecx
mov     re,edx
popa
	}
	return re;
}
*/ /* 
void display(){
	int nums[] = 
		  {0x63B25AF1,0xC5659BA5,0x4C7A3C33,0x0E4E4267,0xB611769B,0x3DE6438C,
        0x84DBA61F,0x0A97497E6,0x650F0FB3,0x84EB507C,0x0D38CD24C,0x0E7B912E0,
        0x7976CD4F,0x84100010,0x7FD66745,0x711D4DBF,0x5402A7E5,0x0A3334351,
        0x1EE41BF8,0x22822EBE,0x0DF5CEE48,0x0A8180D59,0x1576DEDC,0x0F0D62B3B,
        0x32AC1F6E,0x9364A640,0x0C282DD35,0x14C5FC2E,0x0A765E438,0x7FCF345A,
        0x59032BAD,0x9A5600BE,0x5F472DC5,0x5DDE0D84,0x8DF94ED5,0x0BDF826A6,
        0x515A737A,0x4248589E,0x38A96C20,0x0CC7F61D9,0x2638C417,0x0D9BEB996
        };
	int tmp = 0;
	int co = 0;
	int seed = 0;

	for(int i = 1344 ; i < 5293 ; i++){
		srand(0x31333359 ^ i);
			tmp = rand();
	
	  for(int j = 32 ; j < 127; j++){
				co = count(j,tmp);
				if(co == nums[0]){
					printf("srand seed ::   %x\n",i);
					seed = i;
					break;
				}
			}
	  if(seed) break;
		}


		srand(0x31333359 ^ seed);
	
		for(i = 0; i < 42; i++){
			tmp = rand();
	
	  for(int j = 32 ; j < 127; j++){
				co = count(j,tmp);
				if(co == nums[i]){
					printf("%c",j);
				}
			}
		}
		printf("\n");
    
}
*/ 



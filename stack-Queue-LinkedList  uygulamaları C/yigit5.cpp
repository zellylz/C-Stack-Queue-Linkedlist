#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOYUT 10

int yigit[BOYUT];
int top=-1;

int bosmu(){
	if(top==-1){
		printf("yigit bos");
		return 1;
	}

	else {
		return 0;
	}	
}
int dolumu(){
	if(top==BOYUT-1){
	   printf("yigit dolu");
	return 1;	
	}
	else {
		return 0;
	}
}

void push(int x){
	if (dolumu()==1){
     return 0;
	}
	top++;
	x=yigit[top];
	
} 
void pop(){
	if(bosmu()==1){
		return 0;
	}
	int x= yigit[top];
	top--;
	
		
}

int main(){
	
	char kelime[10];
	
	printf("kelimeyi giriniz");
	scanf("%s",&kelime);
	
	int kelimeuzunluk=strlen(kelime);
	
	for(int i=0;i<kelimeuzunluk;i++){
		if(kelime[i]=='1' || kelime[i]=='2' || kelime[i]=='3' || kelime[i]=='4' || kelime[i]=='5' || kelime[i]=='6' || kelime[i]=='7' || kelime[i]=='8' || kelime[i]=='9' ){
			push(kelime[i]);
		}
		else if(kelime[i]=='+'){
			int sonuc;
			
			sonuc=yigit[top]+ yigit[top-1];
			pop();
			pop();
			printf("%d",sonuc);
			
		}
			else if(kelime[i]=='-'){
			int sonuc;
			sonuc=yigit[top]-yigit[top-1];
			pop();
			pop();
				printf("%d",sonuc);
			
		}
		
			else if(kelime[i]=='*'){
					int sonuc;
			printf("%d");
			sonuc= yigit[top] * yigit[top-1];
			pop();
			pop();
			printf("%d",sonuc);
	
	}
		else if(kelime[i]=='/'){
				int sonuc;
			printf("%d");
			sonuc= yigit[top] / yigit[top-1];
			pop();
			pop();
		printf(" %d",sonuc);	
}
}
}







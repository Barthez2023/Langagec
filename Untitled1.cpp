#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int ikili_arama(int *T,int araman,int n){
   int deb=0,fin=n-1,orta;
   while(fin>=deb){
   	
   	    orta=(deb+fin)/2;
   		if(T[orta]==araman)
   			return 1;
		if(T[orta]<araman)
			deb=orta+1; 
		else
			fin=orta-1;
   }
}

int ikili_arama_rec(int *T,int araman,int deb,int fin){
	int orta;
	if(deb>fin)
		return -1;
	else{
		orta=(deb+fin)/2;
		if(T[orta]==araman)
	   			return 1;
	   	if(T[orta]<araman)
	   			return ikili_arama_rec(T,araman,orta+1,fin);
		else
			ikili_arama_rec(T,araman,deb,orta-1);
	}
}

int sirali_arama(int *T,int araman,int n){
	for(int i=0;i<n;i++){
		if(T[i]==araman)
			return 1;
	}
	return -1;
}


   int main(){
   	
   		int tab[]={0,5,9,11,15,22,30};
   		int cmp;
   		//cmp=ikili_arama_rec(tab,0,0,6);
   		//cmp=ikili_arama(tab,0,6);
   		cmp=sirali_arama(tab,30,7);
   		if(cmp==1)
   			printf("element bulduk");
   		else
   			printf("element bulmaduk");
   	return 0;
   }


#include <stdio.h>
#include <stdlib.h>

int le_valida_num();

int main(void) {
	int i, y, flag = 1, tam = 10, *vet;
	
	vet = malloc(tam * sizeof(int));
	
	for(i = 0; i < tam; i++) {
		printf("%d: ", i + 1);
		vet[i] = le_valida_num();	
	}
	
	y = tam;
	
	do{
		printf("Quer continuar (s/n): ");
		scanf("%d", &flag);		
		
		if(flag == 1) {
			printf("\n");
			
			printf("%d: ", y + 1);
			vet = realloc(vet, y + 1);
			
			vet[y] = le_valida_num();
			y++;
		} else {
			flag = 0;
			
			printf("\n");
			
			for(i = 0; i < y; i++) {
				printf("%d ", vet[i]);
			}		
		}
		
		
	}while(flag != 0 && y != 20);
	
	free(vet);
	
	return 0;
}

int le_valida_num() {
	int number;
	
	do{
		scanf("%d", &number);
		
		if(number < 1 || number > 99) {
			printf("\nTamanho invalido, tente novamente.\n\n");
		}
	}while(number < 1 || number > 99);
	
	return number;
}

#include <stdio.h>
#include <stdlib.h>

int le_valida_num();
int le_valida_loop();

int main(void) {
	int i, contador, aux, flag = 1, tam = 10, *vet;
	
	vet = malloc(tam * sizeof(int));
	
	for(i = 0; i < tam; i++) {
		printf("%d: ", i + 1);
		vet[i] = le_valida_num();	
	}
	
	do{
		flag = le_valida_loop();	
		
		if(flag == 1) {
			printf("\n");
			
			printf("%d: ", tam + 1);
			vet = realloc(vet, tam + 1);
			
			vet[tam] = le_valida_num();
			tam++;
		} else {
			flag = 0;
			
			printf("\n");
			
			for(contador = 1; contador < tam; contador++) {
				for(i = 0; i < tam - 1; i++) {
					if(vet[i] > vet[i + 1]) {
						aux = vet[i];
						vet[i] = vet[i + 1];
						vet[i + 1] = aux;
					}
				}
			}
			
			for(i = 0; i < tam; i++) {
				printf("%d ", vet[i]);
			}
		}
		
		
	}while(flag != 0 || tam != 20);
	
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

int le_valida_loop() {
	int flag;
	
	do{
		printf("\n***** Continuar programa *****\n\n");
		printf("1 - Continuar\n");
		printf("2 - Sair\n");
		printf("Quer continuar: ");
		scanf("%d", &flag);	
		
		if(flag < 0 || flag > 1) {
			printf("\nTamanho invalido, tente novamente.\n\n");
		}
	}while(flag < 0 || flag > 1);
	
	return flag;
}

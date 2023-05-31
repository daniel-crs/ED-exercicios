#include <stdio.h>
#include <stdlib.h>

int le_valida_num();
int le_valida_loop();
void ordena_valores();

int main(void) {
	int i, flag = 1, tam = 10, *vet;
	
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
			
			ordena_valores(vet, tam);
		}
		
		
	}while(flag != 0);
	
	free(vet);
	
	return 0;
}

int le_valida_num() {
	int number;
	
	do {
		scanf("%d", &number);
		
		if((number % 2) == 0){
			printf("\nO valor %d proibido por ser par, tente novamente.\n\n", number);
		} else if((number % 3) == 0) {
			printf("\nO valor %d proibido por ser multiplo de 3, tente novamente.\n\n", number);
		}
	}while((number % 2) == 0 || (number % 3) == 0);
	
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

void ordena_valores(int *vet, int tam) {
	int i, x, y, aux;
	
	for(x = 1; x < tam; x++) {
		aux = vet[x];
				
		for(y = x - 1; y >= 0 && vet[y] <= aux; y--) {
			vet[y + 1] = vet[y];
		}
				
		vet[y + 1] = aux;
	}
			
	for(i = 0; i < tam; i++) {
		printf("%d ", vet[i]);
	}
}

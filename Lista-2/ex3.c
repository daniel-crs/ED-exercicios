#include <stdio.h>
#include <stdlib.h>

int le_valida_num();
int le_valida_loop();
void ordena_valores_crescente();
void ordena_valores_decrescente();

int main(void) {
	int i, flag = 1, tam = 2, *vet;
	
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
			
			ordena_valores_crescente(vet, tam);
			
			printf("\n\n");
			
			ordena_valores_decrescente(vet, tam);
		}
		
		
	}while(flag != 0);
	
	free(vet);
	
	return 0;
}

int le_valida_num() {
	int number;
	
	do {
		scanf("%d", &number);
		
		if((number % 2) == 1){
			printf("\nO valor %d proibido por ser impar, tente novamente.\n\n", number);
		} else if((number % 5) == 0) {
			printf("\nO valor %d proibido por ser multiplo de 5, tente novamente.\n\n", number);
		} else if(number < 1) {
			printf("\nO valor %d proibido por ser menor que 0, tente novamente.\n\n", number);
		} else if(number > 99) {
			printf("\nO valor %d proibido por ser maior que 99, tente novamente.\n\n", number);
		}
	}while((number % 2) == 1 || (number % 5) == 0 || number < 1 || number > 99);
	
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

void ordena_valores_crescente(int *vet, int tam) {
	int i, contA, contB, aux;
			
	for(contA = 0; contA <= tam; contA++) {
		for(contB = contA + 1; contB <= tam; contB++) {
			if(vet[contA] > vet[contB]) {
				aux = vet[contB];
				vet[contB] = vet[contA];
				vet[contA] = aux;
			}
		}
	}
			
	for(i = 0; i < tam; i++) {
		printf("%d ", vet[i]);
	}
}

void ordena_valores_decrescente(int *vet, int tam) {
	int i, contA, contB, aux;
	
	for(contA = 0; contA <= tam; contA++) {
		for(contB = contA + 1; contB <= tam; contB++) {
			if(vet[contA] < vet[contB]) {
				aux = vet[contB];
				vet[contB] = vet[contA];
				vet[contA] = aux;
			}
		}
	}
			
	for(i = 0; i < tam; i++) {
		printf("%d ", vet[i]);
	}
}

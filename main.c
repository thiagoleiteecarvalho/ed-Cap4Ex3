/*
 * main.c
 * Resposta do exercício 3 do capítulo 4.
 * Author: Thiago Leite
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "pilha.h"

int main(void) {

	Pilha *pilha = iniciar();

	if (!pilha) {

		printf("Sem memória disponivel!\n");

		exit(1);
	} else {

		//Se desejar expressões maiores, aumente aqui o tamanho.
		char expressao[500];

		printf("Digite a expressão:");
		scanf("%s", expressao);

		bool valida = true;
		int i;
		for(i = 0; i < strlen(expressao); i++) {

			if (expressao[i] == '{') {
				push(pilha, '}');
			} else if (expressao[i] == '[') {
				push(pilha, ']');
			} else if (expressao[i] == '(') {
				push(pilha, ')');
			} else if (expressao[i] == ')') {

				char elemento =  pop(pilha);

				if (elemento  != ')') {
					valida = false;
					break;
				}
			} else if (expressao[i] == ']') {

				char elemento =  pop(pilha);

				if (elemento  != ']') {
					valida = false;
					break;
				}
			} else if (expressao[i] == '}') {

				char elemento =  pop(pilha);

				if (elemento  != '}') {
					valida = false;
					break;
				}
			}
		}

		if (empty(pilha) && valida) {
			printf("Expressão balanceada.");
		} else {
			printf("Expressão não balanceada.");
		}

		free(pilha);
		pilha = NULL;

		return 0;
	}
}

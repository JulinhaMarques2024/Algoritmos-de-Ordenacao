#ifndef CRESCENTE_H
#define CRESCENTE_H

#include "base.h"
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;


void CRESCENTE (int alg, int taminst, FILE* entrada, FILE* saida) {
	srand(time(NULL));

	double tempexec; //tempo de execucao

	time_t Comeco, Fim; // medir tempo de execucao

	int n = 0, seed, *vet;

	seed = (rand() % 1000000) * 100; //gerar numero aleatorio

	char arq1[400], arq2[400], arq3[400];

	char command[400]; //variavel para criar pasta (Buffer)

	switch (alg) { //Coloca a string com o caminho na variavel
		case 1:
			//INSERTION SORT

			sprintf(command, "mkdir .\\InsertionSort\\ArquivosEntrada\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\InsertionSort\\ArquivosSaida\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\InsertionSort\\ArquivosTempo\\Crescente"); //Cria a pasta
			system(command);

			cout << "Insertion" << endl << endl;
			strcpy(arq1, ".//InsertionSort//ArquivosEntrada//Crescente//"); // criando o caminho do arquivo
			strcpy(arq2, ".//InsertionSort//ArquivosSaida//Crescente//");
			strcpy(arq3, ".//InsertionSort//ArquivosTempo//Crescente//");
			cout << endl << endl;
			break;

		case 2:
			//SELECTION SORT

			sprintf(command, "mkdir .\\SelectionSort\\ArquivosEntrada\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\SelectionSort\\ArquivosSaida\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\SelectionSort\\ArquivosTempo\\Crescente"); //Cria a pasta
			system(command);			

			cout << "Selection" << endl << endl;
			strcpy(arq1, ".//SelectionSort//ArquivosEntrada//Crescente//");
			strcpy(arq2, ".//SelectionSort//ArquivosSaida//Crescente//");
			strcpy(arq3, ".//SelectionSort//ArquivosTempo//Crescente//");
			cout << endl << endl;
			break;

		case 3:
			//SHELL SORT

			sprintf(command, "mkdir .\\ShellSort\\ArquivosEntrada\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\ShellSort\\ArquivosSaida\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\ShellSort\\ArquivosTempo\\Crescente"); //Cria a pasta
			system(command);

			cout << "Shell" << endl << endl;
			strcpy(arq1, ".//ShellSort//ArquivosEntrada//Crescente//");
			strcpy(arq2, ".//ShellSort//ArquivosSaida//Crescente//");
			strcpy(arq3, ".//ShellSort//ArquivosTempo//Crescente//");
			cout << endl << endl;
			break;

		case 4:
			//BUBBLE SORT

			sprintf(command, "mkdir .\\BubbleSort\\ArquivosEntrada\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\BubbleSort\\ArquivosSaida\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\BubbleSort\\ArquivosTempo\\Crescente"); //Cria a pasta
			system(command);

			cout << "Bubble" << endl << endl;
			strcpy(arq1, ".//BubbleSort//ArquivosEntrada//Crescente//");
			strcpy(arq2, ".//BubbleSort//ArquivosSaida//Crescente//");
			strcpy(arq3, ".//BubbleSort//ArquivosTempo//Crescente//");
			cout << endl << endl;
			break;

        case 5:
			//MERGE SORT

			sprintf(command, "mkdir .\\MergeSort\\ArquivosEntrada\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\MergeSort\\ArquivosSaida\\Crescente"); //Cria a pasta
			system(command);
			sprintf(command, "mkdir .\\MergeSort\\ArquivosTempo\\Crescente"); //Cria a pasta
			system(command);

			cout << "Merge" << endl << endl;
			strcpy(arq1, ".//MergeSort//ArquivosEntrada//Crescente//");
			strcpy(arq2, ".//MergeSort//ArquivosSaida//Crescente//");
			strcpy(arq3, ".//MergeSort//ArquivosTempo//Crescente//");
			cout << endl << endl;
			break;
    }

	switch (taminst)
	{
	case 1:
		cout << "INSTANCIA TAMANHO 10" << endl;
		n = 10; //define tamanho


		vet = new int[n]; //aloca array
		cout << "SEMENTE GERADA:" << seed << endl;

	    strcat(arq1, "10CRES.txt"); //arqentrada concatena o caminho do arquivo
		strcat(arq2, "10SAID.txt"); //arqsaida
		strcat(arq3, "10TEMPO.txt"); //arqtemp

		entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

		fprintf(entrada, "10\n"); //escreve a primeira linha do arquivo como 10;

		for (int i = 0; i < n; i++) { //escreve os numeros em ordem crescente no arquivo
			vet[i] = seed;
			fprintf(entrada, "%d\n", vet[i]);
			seed++;
		}

		fclose(entrada); //fecha os arquivos

		cout << endl;

		if (alg == 1) {
			Comeco = clock(); //marca o tempo de inicio
			InsertionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 2) {
			Comeco = clock(); //marca o tempo de inicio
			SelectionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 3) {
			Comeco = clock(); //marca o tempo de inicio
			ShellSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		if (alg == 4) {
			Comeco = clock(); //marca o tempo de inicio
			BubbleSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
        if (alg == 5) {
			Comeco = clock(); //marca o tempo de inicio
			MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		cout << "ORDENACAO FEITA" << endl;
		saida = fopen(arq2, "w"); //abro o arquivo de saida

		fprintf(saida, "10\n"); //escreve a primeira linha do arquivo como 10;

		for (int m = 0; m < n; m++) { //escreve o vetor ordenado no arquivo de saida
			fprintf(saida, "%d\n", vet[m]);
		}

		fclose(saida); // fecha o arquivo de saida

		tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

		entrada = fopen(arq3, "w");
		fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
		
		fclose(entrada); //fecha o arquivo de tempo

		delete[] vet; //desaloca o vetor
		break;

	case 2:
		cout << "INSTANCIA TAMANHO 100" << endl;
		n = 100; //define tamanho


		vet = new int[n]; //aloca array
		cout << "SEMENTE GERADA:" << seed << endl;

	    strcat(arq1, "100CRES.txt"); //arqentrada
		strcat(arq2, "100SAID.txt"); //arqsaida
		strcat(arq3, "100TEMPO.txt"); //arqtemp

		entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

		fprintf(entrada, "100\n"); //escreve a primeira linha do arquivo como 10;

		for (int i = 0; i < n; i++) { //escreve os numeros em ordem crescente no arquivo
			vet[i] = seed;
			fprintf(entrada, "%d\n", vet[i]);
			seed++;
		}

		fclose(entrada); //fecha os arquivos

		cout << endl;

		if (alg == 1) {
			Comeco = clock(); //marca o tempo de inicio
			InsertionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 2) {
			Comeco = clock(); //marca o tempo de inicio
			SelectionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 3) {
			Comeco = clock(); //marca o tempo de inicio
			ShellSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		if (alg == 4) {
			Comeco = clock(); //marca o tempo de inicio
			BubbleSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
        if (alg == 5) {
			Comeco = clock(); //marca o tempo de inicio
			MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}


		cout << "ORDENACAO FEITA" << endl;
		saida = fopen(arq2, "w");

		fprintf(saida, "100\n"); //escreve a primeira linha do arquivo como 10;

		for (int m = 0; m < n; m++) {
			fprintf(saida, "%d\n", vet[m]);
		}

		fclose(saida);

		tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

		entrada = fopen(arq3, "w");
		fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
		
		fclose(entrada);

		delete[] vet;
		break;

	case 3:
		cout << "INSTANCIA TAMANHO 1000" << endl;
		n = 1000; //define tamanho


		vet = new int[n]; //aloca array
		cout << "SEMENTE GERADA:" << seed << endl;

	    strcat(arq1, "1000CRES.txt"); //arqentrada
		strcat(arq2, "1000SAID.txt"); //arqsaida
		strcat(arq3, "1000TEMPO.txt"); //arqtemp

		entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

		fprintf(entrada, "1000\n"); //escreve a primeira linha do arquivo como 10;

		for (int i = 0; i < n; i++) { //escreve os numeros em ordem crescente no arquivo
			vet[i] = seed;
			fprintf(entrada, "%d\n", vet[i]);
			seed++;
		}

		fclose(entrada); //fecha os arquivos

		cout << endl;

		if (alg == 1) {
			Comeco = clock(); //marca o tempo de inicio
			InsertionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 2) {
			Comeco = clock(); //marca o tempo de inicio
			SelectionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 3) {
			Comeco = clock(); //marca o tempo de inicio
			ShellSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		if (alg == 4) {
			Comeco = clock(); //marca o tempo de inicio
			BubbleSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
        if (alg == 5) {
			Comeco = clock(); //marca o tempo de inicio
			MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		cout << "ORDENACAO FEITA" << endl;
		saida = fopen(arq2, "w");

		fprintf(saida, "1000\n"); //escreve a primeira linha do arquivo como 10;

		for (int m = 0; m < n; m++) {
			fprintf(saida, "%d\n", vet[m]);
		}

		fclose(saida);

		tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

		entrada = fopen(arq3, "w");
		fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
		
		fclose(entrada);

		delete[] vet;
		break;

	case 4:
		cout << "INSTANCIA TAMANHO 10000" << endl;
		n = 10000; //define tamanho


		vet = new int[n]; //aloca array
		cout << "SEMENTE GERADA:" << seed << endl;

	    strcat(arq1, "10000CRES.txt"); //arqentrada
		strcat(arq2, "10000SAID.txt"); //arqsaida
		strcat(arq3, "10000TEMPO.txt"); //arqtemp

		entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

		fprintf(entrada, "10000\n"); //escreve a primeira linha do arquivo como 10;

		for (int i = 0; i < n; i++) { //escreve os numeros em ordem crescente no arquivo
			vet[i] = seed;
			fprintf(entrada, "%d\n", vet[i]);
			seed++;
		}

		fclose(entrada); //fecha os arquivos

		cout << endl;

		if (alg == 1) {
			Comeco = clock(); //marca o tempo de inicio
			InsertionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 2) {
			Comeco = clock(); //marca o tempo de inicio
			SelectionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 3) {
			Comeco = clock(); //marca o tempo de inicio
			ShellSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		if (alg == 4) {
			Comeco = clock(); //marca o tempo de inicio
			BubbleSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
        if (alg == 5) {
			Comeco = clock(); //marca o tempo de inicio
			MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		cout << "ORDENACAO FEITA" << endl;
		saida = fopen(arq2, "w");

		fprintf(saida, "10000\n"); //escreve a primeira linha do arquivo como 10;

		for (int m = 0; m < n; m++) {
			fprintf(saida, "%d\n", vet[m]);
		}

		fclose(saida);

		tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

		entrada = fopen(arq3, "w");
		fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo
		
		fclose(entrada);

		delete[] vet;
		break;

	case 5:
		cout << "INSTANCIA TAMANHO 100.000" << endl;
		n = 100000; //define tamanho


		vet = new int[n]; //aloca array
		cout << "SEMENTE GERADA:" << seed << endl;

		strcat(arq1, "100000CRES.txt"); //arqentrada
		strcat(arq2, "100000SAID.txt"); //arqsaida
		strcat(arq3, "100000TEMPO.txt"); //arqtemp

		entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1
		if (entrada == NULL) {
			cout << "NULL" << endl;
		}

		fprintf(entrada, "100000\n"); //escreve a primeira linha do arquivo como 10000;

		for (int i = 0; i < n; i++) { //escreve os numeros em ordem crescente no arquivo
			vet[i] = seed;
			fprintf(entrada, "%d\n", vet[i]);
			seed++;
		}

		fclose(entrada); //fecha os arquivos

		cout << endl;

		if (alg == 1) {
			Comeco = clock(); //marca o tempo de inicio
			InsertionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 2) {
			Comeco = clock(); //marca o tempo de inicio
			SelectionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 3) {
			Comeco = clock(); //marca o tempo de inicio
			ShellSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		if (alg == 4) {
			Comeco = clock(); //marca o tempo de inicio
			BubbleSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
        if (alg == 5) {
			Comeco = clock(); //marca o tempo de inicio
			MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		cout << "ORDENACAO FEITA" << endl;
		saida = fopen(arq2, "w");

		fprintf(saida, "100000\n"); //escreve a primeira linha do arquivo como 10000;


		for (int m = 0; m < n; m++) {
			fprintf(saida, "%d\n", vet[m]);
		}

		fclose(saida);

		tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

		entrada = fopen(arq3, "w");
		fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo

		fclose(entrada);

		delete[] vet;
		break;

	case 6:
		cout << "INSTANCIA TAMANHO 1.000.000" << endl;
		n = 1000000; //define tamanho

		vet = new int[n]; //aloca array
		cout << "SEMENTE GERADA:" << seed << endl;

		strcat(arq1, "1000000CRES.txt"); //arqentrada
		strcat(arq2, "1000000SAID.txt"); //arqsaida
		strcat(arq3, "1000000TEMPO.txt"); //arqtemp

		entrada = fopen(arq1, "w"); //abre arquivo, escreve o que está em arq1

		fprintf(entrada, "1000000\n"); //escreve a primeira linha do arquivo como 1000000;

		for (int i = 0; i < n; i++) { //escreve os numeros em ordem crescente no arquivo
			vet[i] = seed;
			fprintf(entrada, "%d\n", vet[i]);
			seed++;
		}

		fclose(entrada); //fecha os arquivos

		cout << endl;

		if (alg == 1) {
			Comeco = clock(); //marca o tempo de inicio
			InsertionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 2) {
			Comeco = clock(); //marca o tempo de inicio
			SelectionSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
		if (alg == 3) {
			Comeco = clock(); //marca o tempo de inicio
			ShellSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		if (alg == 4) {
			Comeco = clock(); //marca o tempo de inicio
			BubbleSort(vet, n); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}
        if (alg == 5) {
			Comeco = clock(); //marca o tempo de inicio
			MergeSort(vet, 0, n-1); //roda o algoritmo e ordena
			Fim = clock(); //marca o tempo do fim
		}

		cout << "ORDENACAO FEITA" << endl;
		saida = fopen(arq2, "w");

		fprintf(saida, "1000000\n"); //escreve a primeira linha do arquivo como 1000000;

		for (int m = 0; m < n; m++) {
			fprintf(saida, "%d\n", vet[m]);
		}

		fclose(saida);

		tempexec = ((Fim - Comeco) / (double)CLOCKS_PER_SEC); //calcula o tempo

		entrada = fopen(arq3, "w");
		fprintf(entrada, "O TEMPO DE EXECUCAO FOI: %.50f", tempexec); //grava o tempo no arquivo

		fclose(entrada);

		delete[] vet;
		break;

	default:
		cout << "ERRO, OPCAO INVALIDA" << endl << endl;
		break;
	}	
}

#endif // !CRESCENTE_H
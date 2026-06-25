#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct para armazenar as caracterísiticas dos pokémons
struct pokemon{
        char nome[15];
        int ataque;
        int defesa;
        int vida;
        char tipo[12];
}Pokemon[150];



int main(){
        
        int pokemons_jogador1, pokemons_jogador2, i, j, k, m, auxiliar, batalha=1, pontos_jogador1=0, pontos_jogador2=0, ataque;

	//Abrir o arquivo para ler as informações
        FILE *arq = fopen("jogadores.txt", "r");

	if (arq == NULL) {
		printf("Erro ao abrir o arquivo");
		exit(0);
	}
        

	//Ler a quantidade de Pokémons de cada jogador 
        fscanf(arq,"%d %d", &pokemons_jogador1, &pokemons_jogador2);
 

	//Armazenar no vetor de struct os pokemons do jogador 1
        for (i=0; i<pokemons_jogador1; i++){   
              fscanf(arq, "%s %d %d %d %s", &Pokemon[i].nome, &Pokemon[i].ataque, &Pokemon[i].defesa, &Pokemon[i].vida, &Pokemon[i].tipo);
        }

	//Armazenar no vetor de struct os pokemons do jogador 2
	for (i=pokemons_jogador1; i<pokemons_jogador1+pokemons_jogador2; i++){ 
              fscanf(arq, "%s %d %d %d %s", &Pokemon[i].nome, &Pokemon[i].ataque, &Pokemon[i].defesa, &Pokemon[i].vida, &Pokemon[i].tipo); 
        }

	//Fechar o arquivo
	fclose(arq);


	//Imprimir as especificações dos pokemons do jogador 1
	printf("\n---------------------Jogador 1: %d Pokemons---------------------", pokemons_jogador1);
	printf("\n   Nome        Ataque        Defesa        Vida        Tipo\n");

	for (i=0; i<pokemons_jogador1; i++){
		printf("\n  %-12s", Pokemon[i].nome);
		printf("   %-3d", Pokemon[i].ataque);
		printf("           %-3d", Pokemon[i].defesa);
		printf("          %-3d", Pokemon[i].vida);
		printf("        %s", Pokemon[i].tipo);
	}

	printf("\n---------------------------------------------------------------");


	//Imprimir as especificações dos pokemons do jogador 2
	printf("\n\n\n---------------------Jogador 2: %d Pokemons---------------------", pokemons_jogador2);
	printf("\n   Nome        Ataque        Defesa        Vida        Tipo\n");

	for (i=pokemons_jogador1; i<pokemons_jogador1+pokemons_jogador2; i++){
		printf("\n  %-12s", Pokemon[i].nome);
		printf("   %-3d", Pokemon[i].ataque);
		printf("           %-3d", Pokemon[i].defesa);
		printf("          %-3d", Pokemon[i].vida);
		printf("        %s", Pokemon[i].tipo);
	}

	printf("\n---------------------------------------------------------------");



	




	//Pegar o primeiro pokemon de cada jogador.Obs: O indice do primeiro pokemon do jogador 2 é igual ao numero de pokemons do jogador 1
	i=0; j=pokemons_jogador1;


	do{	
		//Verificar se há ataques efetivos ou nao efetivos e realizar o mecanismo de batalha

		if (!(strcmp(Pokemon[i].tipo, "eletrico")) && !(strcmp(Pokemon[j].tipo, "agua"))){
			ataque = Pokemon[i].ataque * 1.2;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - (ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}

			
		} else

		if (!(strcmp(Pokemon[i].tipo, "eletrico")) && !(strcmp(Pokemon[j].tipo, "pedra"))){
			ataque = Pokemon[i].ataque * 0.8;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - (ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}


		} else

		if (!(strcmp(Pokemon[i].tipo, "agua")) && !(strcmp(Pokemon[j].tipo, "fogo"))){
			
			ataque = Pokemon[i].ataque * 1.2;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - (ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}

		
		} else

		if (!(strcmp(Pokemon[i].tipo, "agua")) && !(strcmp(Pokemon[j].tipo, "eletrico"))){
			ataque = Pokemon[i].ataque * 0.8;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - ( ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}
		

		} else
		
		if (!(strcmp(Pokemon[i].tipo, "fogo")) && !(strcmp(Pokemon[j].tipo, "gelo"))){
			
			ataque = Pokemon[i].ataque * 1.2;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - (ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}


		} else	
	
		if (!(strcmp(Pokemon[i].tipo, "fogo")) && !(strcmp(Pokemon[j].tipo, "agua"))){
			ataque = Pokemon[i].ataque * 0.8;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - ( ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}


		} else

		if (!(strcmp(Pokemon[i].tipo, "gelo")) && !(strcmp(Pokemon[j].tipo, "pedra"))){
			ataque = Pokemon[i].ataque * 1.2;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - ( ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}


		} else

		if (!(strcmp(Pokemon[i].tipo, "gelo")) && !(strcmp(Pokemon[j].tipo, "fogo"))){
			ataque = Pokemon[i].ataque * 0.8;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - ( ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}


		} else

		if (!(strcmp(Pokemon[i].tipo, "pedra")) && !(strcmp(Pokemon[j].tipo, "eletrico"))){
			ataque = Pokemon[i].ataque * 1.2;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - (ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}


		} else	

		if (!(strcmp(Pokemon[i].tipo, "pedra")) && !(strcmp(Pokemon[j].tipo, "gelo"))){
			ataque = Pokemon[i].ataque * 0.8;

			if ( ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - ( ataque - Pokemon[j].defesa);
			}

			if ( ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}

		
		} else {

			if ( Pokemon[i].ataque > Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - (Pokemon[i].ataque - Pokemon[j].defesa);
			}

			if ( Pokemon[i].ataque <= Pokemon[j].defesa ){
				Pokemon[j].vida = Pokemon[j].vida - 1;
			}
		}



		
		//Verificar a vida do pokemon e alternar os turnos de ataque
		
		if ( Pokemon[j].vida <= 0 ){
			//Imprimir o vencedor de cada batalha
			printf("\n\n\n--------------------Resultado da Batalha %d---------------------\n",batalha);
			printf("\n\t\t    %s venceu %s\n", Pokemon[i].nome, Pokemon[j].nome);
			if ( i < pokemons_jogador1 ){	
				printf("\n\t\t    Ponto para o jogador 1\n ");
				pontos_jogador1 = pontos_jogador1 + 1;
			} else {
				printf("\n\t\t    Ponto para o jogador 2\n ");
				pontos_jogador2 = pontos_jogador2 + 1;
			}
			printf("\n---------------------------------------------------------------");

			printf("\n\ni: %d",i);
			printf("\n\nj: %d",j);
			
			//Incrementando o contador de batalhas
			batalha = batalha + 1;

			//Interrompendo o loop caso chegue ao ultimo pokemons de um dos jogadores 
			//Ou alterando para o proximo pokemon do jogador que perdeu a batalha
			if ( j == pokemons_jogador1-1 || j == pokemons_jogador1+pokemons_jogador2-1 ){
				//Interromper o loop
				break;				
			} else {
				//Alterando os turnos, o pokemon que entrou começa atacando 
				auxiliar = j + 1;
				j = i;	
				i = auxiliar;
			}
			
		} else {
			//Alterarando os turnos, mudando o pokemon atacante
			auxiliar = j;
			j = i;
			i = auxiliar;
		}	
		
	}while(1);


	//Criei essa variáveis para guardar os valores de i e j depois das batalhas terminarem, para saber os índices dos pokemons
	i = k;
	j = m;


	//Impimir quem venceu a batalha 
	printf("\n\n\n\n---------------------O Grande Campeao------------------------");
	
	if ( pontos_jogador1 > pontos_jogador2 ){

		printf("\n\n\t\t    O jogador 1 venceu!!!");

	} else {

		printf("\n\n\t\t    O jogador 2 venceu!!!");
	}
	printf("\n\n---------------------------------------------------------------");





	
	//Imprimir os pokemons sobreviventes 
	printf("\n\n\n\n-------------------Pokemons sobreviventes----------------------");

	//Caso o jogador 1 ganhe
	if( j == pokemons_jogador1+pokemons_jogador2-1 ){

		for ( i; i < pokemons_jogador1; i++){
			
			printf("\n\n\t\t\t  %s", Pokemon[i].nome);
		}
	}

	//Caso o jogador 2 ganhe
	if( j == pokemons_jogador1-1 ){

		for ( i; i < pokemons_jogador1+pokemons_jogador2; i++){
			
			printf("\n\t\t\t  %s", Pokemon[i].nome);
		}
	}
	printf("\n\n---------------------------------------------------------------");


	printf("\n\ni: %d",i);
	printf("\n\nj: %d",j);


	//Imprimindo os Pokemons derrotados do Jogador 1 e do Jogador 2 respectivamente

	printf("\n\n---------------------Pokemons derrotados-----------------------");

	//Caso o jogador 1 ganhe
	if( j == pokemons_jogador1+pokemons_jogador2-1 ){

		printf("\n\n\t\t    Pokemons do jogador 1: ");
		for ( i; i > 0; i--){
			
			printf("\n\t\t\t  %s", Pokemon[(pokemons_jogador1 - 1)- i].nome);
		}

		printf("\n\n\t\t    Pokemons do jogador 2:");
		for ( j=pokemons_jogador1; j < pokemons_jogador1+pokemons_jogador2; j++){
				
			printf("\n\t\t\t  %s", Pokemon[j].nome);
		}
	}
	
	//Caso o jogador 2 ganhe
	/*if( j == pokemons_jogador1-1 ){

		for ( i; i >= pokemons_jogador1; i--){
			
			printf("\n\t\t\t  %s", Pokemon[i].nome);
		}

		for ( j; j >= 0; j--){
						
			printf("\n\n\t\t\t  %s", Pokemon[j].nome);
		}
	}*/
	printf("\n\n---------------------------------------------------------------");



return 0;
}

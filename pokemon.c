#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//Struct para armazenar as caracterísiticas dos pokémons
typedef struct {
        char nome[15];
        int ataque;
        int defesa;
        int vida;
        char tipo[12];
}pokemon;



//Imprimir os dados de cada pokemon de cada jogador
void dados_pokemons ( pokemon *pokemons, int pokemons_jogador1, int pokemons_jogador2){

	int i;
	
	//Imprimir as especificações dos pokemons do jogador 1
	printf("\n---------------------Jogador 1: %d Pokemons---------------------", pokemons_jogador1);
	printf("\n   Nome        Ataque        Defesa        Vida        Tipo\n");

	for (i=0; i<pokemons_jogador1; i++){
		//Delimitei o tamanho de cada impressão pra tabela ficar formatada  
		printf("\n  %-12s", (pokemons + i)->nome);
		printf("   %-3d", (pokemons + i)->ataque);
		printf("           %-3d", (pokemons + i)->defesa);
		printf("          %-3d", (pokemons + i)->vida);
		printf("        %s", (pokemons + i)->tipo);
	}

	printf("\n---------------------------------------------------------------");


	//Imprimir as especificações dos pokemons do jogador 2
	printf("\n\n\n---------------------Jogador 2: %d Pokemons---------------------", pokemons_jogador2);
	printf("\n   Nome        Ataque        Defesa        Vida        Tipo\n");

	for (i=pokemons_jogador1; i<pokemons_jogador1+pokemons_jogador2; i++){
		printf("\n  %-12s", (pokemons + i)->nome);
		printf("   %-3d", (pokemons + i)->ataque);
		printf("           %-3d", (pokemons + i)->defesa);
		printf("          %-3d", (pokemons + i)->vida);
		printf("        %s", (pokemons + i)->tipo);
	}

	printf("\n---------------------------------------------------------------");

}



//Mecanismo do sistema de batalhas 
void batalhas (pokemon *pokemons, int pokemons_jogador1, int pokemons_jogador2, int *k, int *m){		

	int i, j, ataque, batalha = 1, auxiliar, pontos_jogador1 = 0, pontos_jogador2 = 0;

	//Pegar o primeiro pokemon de cada jogador.Obs: O indice do primeiro pokemon do jogador 2 é igual ao numero de pokemons do jogador 1
	i =0 ; 
	j = pokemons_jogador1;


	do{	
		//Verificar se há ataques efetivos ou nao efetivos e realizar o mecanismo de batalha

		if (!(strcmp((pokemons + i)->tipo, "eletrico")) && !(strcmp((pokemons + j)->tipo, "agua"))){
			ataque = (pokemons + i)->ataque * 1.2;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - (ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}

			
		} else

		if (!(strcmp((pokemons + i)->tipo, "eletrico")) && !(strcmp((pokemons + j)->tipo, "pedra"))){
			ataque = (pokemons + i)->ataque * 0.8;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - (ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}


		} else

		if (!(strcmp((pokemons + i)->tipo, "agua")) && !(strcmp((pokemons + j)->tipo, "fogo"))){
			
			ataque = (pokemons + i)->ataque * 1.2;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida =(pokemons + j)->vida - (ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}

		
		} else

		if (!(strcmp((pokemons + i)->tipo, "agua")) && !(strcmp((pokemons + j)->tipo, "eletrico"))){
			ataque = (pokemons + i)->ataque * 0.8;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - ( ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}
		

		} else
		
		if (!(strcmp((pokemons + i)->tipo, "fogo")) && !(strcmp((pokemons + j)->tipo, "gelo"))){
			
			ataque = (pokemons + i)->ataque * 1.2;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - (ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}


		} else	
	
		if (!(strcmp((pokemons + i)->tipo, "fogo")) && !(strcmp((pokemons + j)->tipo, "agua"))){
			ataque = (pokemons + i)->ataque * 0.8;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - ( ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}


		} else

		if (!(strcmp((pokemons + i)->tipo, "gelo")) && !(strcmp((pokemons + j)->tipo, "pedra"))){
			ataque = (pokemons + i)->ataque * 1.2;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida =(pokemons + j)->vida - ( ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}


		} else

		if (!(strcmp((pokemons + i)->tipo, "gelo")) && !(strcmp((pokemons + j)->tipo, "fogo"))){
			ataque = (pokemons + i)->ataque * 0.8;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - ( ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}


		} else

		if (!(strcmp((pokemons + i)->tipo, "pedra")) && !(strcmp((pokemons + j)->tipo, "eletrico"))){
			ataque = (pokemons + i)->ataque * 1.2;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - (ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}


		} else	

		if (!(strcmp((pokemons + i)->tipo, "pedra")) && !(strcmp((pokemons + j)->tipo, "gelo"))){
			ataque = (pokemons + i)->ataque * 0.8;

			if ( ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - ( ataque - (pokemons + j)->defesa);
			}

			if ( ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}

		
		} else {

			if ( (pokemons + i)->ataque > (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - ((pokemons + i)->ataque - (pokemons + j)->defesa);
			}

			if ( (pokemons + i)->ataque <= (pokemons + j)->defesa ){
				(pokemons + j)->vida = (pokemons + j)->vida - 1;
			}
		}



		
		//Verificar a vida do pokemon e alternar os turnos de ataque
		
		if ( (pokemons + j)->vida <= 0 ){

			//Imprimir o vencedor de cada batalha
			printf("\n\n\n\n\n\n\n\n--------------------Resultado da Batalha %d---------------------\n",batalha);

			printf("\n\t\t    %s venceu %s\n",(pokemons + i)->nome, (pokemons + j)->nome);

			if ( i < pokemons_jogador1 ){	

				printf("\n\t\t    Ponto para o jogador 1\n ");
				pontos_jogador1 = pontos_jogador1 + 1;
			} else {

				printf("\n\t\t    Ponto para o jogador 2\n ");
				pontos_jogador2 = pontos_jogador2 + 1;
			}
			printf("\n---------------------------------------------------------------");

			

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
	


	//Impimir quem venceu a batalha 
	printf("\n\n\n\n\n\n\n\n\n---------------------O Grande Campeao------------------------");
	
	if ( pontos_jogador1 > pontos_jogador2 ){

		printf("\n\n\t\t    O jogador 1 venceu!!!");

	} else {

		printf("\n\n\t\t    O jogador 2 venceu!!!");
	}
	printf("\n\n---------------------------------------------------------------");



	//Armazenei i e j nos ponteiros para poder usar no restante do código 
	*k = i;
	*m = j;


}
		






int main(){
        

	pokemon Pokemon[150];

	//As letras declaradas são auxiliares que serão explicadas na primeira vez que eles forem implementadas
        int pokemons_jogador1, pokemons_jogador2, i, j, k, m, x, y;


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


	//Imprimir os dados de cada pokemon de cada jogador
	dados_pokemons(Pokemon, pokemons_jogador1, pokemons_jogador2); 	



	//Mecanismo de batalhas
	batalhas(Pokemon, pokemons_jogador1, pokemons_jogador2, &k, &m);

	

	//Atribui os valores de k e m retornados da função batalhas para eles não serem perdidos 
	i = k;
	j = m;


	
	//Imprimir os pokemons sobreviventes 
	printf("\n\n\n\n-------------------Pokemons sobreviventes----------------------");

	//Caso o jogador 1 ganhe
	if( m == pokemons_jogador1+pokemons_jogador2-1 ){

		for ( k ; k < pokemons_jogador1; k++){
			
			printf("\n\n\t\t\t  %s", Pokemon[k].nome);
		}
	}

	//Caso o jogador 2 ganhe
	if( m == pokemons_jogador1-1 ){

		for ( k ; k < pokemons_jogador1+pokemons_jogador2; k++){
			
			printf("\n\n\t\t\t  %s", Pokemon[k].nome);
		}
	}
	printf("\n\n---------------------------------------------------------------");





	//Atribuindo os valores armazenados novamente a k e m para funcionar corretamente o restante do código
	k = i;
	m = j;
	

	//Imprimindo os Pokemons derrotados do Jogador 1 e do Jogador 2 respectivamente

	printf("\n\n---------------------Pokemons derrotados-----------------------");

	//Caso o jogador 1 ganhe
	if( m == pokemons_jogador1+pokemons_jogador2-1 ){

		//Criei x e y para printar os pokemons derrotados na ordem correta
		printf("\n\n\t\t    Pokemons do jogador 1: ");

		for ( x=0 ; x < k ; x++){
			
			printf("\n\t\t\t  %s", Pokemon[x].nome);
		}

		printf("\n\n\t\t    Pokemons do jogador 2:");

		for ( y=pokemons_jogador1; y < pokemons_jogador1+pokemons_jogador2; y++){
				
			printf("\n\t\t\t  %s", Pokemon[y].nome);
		}
	}
	
	//Caso o jogador 2 ganhe
	if( m == pokemons_jogador1-1 ){

		printf("\n\n\t\t    Pokemons do jogador 1: ");

		for ( x=0 ; x < pokemons_jogador1 ; x++){
			
			printf("\n\t\t\t  %s", Pokemon[x].nome);
		}

		printf("\n\n\t\t    Pokemons do jogador 2:");

		for ( y=pokemons_jogador1; y < k ; y++){
				
			printf("\n\t\t\t  %s", Pokemon[y].nome);
		}

	}
	printf("\n\n---------------------------------------------------------------");



return 0;
}

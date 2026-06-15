#include <stdio.h>
#include<string.h>


typedef struct{
        char nome[12];
        int ataque;
        int defesa;
        int vida;
        char tipo[12]
}pokemon;


typedef struct {
        pokemon numero[50];
}jogador;

typedef struct {
        struct{
                char nome[12];
                int ataque;
                int defesa;
                int vida;
                char tipo[12]
        }
}jogador;

int main(){
        
        int pokemons_jogador1, pokemons_jogador2, i;

        FILE *arq = fopen("jogadores.txt", "r");
        
        fscanf(arq,"%d %d", pokemons_jogador1, pokemons_jogador2);
        
        jogador numero1;
        jogador numero2;
        

        for (i=0; i<pokemons_jogador1; i++){
                       
              
        
        
        
        }














return 0;
}

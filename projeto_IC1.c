//Tiago Costa Carvalho 11315102
//Sabrina Kappann da Silva 11208332

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

 struct Filmes {    //struct para parte 1
    char title[50];
    char rating[20];
    char ratingLevel[100];
    char ratingDescription[10];
    char releaseYear[5];
    char userRatingScore[10];
    char userRatingSize[10];
    }; struct Filmes filme[1001];   // tem tamanho 1001 pois há o cabeçalho do arquivo
struct Rating {     //estrutura para o enunciado 2
    int PG_13;
    int R;
    int TV_14;
    int TV_PG;
    int TV_MA;
    int TV_Y;
    int NR;
    int TV_Y7_FV;
    int UR;
    int PG;
    int TV_G;
    int G;
    int TV_Y7;
    int ano;
};


int filmeporano(){  // função para questão 3
        printf("Insira o ano, para que seja mostrado o número de filmes lancados nesse ano\n");
        int year;
        scanf("%i", &year);
        int a = 0;
        for (int i = 1; i <= 1001; i++){

        int yearConvert = atoi(filme[i].releaseYear);

            if (year == yearConvert){
            a += 1;
            }
        }
        printf("total de filmes lancados em %i : %i\n", year, a);
}





int carac_cont(const char* avaliado, const char* avalia){    //conta uma certa description, função para questão 5
    int i, contador = 0;
    char *retorno;
    retorno = strstr(avaliado, avalia);                      //retorno recebe tudo o que o avaliado tem igual e após a palavra avalia
    if(retorno != NULL){                                     //caso retorna receba algo, ou seja, tem algo em comum com avalia...
        contador++;                                          //o contador de violence sobe
    }
    return(contador);
}

int busca_por_chave(const char* a){                          //funcao para enunciado 6
    int i;
    char *check;
    for(i = 0; i < 1001; i++){                               //checa todos os filmes se...
        check = strstr(filme[i].title, a );                  //eles possuem o checador "a" no nome..
        if(check != NULL){                                  //e caso possuam, suas características sao imprimidas.
            printf("\nfilme: %s:\n faixa etaria: %s\n descricao da faixa etaria: %s.", filme[i].title, filme[i].rating, filme[i].ratingLevel);
        }
    }
    return(0);
}





int main()
{

    int i, linha=0, yearConvert, a, b=0;

    char *token = NULL;
    char *checador;
    FILE *file;
    file = fopen("netflix_all.csv", "r+");          // o arquivo netflix_all esta na pasta do programa
    if (file == NULL){
        printf("erro ao abrir arquivo");
        return 0;
    }

    //ler linha de 0 até 1001
    //fazer o strtok para CADA LINHA! a primeira chamada sera a linha q ele pegou



    char linhaLida[200]; // armazena linha a linha do texto para ser usada
    char NA[3] = "NA";
    while( fgets(linhaLida, sizeof(linhaLida), file) != NULL )  {
        checador = strstr(linhaLida, ";;");
        if(checador != NULL){ //checa se há um filme com erro de formatação.
            strcpy(filme[linha].title, "NA");
            strcpy(filme[linha].rating, "NA");
            strcpy(filme[linha].ratingLevel, "NA");
            strcpy(filme[linha].ratingDescription, "NA");
            strcpy(filme[linha].releaseYear, "NA");
            strcpy(filme[linha].userRatingScore, "NA");
            strcpy(filme[linha].userRatingSize, "NA");
            linha++;
        }else{

            token = strtok(linhaLida,";"); //inicia com a linha lida em questão
            strcpy(filme[linha].title, token);

            token = strtok(NULL,";");
            strcpy(filme[linha].rating, token);

            token = strtok(NULL,";");
            strcpy(filme[linha].ratingLevel, token);

            token = strtok(NULL,";");
            strcpy(filme[linha].ratingDescription, token);

            token = strtok(NULL,";");
            strcpy(filme[linha].releaseYear, token);

            token = strtok(NULL,";");
            strcpy(filme[linha].userRatingScore, token);

            token = strtok(NULL,";");
            strcpy(filme[linha].userRatingSize, token);

            linha++; // vai para a prox linha
        }
    }

   //*************PARTE 2************

    printf("********QUESTAO 2********\n\n");
 // criou uma estrutura para cada ano y desde 1940 (menor data)
        struct Rating y[78]; //ate 2017 (maior data); y[0] = 1939, y[77] = 2017; posição = ano - 1939
        for (i = 0; i < 79; i++){       //inicializando tudo com zero para usar no contador depois
            y[i].PG_13 = 0;
            y[i].R = 0;
            y[i].TV_14 = 0;
            y[i].TV_PG = 0;
            y[i].TV_MA = 0;
            y[i].TV_Y = 0;
            y[i].NR = 0;
            y[i].TV_Y7_FV = 0;
            y[i].UR = 0;
            y[i].PG = 0;
            y[i].TV_G = 0;
            y[i].G = 0;
            y[i].TV_Y7 = 0;
            y[i].ano = (1939 + i);
        }


        for (i = 0; i < 1001; i++){         //printf("valor de i: %i\n", i);
            for (b = 0; b < 79; b++){       //printf("valor de b: %i\n", b);
            yearConvert = atoi(filme[i].releaseYear); // converte releaseYear para int

            if (yearConvert == y[b].ano){   //compara o releaseYear com o ano do contador
                int resultado = strcmp (filme[i].rating, "PG-13" );
                if (resultado == 0){
                    y[b].PG_13 +=1;
                }
                 resultado = strcmp (filme[i].rating, "R" );
                if (resultado == 0){
                    y[b].R +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-14" );
                if (resultado == 0){
                    y[b].TV_14 +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-PG" );
                if (resultado == 0){
                    y[b].TV_PG +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-MA" );
                if (resultado == 0){
                    y[b].TV_MA +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-Y" );
                if (resultado == 0){
                    y[b].TV_Y +=1;
                }
                 resultado = strcmp (filme[i].rating, "NR" );
                if (resultado == 0){
                    y[b].NR +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-Y7-FV" );
                if (resultado == 0){
                    y[b].TV_Y7_FV +=1;
                }
                 resultado = strcmp (filme[i].rating, "UR" );
                if (resultado == 0){
                    y[b].UR +=1;
                }
                 resultado = strcmp (filme[i].rating, "PG" );
                if (resultado == 0){
                    y[b].PG +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-G" );
                if (resultado == 0){
                    y[b].TV_G +=1;
                }
                 resultado = strcmp (filme[i].rating, "G" );
                if (resultado == 0){
                    y[b].G +=1;
                }
                 resultado = strcmp (filme[i].rating, "TV-Y7" );
                if (resultado == 0){
                    y[b].TV_Y7 +=1;
                }
            }
          }
        }
    printf("Total de tipos de ratings por ano: \n");
    for (i = 1; i< 79; i++){
    printf("ano = %i\n PG-13 = %i\n R = %i\n TV-14 = %i\n TV-PG = %i\n TV-MA =%i\n TV-Y =%i\n NR =%i\n TV-Y7-FV =%i\n UR =%i\n PG =%i\n TV-G =%i\n G =%i\n TV-Y7 = %i\n\n\n",
 y[i].ano, y[i].PG_13,y[i].R, y[i].TV_14,y[i].TV_PG, y[i].TV_MA,y[i].TV_Y, y[i].NR,y[i].TV_Y7_FV, y[i].UR, y[i].PG, y[i].TV_G, y[i].G,y[i].TV_Y7);
    }
//************************parte 3********************************

    printf("********QUESTAO 3********\n\n");
     filmeporano();



//***********************parte 4*********************************
    struct topTen{  //estrutura para armazenar os 10 melhores de um certo ano.
        char Name[30];
        int ratingScore;
        int ano;
    };
    typedef struct topTen dezMelhores;
    dezMelhores Topten[10];     //cria-se 10 FILMES(nao 10 top 10, mas sim 10 filmes para se encaixar no top 10 de um ano)
    for(int year = 1940; year < 2018; year++){   //popula todos os filmes de um Topten do ano em questão.
        for(int i = 0; i < 10; i++){
        strcpy(Topten[i].Name, "NA");
        Topten[i].ratingScore = 0;
        Topten[i].ano = year;
        }
        i = 0;
        for(int j = 1; j < 1001; j++){
            if(atoi(filme[j].releaseYear) == year){ //checa se o filme[j] é do ano em questão
                if(strcmp(filme[j].title,Topten[0].Name) != 0 && strcmp(filme[j].title,Topten[1].Name) != 0 && strcmp(filme[j].title,Topten[2].Name) != 0 && strcmp(filme[j].title,Topten[3].Name) != 0 && strcmp(filme[j].title,Topten[4].Name) != 0 && strcmp(filme[j].title,Topten[5].Name) != 0 && strcmp(filme[j].title,Topten[6].Name) != 0 && strcmp(filme[j].title,Topten[7].Name) != 0 && strcmp(filme[j].title,Topten[8].Name) != 0 && strcmp(filme[j].title,Topten[9].Name) != 0) { //checa se a função recebe um filme repetido.
                    if(atoi((filme[j]).userRatingScore) >= Topten[i].ratingScore){ //checa se o filme em questão é maior que o último(que sempre é o maior que existia), ou seja, só pega os filmes que são maiores que os outros.
                        strcpy(Topten[i].Name, filme[j].title);
                        Topten[i].ratingScore = atoi(filme[j].userRatingScore);
                        i++;
                        if(i == 10){ //caso i chegue ao final de Topten, reseta ele.
                            i = 0;
                        }
                    }
                }
            }
        }

            for(i = 0; i < 10; i++){ //ordena os filmes do Topten do ano em questão
                for(int j = ( i + 1 ); j < 10; j++){
                    if(Topten[i].ratingScore < Topten[j].ratingScore){
                        int temp1;
                        temp1 = Topten[i].ratingScore;
                        Topten[i].ratingScore = Topten[j].ratingScore;
                        Topten[j].ratingScore = temp1;

                        char temp2[30];
                        strcpy(temp2,Topten[i].Name);
                        strcpy(Topten[i].Name, Topten[j].Name);
                        strcpy(Topten[j].Name,temp2);
                    }
                }
            }
        FILE *quest4; //cria e abre um arquivo
        quest4 = fopen("enunciado4.txt", "a");

        fprintf(quest4,"Ano : %d\n", year); //e finalmente, printa o topTen desse ano num txt.
        for(i = 0; i< 10; i++){
            fprintf(quest4, "  %s: %d\n", Topten[i].Name,Topten[i].ratingScore);

        }
        fclose(quest4);
    }


//************************parte 5 ************************************************
     printf("********QUESTAO 5********\n\n");
    //contar quantos possuem violence

    float quantidade = 0;
    int temp;
    char s[10] = "violence";
    for(int j = 0; j < 1001 ; j++){
            temp =  carac_cont( &filme[j].ratingLevel, &s);
            quantidade = quantidade + temp; //a quantidade de violence sobe caso a funcao perceba violence em uma das linhas entre 0 e 1000.
    }
    printf("A quantidade de vezes que violence aparece eh: %.1f \n e a sua porcentagem eh: %.1f porcento\n", quantidade, quantidade/10);



    //contar quantos possuem sexual content
    quantidade = 0;
    char t[20] = "sexual content";
    for(int j = 0; j <1001; j++){
        temp = carac_cont (&filme[j].ratingLevel, &t);
        quantidade = quantidade + temp;
    }
    printf("A quantidade de vezes que sexual content aparece eh: %.1f \n e a sua porcentagem eh:%.1f porcento\n", quantidade, quantidade/10);


    //contar quantos possuem violent
    quantidade = 0;
    char u[20] = "violent";
    for(int j = 0; j <1001; j++){
        temp = carac_cont (&filme[j].ratingLevel, &u);
        quantidade = quantidade + temp;
    }
    printf("A quantidade de vezes que violent aparece eh: %.1f \n e a sua porcentagem eh:%.1f porcento\n", quantidade, quantidade/10);



    // *********************** parte 6 ****************
     printf("********QUESTAO 6********\n\n");
    char procurar[100]; //procurar como chave da busca
    printf("Digite uma chave para a busca de um filme.A busca por chave eh rigida na questao de espacamento e letras maiusculas e minusculas.\n");
    scanf("%s", &procurar);

    busca_por_chave( &procurar );




    fclose(file);
    return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "IbraCo2018116025.h"

int capturaDia(char *data, int *cont);
int capturaMes(char *data,int *cont);
int capturaAno(char *data,int *cont);
int validaData(int di, int mi, int ai);
int qtdDiasMes(int mes, int ano);
int ehBissexto(int ano);

int q1(char *data){

    int datavalida=1;
    int di=0,mi=0,ai=0;
    int cont;

    //captura dia e converte em int
    di=capturaDia(data,&cont);

    //caputura mes e converte em int
    mi=capturaMes(data,&cont);

    //captura ano e converte em int
    ai=capturaAno(data,&cont);

    //valida data
    if(validaData(di,mi,ai)==1)
        return 1;
    else
        return 0;

}


int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos){


    int di,mi,ai,df,mf,af;
    int contI,countF;

    //calcule os dados e armazene nas trÃªs variÃ¡veis a seguir
    int nDias=0, nMeses=0, nAnos=0;


    //quebra a data inicial em dia,mes e ano do tipo inteiro
    di=capturaDia(datainicial,&contI);
    mi=capturaMes(datainicial,&contI);
    ai=capturaAno(datainicial,&contI);

    //quebra a data final em dia,mes e ano do tipo inteiro
    df=capturaDia(datafinal,&contI);
    mf=capturaMes(datafinal,&contI);
    af=capturaAno(datafinal,&contI);

    //verifica validade de data inicial
    if (q1(datainicial) == 0)
        return 2;

    //verifica validade de data final
    if (q1(datafinal) == 0)
        return 3;

    //verifica se a data incial Ã© anterior Ã  data final
    if (ai > af)
        return 4;
    else if(ai==af&&mi>mf)
        return 4;
    else if(ai==af&&mi==mf&&di>df)
        return 4;

    //calcula intervalo de tempo entre uma data e outra em dias, meses e anos.
    if(q1(datainicial)==1&&q1(datafinal)==1){

        if(df-di<0){
            nMeses--;
            nDias=(df-di) + qtdDiasMes(mf-1,af);
        }
        else
            nDias=df-di;


        if((mf-mi) + nMeses<0){
            nAnos--;
            nMeses=((mf-mi) + nMeses) + 12;
        }
        else
            nMeses=(mf-mi) + nMeses;


        if((af-ai) + nAnos<0){
            nAnos=((af-ai) + nAnos) + 1;
        }
        else
            nAnos=(af-ai) + nAnos;
    }

    //aloca o valor de dias, meses e anos no endereço de memória da variável correspondente
    /*mantenha o código abaixo, para salvar os dados em
    nos parâmetros da função
    */
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //retorno correspondente ao calculo correto da diferença de tempo entre as datas.
    return 1;

}

int q3(char str[250], char letra, int Case_Sensitive){

	int i, cont = 0;

	if(Case_Sensitive == 0){
	for(i = 0; str[i] != '\0'; i++)
	   if(( str[i] == letra ||  str[i] == letra + 32 || str[i] == letra - 32))
			cont++;


	} else if(Case_Sensitive == 1){
			for(i = 0; str[i] != '\0'; i++){
			if( str[i] == letra)
			cont++;
	}

}

		 return (cont);

}

int q4(char *strTexto, char *strBusca, int posicoes[30]){
    int qtdOcorrencias = 0;
    char intTexto[250];
    char intBusca[50];
    int i=0,z=0,j=0,k=0,l=0,count=0,tamBusca=0;
    int pInicial=0,pFinal=0;

    //captura texto sem o -61
    for(i=0;strTexto[i]!='\0';i++){
        if(strTexto[i]!=-61){
            intTexto[j]=strTexto[i];
            j++;
        }
    }
    intTexto[j]='\0';
    j=0;

    //captura busca sem o -61
     for(i=0;strBusca[i]!='\0';i++){
        if(strBusca[i]!=-61){
            intBusca[j]=strBusca[i];
            j++;
        }
    }
    tamBusca=j;
    intBusca[j]='\0';
    j=0;

    //busca palavra e posiÃ§Ãµefor(i=0;intTexto[i]!='\0';i++){
    for(i=0,j=0;intTexto[i]!='\0';i++){
        if(intTexto[i]==intBusca[j] || intTexto[i]==(intBusca[j]+32) || intTexto[i]==(intBusca[j]-32)){
            for(k=i,l=0;intBusca[l]!='\0';k++,l++){
                if(intTexto[k]==intBusca[l] || intTexto[k]==(intBusca[l]+32) || intTexto[k]==(intBusca[l]-32)){
                    count++;
                }
            }
            //valida condiÃ§Ã£o para armazenar posicoes e contar ocorrencia
            if(count==tamBusca){
                posicoes[z]=i+1;
                posicoes[z+1]=k;
                z+=2;
                qtdOcorrencias++;
            }
        }
        count=0;
    }
    //retorna quantidade de ocorrencias
    return qtdOcorrencias;
 }


int q5(int Numero_de_Entrada ){

    int Num;
    int Numero_Invertido;

    Num = Numero_de_Entrada;
    Numero_Invertido = 0;



	for( ; Numero_de_Entrada > 0; Numero_de_Entrada =  Numero_de_Entrada/10 ){
		Numero_Invertido = Numero_Invertido * 10;
		Numero_Invertido = Numero_Invertido + (Numero_de_Entrada % 10);
	}
	return Numero_Invertido;
}

int q6(int numerobase, int numerobusca){
    int qtdOcorrencias=0, aux=numerobusca, b;

    if(numerobase/10>0){

    	for(b=1;aux>0;aux/=10){
    		b*=10;
    	}

        for(b=b;numerobase>0;numerobase/=10){
            if ((numerobase%b)==numerobusca)
                qtdOcorrencias++;
        }
    }

    else if (numerobase==numerobusca)
        qtdOcorrencias=1;
    else
        qtdOcorrencias=0;

    return qtdOcorrencias;
}

int ehBissexto(int ano){
    if((ano%4==0&&ano%100!=0)||ano%400==0)
        return 1;
    else
        return 0;
}

int qtdDiasMes(int mes, int ano){

    if(mes==1)
        return 31;

    else if(mes==2){
        if(ehBissexto(ano)==1)
            return 29;
        else
            return 28;
    }

    else if(mes%2!=0){
        if(mes<8)
            return 31;
        else
            return 30;
    }

    else{
        if(mes<8)
            return 30;
        else
            return 31;
    }
}

int capturaDia(char *data, int *cont){
    char dd[3];
    int i;

    for(i=0;data[i]!='/';i++){
        dd[i]=data[i];
    }
    dd[i] = '\0';

    *cont=i;

    return atoi(dd);
}

int capturaMes(char *data,int *cont){
    char mm[3];
    int i,j=0;

    i=*cont+1;

    for(;data[i]!='/';i++,j++){
        mm[j]=data[i];
    }
    mm[j] = '\0';

    *cont=i;

    return atoi(mm);
}

int capturaAno(char *data,int* cont){

    char ano[5];
    int i,j=0;
    int ai;
    i=*cont+1;

    for(;data[i]!='\0';i++,j++){
        ano[j]=data[i];
    }
    ano[j] = '\0';

    *cont=i;

    ai=atoi(ano);

    if(ai<20)
        ai+=2000;

    return ai;
}



int validaData(int di, int mi, int ai){

    //valida data
    if(ai<19&&ai<2000)
        return 0;

    else if(mi<1||mi>12)
        return 0;

    else if(mi==1){
        if(di>0&&di<=31)
            return 1;
        else
            return 0;
    }

    else if(mi==2){

        if(di==29){
            if (ehBissexto(ai)==1)
                return 1;
            else
                return 0;
        }
        else if(di>0&&di<29)
            return 1;
        else
            return 0;
    }

    else if(mi%2==0){
        if(mi<8){
            if(di>0&&di<31)
                return 1;
            else
                return 0;
        }
        else{
            if(di>0&&di<=31)
                return 1;
            else
                return 0;
        }
    }
    else if(mi%2!=0){
        if(mi<8){
            if(di>0&&di<=31)
                return 1;
            else
                return 0;
        }
        else{
            if(di>0&&di<31)
                return 1;
            else
                return 0;
        }
    }
    else
        return 0;
}


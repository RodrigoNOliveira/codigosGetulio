#include <pthread.h> /* cria��o de threads */
#include <stdio.h>   /* impress�o na tela */
#include <stdlib.h>  /* biblioteca padr�o ( atoi ) */
#include <time.h>    /* para a semente aleat�ria */

typedef struct _dados {
	//int n; // limite inferior do intervalo
	//int m; // limite superior do intervalo
	
	double * conjunto;     // conjunto de dados
	int tamanho_conjunto;  // tamanho do conjunto
} Dados;

double * dummy( int n );
//void mostrar_primos(int m, int n);
//int qtd_divisores( int n );
double calc_media();
int soma( int x );
int maior( int x );
int menor( int x );

void *runner(void * param); /* o thread */

int main(int argc, char *argv[]){
	
	srand( time(NULL) ); // "semente" para gera��o de n�meros aleat�rios
	
	pthread_t tid;       /* o identificador do thread */
	pthread_attr_t attr; /* configura��o de atributos do thread */
	
	// ======================================
	// verifica��o dos parametros de entrada
	if (argc != 3) {
		fprintf(stderr,"usage: a.out <integer value> <integer value>\n argc=%d\n", argc);
		return 1024;
	}

	if (atoi(argv[1]) < 0) {
		fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[1]));
		return 2048;
	}

	/*if (atoi(argv[2]) < 0) {
		fprintf(stderr,"Argument %d must be non-negative\n",atoi(argv[2]));
		return 2096;
	}
	
	if (atoi(argv[1]) > atoi(argv[2])) {
		fprintf(stderr,"Argument %d must be less than or equal %d \n",atoi(argv[1]), atoi(argv[2]));
		return 2128;
	}*/
	// ======================================
	
	// prepara��o dos dados para a thread
	Dados * d = (Dados *) malloc( sizeof(Dados) );
	//d->n = atoi(argv[1]);
	//d->m = atoi(argv[2]);
	
	d->tamanho_conjunto = 20;
	d->conjunto = dummy( d->tamanho_conjunto );
	
	/* captura os atributos padr�o */
	pthread_attr_init(&attr);

	/* cria o thread */
	pthread_create(&tid,&attr,runner, (Dados *) d);

	/* agora espera o thread terminar */
	pthread_join(tid,NULL);

	printf("\nPrograma finalizado\n");
	
	free( d ); // libera��o do "pacote" de dados para a thread
	return 0;
}

/**
  * O thread assumir� o controle nessa fun��o
 */
void * runner(void * param) {
	
	Dados * x = (Dados *) param;
	
	//mostrar_primos(x->n, x->m);
	
	
	
	printf("A media dos valores: %g\n", calc_media());
	printf("O maior entre os valores: %d\n", maior());
	printf("O menor entre os valores: %d\n", menor());
	
	printf("Tamanho do conjunto: %d\n", x->tamanho_conjunto);
	int i = 0;
	for(i = 0; i < x->tamanho_conjunto; i++) {
		printf(" %g ", x->conjunto[i]);
	}
    
	pthread_exit(0);
}

/* 
 * mostra a sequencia de n�meros primos no intervalo [n, m]
 */
//void mostrar_primos(int m, int n) {
//	int i =0;
//	for( i = m; i <= n; i++) {
//		if ( qtd_divisores( i ) <= 2 ) {
//			printf(" %d ", i);
//		}
//	}	
//}

/**
 * retorna a quantidade de divisores de X
 */

double calc_media() {
	double result;
	result = soma()/x->tamanho_conjunto;
	return result;
}
 

 
int soma( int x ) {
	int soma;
	soma = soma + x;
	return s;
}
 
 
int maior( int x ) {
	int s;
	if (s < x){
		s = x;
	}
	return s;
}

int menor( int x ) {
	int r;
	if (r > x){
		r = x;
	}
	return r;
}

/**
 * gera dados aleatorios para testes
 */
double * dummy( int n ) {
	double * v = (double *) malloc( n * sizeof( double ) );
	int i;
	for(i = 0; i < n; i++) {
		v[i] = rand() % 100;
	}
	return v;
}

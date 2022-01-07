/*
FEITO NO SEGUNDO SEMESTRE DE 2016

Este projeto armazena os dados sobre computadores e celulares obtidos pelo usuário, e os armazena no 
arquivo "Dados da execução.txt" quando o usuário escolher a opção "Salvar e sair"

*/

#include<stdio.h>
#include<stdlib.h>
#include<strings.h>

void menu_computador(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void iniciar_pc(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void incluir_pc(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void editar_pc(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void remover_pc(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void index_pc(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);;
int all_index_pc(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);

void menu_celular(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void iniciar_cell(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void incluir_cell(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void editar_cell(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void remover_cell(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void index_cell(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
int all_index_cell(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);

void menu_raiz(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void salvar_sair(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
void ajuda(struct computador *data1, struct celular *data2, int num_pc, int num_cell, int value4);
typedef enum sistema_operacional {Windows, Linux, MAC}sistemaPC;		
typedef enum sistema_celular {Android, iPhone, WindownsPhone, Desconhecido}sistemaCell;

typedef struct computador
{
	char marca [20];
	int IP;
	int preco;
	enum sistema_operacional systempc;
	int save_state;
}Computador;

typedef struct celular
{
	char marca [20];
	int IP;
	int preco;
	enum sistema_celular systemcell;
	int save_state;
}Celular;
FILE * arq;

int main(int argc, char *argv[])
{
	int num_pc, num_cell, op;
	int gatekeeper;
	arq = fopen("Dados da execução.txt", "w");
	Computador *data1;
	Celular *data2;
	int cont, x, i, value1=0, value2=0, value3=0, value4=0, value5=0;
	if (argc<2) menu_raiz(data1, data2, num_pc, num_cell, value4);
	
	for (i=0;i<6;i++)
	{
		x = strcmp(argv[i], "/?");
		if (x == 0)
		{
			printf ("***Ajuda do programa***\nOs parametros sao os seguintes:");
	    	printf ("\n1. Quantidade de computadores;\n2. Quantidade de celulares;\n3. Menu dos computadores(1) ou Menu dos celulares(2);\n4. Funcao a ser executada (1 , 2, 3, 4, 5 ou 6 - Inicializar, Inserir, Editar, Remover, Listar por codigo, Listar tudo");	
			break;
		}
	}
	
	if (argc == 6)
	{
    	value1 = atoi(argv[1]);
	    value2 = atoi(argv[2]); 
	    value3 = atoi(argv[3]); 
	    value4 = atoi(argv[4]);
	    value5 = atoi(argv[5]);
	    printf ("\nVc digitou os paramentros:\nParametro 1=%d\nParametro 2=%d\nParametro 3=%d\nParametro 4=%d\nParametro 5=%d", value1, value2, value3, value4, value5);
	    getchar();
	}
	else 
	{
		printf("\nQuantidade de parametros invalidos. Para receber ajuda digite /?\n");
		return 0;
	}
	if(value1 <= 0 || value2 <= 0 ) gatekeeper = 1;
    else if(value3 != 1 && value3 != 2 && value3 != 3) gatekeeper = 1;
    else if(value3<=0 || value4 > 7) gatekeeper = 1;
    else gatekeeper = 0;
		
	if (gatekeeper == 1) printf("\nParametros invalidos. Para receber ajuda digite /?\n");
	else
	{
		num_pc = value1;
		num_cell = value2;
		op = value3;
	switch(op)
	{
	    case 1:
			system("cls");   	
	    	menu_computador(data1, data2, num_pc, num_cell, value4);
	    	break;
	    case 2:
	    	system("cls");
	    	menu_celular(data1, data2, num_pc, num_cell, value4);
	    	break;
	    case 3:
	    	system("cls");
			salvar_sair(data1, data2, num_pc, num_cell, value4);
	    	break;
	}
	}
	return 0;
}

void menu_raiz(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, op;
	do
	{
		printf("\nDetermine a quantidade de computadores: ");
		scanf("%d", &num_pc);
		fflush(stdin);
		if (num_pc>0)
		{
			
			data1 = (struct computador *) malloc(num_pc * sizeof(struct computador));
			printf("Quantidade determinada!!!");
		}
		else printf("Quantidade invalida!!!");
	}while(num_pc<=0);
	do
	{
		printf("\nDetermine a quantidade de celulares: ");
		scanf("%d", &num_cell);
		fflush(stdin);
		if (num_cell>0)
		{
			data2 = (struct celular *) malloc(num_cell * sizeof(struct celular));
			printf("Quantidade determinada!!!");
		}
		else printf("Quantidade invalida!!!");
	}while(num_cell<=0);
	
	
		
	printf("\n***Menu Raiz***\n1-Menu dos Computadores\n2-Menu dos celulares\n3-Sair\n4-Ajuda");
	scanf("%d", &op);
	fflush(stdin);
	switch(op){
	    case 1:
			system("cls");   	
	    	menu_computador(data1, data2, num_pc, num_cell, value4);
	    	break;
	    case 2:
	    	system("cls");
	    	menu_celular(data1, data2, num_pc, num_cell, value4);
	    	break;
	    case 3:
	    	system("cls");
			salvar_sair(data1, data2, num_pc, num_cell, value4);
	    	break;
	    case 4:
	    	ajuda(data1, data2, num_pc, num_cell, value4);
	    	break;
	}
}

void menu_computador(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	printf("\n***Menu dos Computadores***\nEscolha uma das opcoes:\n1-Inicializar (Iniciar ou Resetar)\n2-Inserir\n3-Editar\n4-Remover\n5-Listar por codigo\n6-Listar tudo\n7-Sair\n");
	scanf("%d", &value4);
	fflush(stdin);
	switch (value4)
	{
		case 1:
			iniciar_pc(data1, data2, num_pc, num_cell, value4);
			break;
		case 2:
			incluir_pc(data1, data2, num_pc, num_cell, value4);
			break;
		case 3:
			editar_pc(data1, data2, num_pc, num_cell, value4);
			break;
		case 4:
			remover_pc(data1, data2, num_pc, num_cell, value4);
			break;
		case 5:
			index_pc(data1, data2, num_pc, num_cell, value4);
			break;
		case 6:
			all_index_pc(data1, data2, num_pc, num_cell, value4);
			break;
		case 7:
			salvar_sair(data1, data2, num_pc, num_cell, value4);
			break;
		default:
			system("cls");
			printf("\nOpcao invalida!");
			menu_computador(data1, data2, num_pc, num_cell, value4);
			break;
	}
}

void iniciar_pc(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i;
	for (i=0;i<num_pc;i++) data1[i].save_state = 0;
	system ("cls");
	printf("\nMemoria iniciada");
	menu_computador(data1, data2, num_pc, num_cell, value4);
}
void incluir_pc(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, j, x, k;
	j = 1;
	x = num_pc;
	x--;
	system ("cls");
	for (i=0, j=1;j == 1;i++)
	{
		for (k=0; k<num_pc;k++)
		{
			if (data1[i].save_state == 1) j=0;
		}
	if(data1[i].save_state == 0 && j ==1)
	{
		printf("\nDigite a marca do computador: ");
		gets(data1[i].marca);
		printf("\nDigite o numero de IP: ");
		scanf("%d", &data1[i].IP);
		fflush(stdin);
		printf("\nDigite o preco do computador: ");
		scanf("%d", &data1[i].preco);
		fflush(stdin);
		printf("\nInforme o sistema operacional do computador: (0=Windowns / 1=Linux / 2=MAC)");
		scanf("%d", &data1[i].systempc);
		fflush(stdin);
		data1[i].save_state = 1;
		printf("\nCadastro realizado!\nDeseja adicionar mais um computador? (1=Sim / 0=Nao)");
		scanf("%d", &j);
		fflush(stdin);
		if (i == x && j ==1)
		{
			printf("\nMemoria insuficiente. Ja foi incluido %d computadores.\nPrecione enter para continuar.", num_pc);
			getchar();
			j = 0;
		}
		system ("cls");
	}
	}
	menu_computador(data1, data2, num_pc, num_cell, value4);
}
void editar_pc(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, j, x, y;
	system ("cls");
	printf("\nQual o numero de IP do computador que deseja editar?");
	scanf("%d", &x);
	fflush(stdin);
	for (i=0;i<num_pc;i++)
	{
		if (data1[i].IP == x && data1[i].save_state == 1)
		{
		printf("\nMarca do computador: "); puts(data1[i].marca);
		printf("\nDigite a nova marca do computador: ");
		gets(data1[i].marca);
		
		printf("IP do computador: %d", data1[i].IP);
		printf("\nDigite o novo numero de IP: ");
		scanf("%d", &data1[i].IP);
		fflush(stdin);
		printf("\nPreco do computador: %d", data1[i].preco); 
		printf("\nDigite o novo preco do computador: ");
		scanf("%d", &data1[i].preco);
		fflush(stdin);
		
		if (data1[i].systempc == 0) printf("\nSistema Operacional do computador: Windows");
		else if (data1[i].systempc == 1) printf("\nSistema Operacional do computador: Linux");
		else printf("\nSistema Operacional do computador: MAC");
		printf("\nInforme o novo sistema operacional do computador: (0=Windowns / 1=Linux / 2=MAC)");
		scanf("%d", &data1[i].systempc);
		fflush(stdin);
		data1[i].save_state = 1;
		j = 1;
		printf("\nDeseja editar outro arquivo? (1=sim / 0=nao)");
		scanf("%d", &y);
		fflush(stdin);
		if (y == 1) index_pc(data1, data2, num_pc, num_cell, value4);
		else 
		{
			menu_computador(data1, data2, num_pc, num_cell, value4);
			system ("cls");
		}
		}
	}
	if (j==0)
	{
		printf("\nNumero de IP nao encontrado \n(0=Sair / 1=Continuar a busca)");
		scanf ("%d", &j);
		fflush(stdin);
		if (j == 1) editar_pc(data1, data2, num_pc, num_cell, value4);
		else menu_computador(data1, data2, num_pc, num_cell, value4);
	}
}

void remover_pc(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int x, i, j;
	system ("cls");
	printf ("\nDigite o numero de IP para remover o cadastro");
	scanf("%d", &x);
	fflush(stdin);
	j=0;
	for (i=0;i<num_pc;i++)
	{
		if (data1[i].IP == x)
		{
			data1[i].save_state = 0;
			printf("O computador da marca "); puts(data1[i].marca); printf("foi removido\n");
			j=1;
		}
	}
	if (j==0) printf("O computador com o IP %d não existe!", x);
	printf("\nDigite 1 para continuar ou 0 para voltar ao menu\t");
	scanf ("%d", &i);
	fflush(stdin);
	if (i == 1) remover_pc (data1, data2, num_pc, num_cell, value4);
	system ("cls");
	menu_computador(data1, data2, num_pc, num_cell, value4);
}
void index_pc(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, j, x, y;
	system ("cls");
	printf("\nQual o numero de IP do computador que deseja consultar?");
	scanf("%d", &x);
	fflush(stdin);
	for (i=0;i<num_pc;i++)
	{
		if (data1[i].IP == x && data1[i].save_state == 1)
		{
			printf("\nComputador: "); puts(data1[i].marca);
			printf("IP: %d", data1[i].IP); 
			printf("\nPreco: %d", data1[i].preco); 
			if (data1[i].systempc == 0) printf("\nSistema Operacional: Windows");
			else if (data1[i].systempc == 1) printf("\nSistema Operacional: Linux");
			else printf("\nSistema Operacional: MAC");
			j = 1;
			printf("\nDeseja fazer outra consulta? (1=sim / 0=nao)");
			scanf("%d", &y);
			fflush(stdin);
			if (y == 1) index_pc(data1, data2, num_pc, num_cell, value4);
			else 
			{
				menu_computador(data1, data2, num_pc, num_cell, value4);
				system ("cls");
			}
		}
	}
	if (j==0)
	{
		printf("\nNumero de IP nao encontrado \n(0=Sair / 1=Continuar a busca)");
		scanf ("%d", &j);
		fflush(stdin);
		if (j == 1) index_pc(data1, data2, num_pc, num_cell, value4);
		else menu_computador(data1, data2, num_pc, num_cell, value4);
	}
}

int all_index_pc(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i;
	system ("cls");
	for (i=0; i<num_pc; i++)
	{
		if (data1[i].save_state == 1)
		{
			printf("\nComputador: "); puts(data1[i].marca);
			printf("IP: %d", data1[i].IP);
			printf("\nPreco: %d", data1[i].preco);
			if (data1[i].systempc == 0) printf("\nSistema Operacional: Windows");
			else if (data1[i].systempc == 1) printf("\nSistema Operacional: Linux");
			else printf("\nSistema Operacional: MAC");
		}
	}
	printf("\nDigite enter para voltar ao menu dos computadores");
	getchar();
	system("cls");
	menu_computador(data1, data2, num_pc, num_cell, value4);
	return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu_celular(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	printf("\n***Menu dos Celulares***\nEscolha uma das opcoes:\n1-Inicializar (Iniciar ou Resetar)\n2-Inserir\n3-Editar\n4-Remover\n5-Listar por codigo\n6-Listar tudo\n7-Sair\n");
	scanf("%d", &value4);
	fflush(stdin);
	switch (value4)
	{
		case 1:
			iniciar_cell(data1, data2, num_pc, num_cell, value4);
			break;
		case 2:
			incluir_cell(data1, data2, num_pc, num_cell, value4);
			break;
		case 3:
			editar_cell(data1, data2, num_pc, num_cell, value4);
			break;
		case 4:
			remover_cell(data1, data2, num_pc, num_cell, value4);
			break;
		case 5:
			index_cell(data1, data2, num_pc, num_cell, value4);
			break;
		case 6:
			all_index_cell(data1, data2, num_pc, num_cell, value4);
			break;
		case 7:
			salvar_sair(data1, data2, num_pc, num_cell, value4);
			break;
		default:
			system("cls");
			printf("\nOpcao invalida!");
			menu_celular(data1, data2, num_pc, num_cell, value4);
			break;
	}
}

void iniciar_cell(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i;
	for (i=0;i<num_cell;i++) data2[i].save_state = 0;
	system ("cls");
	printf("\nMemoria iniciada");
	menu_celular(data1, data2, num_pc, num_cell, value4);
}
void incluir_cell(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, j, x, k;
	j = 1;
	x = num_cell;
	x--;
	system ("cls");
	for (i=0, j=1;j == 1;i++)
	{
		for (k=0; k<num_cell;k++)
		{
			if (data2[i].save_state == 1) j=0;
		}
	if(data2[i].save_state == 0 && j ==1)
	{
		printf("\nDigite a marca do celular: ");
		gets(data2[i].marca);
		printf("\nDigite o numero de IP: ");
		scanf("%d", &data2[i].IP);
		fflush(stdin);
		printf("\nDigite o preco do celular: ");
		scanf("%d", &data2[i].preco);
		fflush(stdin);
		printf("\nInforme o sistema operacional do celular: (0=Android / 1=iPhone / 2=WindownsPhone / 3=Desconhecido)");
		scanf("%d", &data2[i].systemcell);
		fflush(stdin);
		data2[i].save_state = 1;
		printf("\nCadastro realizado!\nDeseja adicionar mais um celular? (1=Sim / 0=Nao)");
		scanf("%d", &j);
		fflush(stdin);
		if (i == x && j ==1)
		{
			printf("\nMemoria insuficiente. Ja foi incluido %d celulares.\nPrecione enter para continuar.", num_cell);
			getchar();
			j = 0;
		}
		system ("cls");
	}
	}
	menu_celular(data1, data2, num_pc, num_cell, value4);
}
void editar_cell(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, j, x, y;
	system ("cls");
	printf("\nQual o numero de IP do celular que deseja editar?");
	scanf("%d", &x);
	fflush(stdin);
	for (i=0;i<num_cell;i++)
	{
		if (data2[i].IP == x && data2[i].save_state == 1)
		{
		printf("\nMarca do celular: "); puts(data2[i].marca);
		printf("\nDigite a nova marca do celular: ");
		gets(data2[i].marca);
		
		printf("IP do celular: %d", data2[i].IP);
		printf("\nDigite o novo numero de IP: ");
		scanf("%d", &data2[i].IP);
		fflush(stdin);
		printf("\nPreco do celular: %d", data2[i].preco); 
		printf("\nDigite o novo preco do celular: ");
		scanf("%d", &data2[i].preco);
		fflush(stdin);
		if (data2[i].systemcell == 0) printf("\nSistema Operacional do celular: Android");
		else if (data2[i].systemcell == 1) printf("\nSistema Operacional do celular: iPhone");
		else if (data2[i].systemcell == 2) printf("\nSistema Operacional do celular: WindownsPhone");
		else printf("\nSistema Operacional do celular: Desconhecido");
		printf("\nInforme o novo sistema operacional do celular: (0=Android / 1=iPhone / 2=WindownsPhone / 3=Desconhecido)");
		scanf("%d", &data2[i].systemcell);
		fflush(stdin);
		data2[i].save_state = 1;
		j = 1;
		printf("\nDeseja editar outro arquivo? (1=sim / 0=nao)");
		scanf("%d", &y);
		fflush(stdin);
		if (y == 1) index_cell(data1, data2, num_pc, num_cell, value4);
		else 
		{
			menu_celular(data1, data2, num_pc, num_cell, value4);
			system ("cls");
		}
		}
	}
	if (j==0)
	{
		printf("\nNumero de IP nao encontrado \n(0=Sair / 1=Continuar a busca)");
		scanf ("%d", &j);
		fflush(stdin);
		if (j == 1) editar_cell(data1, data2, num_pc, num_cell, value4);
		else menu_celular(data1, data2, num_pc, num_cell, value4);
	}
}

void remover_cell(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int x, i, j;
	system ("cls");
	printf ("\nDigite o numero de IP para remover o cadastro");
	scanf("%d", &x);
	fflush(stdin);
	j=0;
	for (i=0;i<num_cell;i++)
	{
		if (data2[i].IP == x)
		{
			data2[i].save_state = 0;
			printf("O celular da marca "); puts(data2[i].marca); printf("foi removido\n");
			j=1;
		}
	}
	if (j==0) printf("O celular com o IP %d não existe!", x);
	printf("\nDigite 1 para continuar ou 0 para voltar ao menu\t");
	scanf ("%d", &i);
	fflush(stdin);
	if (i == 1) remover_cell (data1, data2, num_pc, num_cell, value4);
	system ("cls");
	menu_celular(data1, data2, num_pc, num_cell, value4);
}
void index_cell(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, j, x, y;
	system ("cls");
	printf("\nQual o numero de IP do que deseja consultar?");
	scanf("%d", &x);
	fflush(stdin);
	for (i=0;i<num_cell;i++)
	{
		if (data2[i].IP == x && data2[i].save_state == 1)
		{
			printf("\ncelular: "); puts(data2[i].marca);
			printf("IP: %d", data2[i].IP); 
			printf("\nPreco: %d", data2[i].preco); 
			if (data2[i].systemcell == 0) printf("\nSistema Operacional do celular: Android");
			else if (data2[i].systemcell == 1) printf("\nSistema Operacional do celular: iPhone");
			else if (data2[i].systemcell == 2) printf("\nSistema Operacional do celular: WindownsPhone");
			else printf("\nSistema Operacional do celular: Desconhecido");
			j = 1;
			printf("\nDeseja fazer outra consulta? (1=sim / 0=nao)");
			scanf("%d", &y);
			fflush(stdin);
			if (y == 1) index_cell(data1, data2, num_pc, num_cell, value4);
			else 
			{
				menu_celular(data1, data2, num_pc, num_cell, value4);
				system ("cls");
			}
		}
	}
	if (j==0)
	{
		printf("\nNumero de IP nao encontrado \n(0=Sair / 1=Continuar a busca)");
		scanf ("%d", &j);
		fflush(stdin);
		if (j == 1) index_cell(data1, data2, num_pc, num_cell, value4);
		else menu_celular(data1, data2, num_pc, num_cell, value4);
	}
}

int all_index_cell(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i;
	system ("cls");
	for (i=0; i<num_cell; i++)
	{
		if (data2[i].save_state == 1)
		{
			printf("\ncelular: "); puts(data2[i].marca);
			printf("IP: %d", data2[i].IP);
			printf("\nPreco: %d", data2[i].preco);
			if (data2[i].systemcell == 0) printf("\nSistema Operacional do celular: Android");
			else if (data2[i].systemcell == 1) printf("\nSistema Operacional do celular: iPhone");
			else if (data2[i].systemcell == 2) printf("\nSistema Operacional do celular: WindownsPhone");
			else printf("\nSistema Operacional do celular: Desconhecido");
		}
	}
	printf("\nDigite enter para voltar ao menu dos celulares");
	getchar();
	system("cls");
	menu_celular(data1, data2, num_pc, num_cell, value4);
	return 0;
}

void salvar_sair(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	int i, x;
	system("cls");
	printf("Escolha sua opcao:\n1-Voltar ao menu dos computadores\n2-Voltar ao menu dos celulares\n3-Salvar e sair\n4-Ajuda");
	scanf("%d", &x);
	fflush(stdin);
	switch (x)
	{
		case 1:
			system("cls");
			menu_computador(data1, data2, num_pc, num_cell, value4);
			break;
		case 2:
			system("cls");
			menu_celular(data1, data2, num_pc, num_cell, value4);
			break;
		case 3:
			for (i=0; i<num_pc; i++)
				{
					if (data1[i].save_state == 1)
					{
					fprintf(arq,"\n\n1-Marca do computador: %s\n2-IP do computador: %d\n3-Preco do computador: %d", data1[i].marca, data1[i].IP, data1[i].preco);
					if (data1[i].systempc == 0) fprintf(arq,"\n4-Sistema operacional do computador: Windows");
					else if (data1[i].systempc == 1) fprintf(arq,"\n4-Sistema operacional do computador: Linux");
					else fprintf(arq,"\n4-Sistema operacional do computador: MAC");
					}
				}
			for (i=0; i<num_cell; i++)
				{
					if (data2[i].save_state == 1)
					{
					fprintf(arq,"\n\n1-Marca do celular: %s\n2-IP do celular: %d\n3-Preco do celular: %d", data2[i].marca, data2[i].IP, data2[i].preco);
					if (data2[i].systemcell == 0) fprintf(arq,"\n4-Sistema operacional do celular: Android");
					else if (data2[i].systemcell == 1) fprintf(arq,"\n4-Sistema operacional do celular: iPhone");
					else if (data2[i].systemcell == 2) fprintf(arq,"\n4-Sistema operacional do celular: Windows Phone");
					else fprintf(arq,"\n4-Sistema operacional do computador: Desconhecido");
					}
				}
			fprintf(arq,"\nQuantidade de computadores: %d\nQuantidade de celulares: %d", num_pc,num_cell);
			break;
		case 4:
			ajuda(data1, data2, num_pc, num_cell, value4);
			break;
	}
	
	if (x!=1 && x!=2 && x!=3 && x!=4)
	{
		printf("Comando Invalido! Precione enter para continuar.");
		getchar();
		salvar_sair(data1, data2, num_pc, num_cell, value4);
	}
	exit(0);
}
void ajuda(Computador *data1, Celular *data2, int num_pc, int num_cell, int value4)
{
	system("cls");
	printf ("***Ajuda do programa***\nOs parametros sao os seguintes:");
	printf ("\n1. Quantidade de computadores;\n2. Quantidade de celulares;\n3. Menu dos computadores(1) ou Menu dos celulares(2);\n4. Funcao a ser executada (1 , 2, 3, 4, 5 ou 6 - Inicializar, Inserir, Editar, Remover, Listar por codigo, Listar tudo");
	getchar();
	salvar_sair(data1, data2, num_pc, num_cell, value4);
}

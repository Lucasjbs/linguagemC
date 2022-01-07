/*
	FEITO NO PRIMEIRO SEMESTRE DE 2018 (3° Período)
Este programa ler o arquivo salvo ("palavras.dat") e fornecer mecanismos para o usuário pesquisar as palavras que ele desejar.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <assert.h>


typedef struct PALAVRA{
    char palavra[50];
    int vez;
    struct PALAVRA *prox;
}Palav;

struct avl_node_s
{
	struct avl_node_s *left;
	struct avl_node_s *right;
	char data[50];
	int ocorrencias;
};
typedef struct avl_node_s avl_node_t;

struct avl_tree_s
{
	struct avl_node_s *root;
};
typedef struct avl_tree_s avl_tree_t;

void avl_insert( avl_tree_t *tree, char value[50], int qtd);
void avl_balance( avl_tree_t *tree );

avl_node_t *avl_balance_node( avl_node_t *node );
int avl_balance_factor( avl_node_t *node );
int avl_node_height( avl_node_t *node );
avl_node_t *avl_rotate_leftright( avl_node_t *node );
avl_node_t *avl_rotate_leftleft( avl_node_t *node );
avl_node_t *avl_rotate_rightleft( avl_node_t *node );
avl_node_t *avl_rotate_rightright( avl_node_t *node );
void avl_traverse_node_dfs( avl_node_t *node,  char value[50]);
void lerBin(avl_tree_t *tree);

int main()
{
	avl_tree_t *tree = NULL;
    char palavra[50], flag;


	if( ( tree = malloc( sizeof( avl_tree_t ) ) ) == NULL ) tree = NULL;
	tree->root = NULL;
    lerBin(tree);

    while( 1 ){

        printf("Insira a palavra a ser pesquisada : ");
        scanf("%s",palavra);
        fflush(stdin);
        avl_traverse_node_dfs(tree->root, palavra);

        printf("Deseja continuar com a pesquisa ? S ou N\n");
        scanf("%c",&flag);
        fflush(stdin);

        if( tolower(flag) == 's' ){}
        else if( tolower(flag) == 'n' ){ break; }
        else{
            while( tolower(flag) != 's' && tolower(flag) != 'n' ){
                printf("Comando Invalido!!\n");
                scanf("%c",&flag);
                fflush(stdin);
            }
            if( tolower(flag) == 'n' ) break;
        }

    }
    printf("Deseja pesquisar em algum outro arquivo ? S ou N\n");
    scanf("%c",&flag);
    fflush(stdin);

    if( tolower(flag) == 's' ){ main(); }
        else if( tolower(flag) == 'n' ){  }
        else{
            while( tolower(flag) != 's' && tolower(flag) != 'n' ){
                printf("Comando Invalido!!\n");
                scanf("%c",&flag);
                fflush(stdin);
            }
            if( tolower(flag) == 's' ) main();
        }

	return 0;
}

void lerBin( avl_tree_t *tree){
    FILE *file;
    Palav aux;
    char diretorio[50] = "\0";

    printf("Insira o nome do arquivo binario a ser pesquisado : ");
    scanf("%s",diretorio);
    fflush(stdin);

    if( (file = fopen(diretorio,"r+b")) == NULL ){
        printf("\nImpossivel abrir o arquivo!!\n\n"); fclose(file); main(); return;
    }

    while( fread(&aux,sizeof(Palav),1,file) ){
        //printf("palavra : %s\n",aux.palavra);
        avl_insert(tree,aux.palavra,aux.vez);
        if( feof(file) ) break;
    }

    fclose(file);
}


void avl_insert( avl_tree_t *tree, char value[50], int qtd)
{
	avl_node_t *node = NULL;
	avl_node_t *next = NULL;
	avl_node_t *last = NULL;

	if( tree->root == NULL )
	{
		if( ( node = malloc( sizeof( avl_node_t ) ) ) == NULL )
			{
				node = NULL;
				exit(1);
			}
		node->left = NULL;
		node->right = NULL;
		strcpy(node->data, value);
		tree->root = node;
		node->ocorrencias = qtd;
	}
	else
	{
		next = tree->root;
		while( next != NULL)
		{
			last = next;
			if( strcmp(value, next->data) < 0)next = next->left;
			else if( strcmp(value, next->data) > 0 ) next = next->right;
			else if( strcmp(next->data, value) == 0 ) exit(1);
		}
		if( ( node = malloc( sizeof( avl_node_t ) ) ) == NULL )
			{
				node = NULL;
				exit(1);
			}
		node->left = NULL;
		node->right = NULL;
		strcpy(node->data, value);
		node->ocorrencias = qtd;
		if( strcmp(value, last->data) < 0 ) last->left = node;
		if( strcmp(value, last->data) > 0 ) last->right = node;
	}
	avl_balance( tree );
}

void avl_balance( avl_tree_t *tree )
{
	avl_node_t *newroot = NULL;
	newroot = avl_balance_node( tree->root );
	if( newroot != tree->root )  tree->root = newroot;
}
avl_node_t *avl_balance_node( avl_node_t *node )
{
	avl_node_t *newroot = NULL;
	if( node->left ) node->left  = avl_balance_node( node->left  );
	if( node->right ) node->right = avl_balance_node( node->right );
	int bf = avl_balance_factor( node );

	if( bf >= 2 ) {
		if( avl_balance_factor( node->left ) <= -1 ) newroot = avl_rotate_leftright( node );
		else newroot = avl_rotate_leftleft( node );
	}
	else if( bf <= -2 ) {
		if( avl_balance_factor( node->right ) >= 1 ) newroot = avl_rotate_rightleft( node );
		else newroot = avl_rotate_rightright( node );

	}
	else newroot = node;
	return( newroot );
}


//FUNÇÕES DA ÁRVORE AVL:
int avl_balance_factor( avl_node_t *node )
{
	int bf = 0;
	if( node->left  ) bf += avl_node_height( node->left );
	if( node->right ) bf -= avl_node_height( node->right );
	return bf ;
}
int avl_node_height( avl_node_t *node )
{
	int height_left = 0;
	int height_right = 0;
	if( node->left ) height_left = avl_node_height( node->left );
	if( node->right ) height_right = avl_node_height( node->right );
	return height_right > height_left ? ++height_right : ++height_left;
}
avl_node_t *avl_rotate_leftright( avl_node_t *node )
{
	avl_node_t *a = node;
	avl_node_t *b = a->left;
	avl_node_t *c = b->right;

	a->left = c->right;
	b->right = c->left;
	c->left = b;
	c->right = a;

	return( c );
}
avl_node_t *avl_rotate_leftleft( avl_node_t *node )
{
 	avl_node_t *a = node;
	avl_node_t *b = a->left;

	a->left = b->right;
	b->right = a;

	return( b );
}
avl_node_t *avl_rotate_rightleft( avl_node_t *node )
{
	avl_node_t *a = node;
	avl_node_t *b = a->right;
	avl_node_t *c = b->left;

	a->right = c->left;
	b->left = c->right;
	c->right = b;
	c->left = a;

	return( c );
}
avl_node_t *avl_rotate_rightright( avl_node_t *node )
{
	avl_node_t *a = node;
	avl_node_t *b = a->right;

	a->right = b->left;
	b->left = a;

	return( b );
}

void avl_traverse_node_dfs( avl_node_t *node,  char value[50] )
{
	if (strcmp (node->data, value) == 0) printf("\nPalavra : %s \nOcorrencias : %d vezes\n\n", node->data, node->ocorrencias);

	if( node->left ) avl_traverse_node_dfs( node->left, value);
	if( node->right ) avl_traverse_node_dfs( node->right, value);
}

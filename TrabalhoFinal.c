/* 
Desenvolva um programa que contenha uma matriz 6x6 de inteiros. O programa dever� solicitar ao usu�rio a digita��o dos 36 n�meros. Na sequ�ncia, o programa dever� varrer a matriz e fazer as seguintes altera��es:
 a-) se o n�mero for par, acrescentar ao seu valor 4;
 b-) se o n�mero for �mpar, acrescentar ao seu valor 1; 
 c-) se a matriz tiver o n�mero 10, dever� ser substitu�do por 15;
 d-) se a matriz tiver o n�mero 17, dever� ser substitu�do por 12;
 e-) quantos n�meros pares e �mpares tinham antes da altera��o;
 f-) quantos n�meros pares e �mpares tinham ap�s a altera��o.
 */
#include <stdio.h>
int i, x, j;
int pa, ia, pd, id;
int main()
{
int mat [i][j];
printf("Digite 36 numeros \n");
	for (i=0;i<6;i++)
	{
		for(j=0;j<6;j++)
		{
			scanf("%d", &mat[i][j]);
			if (mat[i][j] % 2 == 0)
			{
				pa = pa + 1;
			}
			else if (mat[i][j] % 2 == 1)
			{
				ia = ia + 1;;	
			}
			if (mat[i][j] == 10)
			{
				mat[i][j] = 15;
			}
			else if (mat[i][j] == 17)
			{
				mat[i][j] = 12;	
			}
			else if (mat[i][j] % 2 == 0)
			{
				mat[i][j] = mat[i][j] + 4;
			}
			else if (mat[i][j] % 2 == 1)
			{
				mat[i][j] = mat[i][j] + 1;	
			}
			if (mat[i][j] % 2 == 0)
			{
				pd = pd + 1;
			}
			else if (mat[i][j] % 2 == 1)
			{
				id = id + 1;;	
			}
			printf("A coordenada do numero eh %d %d, e o valor final do numero eh %d \n", i, j, mat[i][j]);			
		}
		
	}
	
	printf("A quantidade de numeros pares digitados antes da alteracao foi %d \n", pa);
	printf("A quantidade de numeros impares digitados antes da alteracao foi %d \n", ia);
	printf("A quantidade de numeros pares digitados depois da alteracao foi %d \n", pd);
	printf("A quantidade de numeros impares digitados depois da alteracao foi %d \n", id);
	return 0;
}



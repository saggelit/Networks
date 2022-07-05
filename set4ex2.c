#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 1000 //komboi
#define k 14000 //synolo syndeswn
#define p 0.2 //pithanothta

int main()
{
  int i,j,l,m,node;
  double num;
  srand(4366);

  FILE *datadelta;
  datadelta=fopen("net2delta.txt","w");
  FILE *data;
  data=fopen("net2.txt","w");

  int *links=malloc(N*sizeof(int));
  for (i=0;i<N;i++) links[i]=0;
  int (*network)[N]=malloc(sizeof(int[N][N]));
  for (i=0;i<N;i++)
    {
      for (j=0;j<N;j++)
	{
	  network[i][j]=0;
	}
    }

  for (i=0;i<N-1;i++)
    {
      for (j=i+1;j<N;j++)
	{
	  if (j<=i+k/N/2) // gia syndesh dexia
	    {
	      network[i][j]=1;
	      //network[j][i]=1; //gia ton katw symmetriko
	      links[i]++;
	      links[j]++;
	    }
	  else if (j>=i+N-k/N/2)  // gia syndesh aristera
	    {
	      network[i][j]=1;
	      //network[j][i]=1; //gia ton katw symmetriko
	      links[i]++;
	      links[j]++;
	    }
	}
    }
  /*  //Gia na dw to arxiko plegma
  for (i=0;i<N;i++)
    {
      for (j=0;j<N;j++)
	{
	  printf("%d ",network[i][j]);
	}
      printf("\n");
    }
  printf("\n");
  */

  for (i=0;i<N;i++)
    {
      fprintf(datadelta,"%d\n",links[i]);
    }
  
  for (i=0;i<N-1;i++)
    {
      for (j=i+1;j<N;j++)
	if (network[i][j]==1)
	{
	  num=1.0*rand()/RAND_MAX;
	  if (num<=p)
	    {
	      do
		{
		  node=rand()%N;
		}
	      while (node==i || node==j);
	      network[i][j]=0;
	      //network[j][i]=0; //gia ton katw symmetriko //Gt de mpainoyn swsta oi komboi?
	      if (i<node) network[i][node]=1;
	      else network[node][i]=1;
	      //network[node][i]=1; //gia ton katw symmetriko
	      links[node]++;
	      links[j]--;
	    }
	}
    }
  
  /*
  for (i=0;i<N;i++)
    {
      for (j=0;j<N;j++)
	{
	  printf("%d ",network[i][j]);
	}
      printf("\n");
    }
  printf("\n");
  */

  for (i=0;i<N;i++) fprintf(data,"%d\n",links[i]);

  fclose(datadelta);
  fclose(data);
  free(network);
  free(links);
}

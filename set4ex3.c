#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000 //nodes
#define run 3 //runs

double y(double g,double ymin, double ymax, double x)
{
  return pow((pow(ymax,1-g)-pow(ymin,1-g))*x+pow(ymin,1-g),1/(1-g));
}

int main()
{
  int r,i,j;
  double g,x,ymin=1.0,ymax=N-1.0;
  srand(4366);

  double gamma[run]={2.0,2.5,3.0};
  
  FILE *data;
  FILE *datad;
  for (r=0;r<run;r++)
    {
      g=gamma[r];
      
      if (g==2.0) data=fopen("net3kgamma2.0.txt","w");
      else if (g==2.5) data=fopen("net3kgamma2.5.txt","w");
      else data=fopen("net3kgamma3.0.txt","w"); //epilogh arxeiou

      int *k=malloc(N*sizeof(int)); //Edges' matrix for every node
      for (i=0;i<N;i++) k[i]=0;

      for (i=0;i<N;i++)
	{
	  x=1.0*rand()/RAND_MAX;
	  k[i]=floor(y(g,ymin,ymax,x));
	  fprintf(data,"%d\t%d\n",i,k[i]);
	}

      int kmax=0;
      for (i=0;i<N;i++)
	{
	  if (k[i]>kmax)
	    kmax=k[i];
	}
      kmax=kmax+1;
      int *distribution=malloc(kmax*sizeof(int));

      for (i=0;i<kmax;i++)
	distribution[i]=0; //Initialization

      for (i=0;i<N;i++)
	distribution[k[i]]++ ;

      if (g==2.0) datad=fopen("net3kgamma2.0D.txt","w");
      else if (g==2.5) datad=fopen("net3kgamma2.5D.txt","w");
      else datad=fopen("net3kgamma3.0D.txt","w"); //epilogh arxeiou
	

      for (i=0;i<kmax;i++)
	{fprintf(datad,"%d\t%d\n",i+1,distribution[i]);}
  
      
      fclose(data);
      fclose(datad);
      free(distribution);
      free(k);
    }
}

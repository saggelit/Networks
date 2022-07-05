#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 10000 //komboi 1000 kai 10000
#define p 1.0/6 //pithanothta
#define run 1000 //plhthos prosomoiwsewn


int main()
{
  int i,j,n,kmax;
  double num;
  srand(4366);
  
  FILE *datak;
  FILE *datad;
  if (N==1000)
    {
      datak=fopen("net1k1000.txt","w");
      datad=fopen("net1d1000.txt","w");
    }
  else
    {
      datak=fopen("net1k10000.txt","w");
      datad=fopen("net1d10000.txt","w");
    }
  
  int *k=malloc(N*sizeof(int)); //pinakas syndesewn kathe kombou
  for (i=0;i<N;i++) k[i]=0;
 
  for (n=0;n<run;n++)
    {      
      for (i=0;i<N;i++)
	{
	  for (j=i+1;j<N;j++)
	    {
	      num=1.0*rand()/RAND_MAX;
	      if (num<p)
		{
		  k[i]++;
		  k[j]++;
		}
	    }
 	}
    }

  //for (i=0;i<N;i++) k[i]=k[i]/run; //me ayth th diairesh edw bgazw tria bins
  
  kmax=0;
  for (i=0;i<N;i++)
    {
      if (kmax<k[i])
	kmax=k[i];
    }
  kmax=kmax+1;
  printf("kmax=%d\n",kmax);
  int *distribution=malloc(kmax*sizeof(int)); 

  for (i=0;i<kmax;i++)
    distribution[i]=0; //Arxikopoihsh
  
  for (i=0;i<N;i++)
    {distribution[k[i]]=distribution[k[i]]+1;}

  for (i=0;i<kmax;i++)
    {printf("%f\t%f\n",(i+1)/(float)run,distribution[i]/(float)run);
      fprintf(datad,"%f\t%f\n",(i+1)/(float)run,distribution[i]/(float)run);}
  
  for (i=0;i<N;i++)
    fprintf(datak,"%f\n",k[i]/(float)run);

  free(k);
  free(distribution);
  fclose(datak);
  fclose(datad);
}

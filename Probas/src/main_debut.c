#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "von_neumann.h"
#include "aes.h"
#include "mersenne_twister.h"

#define ARRAY_MAX_SIZE 1000

int rdtsc()
{
	// cette fonction cree un warning : c'est normal.
	__asm__ __volatile__("rdtsc");
}

int* randWeak(int n)
{
	int* tab = malloc(n*sizeof(int));
	int i;
	unsigned int value;
	for(i=0; i<n;i++)
	{
		srand(rdtsc());  // rand du C 
		//value = 1+(int)(n*rand()/(RAND_MAX+1.0));
		value = rand();
		value = value&0xF;
		tab[i] = value;
		printf("%d;", value);
	}
	return tab;
}

int* randStrong(int n)
{
	int* tab = malloc(n*sizeof(int));
	int i;
	unsigned int value;
	for(i=0; i<n;i++)
	{
		srand(rdtsc());  // rand du C 
		value = rand();
		//value = 1+(int)(n*rand()/(RAND_MAX+1.0));
		value = (value >> 27);
		value = value&0xF;
		tab[i]=value;
		printf("%d;", value);
	}
	return tab;
}

word16* randNeumann(int n)
{
	word16* tab = malloc(n*sizeof(word16));
	word16 x=1111; // nombre entre 1000 et 9999 pour Von Neumann
	word16 output_VN; // sortie pour pour Von Neumann
	int i;
	for(i=0; i<n;i++)
	{
		output_VN = Von_Neumann(&x); // Von Neumann
		tab[i] = output_VN;
		printf("%u;",output_VN);
	}
	return tab;
}

word32* randTwister(int n)
{
	word32* tab = malloc(n*sizeof(word32));
	struct mt19937p mt; // Pour Mersenne-Twister
	int tmp;
	word32 output_MT; // sortie pour Mersenne-Twister
	int i;
	for(i=0; i<n;i++)
	{
		tmp = rand(); // Pour Mersenne-Twister
		sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
		output_MT = genrand(&mt); // Mersenne-Twister
		tab[i] = output_MT;
		printf("%u;",output_MT);
	}
	return tab;
}

word32* randAES(int n)
{
	word32* tab = malloc(n*sizeof(word32));
	u32 Kx[NK], Kex[NB*NR], Px[NB]; // pour l'AES
	int i;
	word32 output_AES; // sortie pour l'AES
	for(i=0; i<n;i++)
	{
		init_rand(Kx, Px, NK, NB, 45);
		KeyExpansion(Kex,Kx); // AES : sous-clefs
		output_AES = AES(Px, Kex); // AES
		tab[i] = output_AES;
		printf("%u;",output_AES);
	}
	return tab;
}

double frequency(int n, int algo)
{
	int i, j;
	int sum = 0;
	int* weak;
	int* strong;
	word16* vn;
	word32* mt;
	word32* aes;
	double sobs;
	
	switch(algo)
	{
		case 0:
			weak = randWeak(n);
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(int); j++)
				{
					sum += 2*(weak[i]&0x1) - 1;
					weak[i] = weak[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*sizeof(int));
			break;
		case 1:
			strong = randStrong(n);
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(int); j++)
				{
					sum += 2*(strong[i]&0x1) - 1;
					strong[i] = strong[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*sizeof(int));
			break;
		case 2:
			vn = randNeumann(n);
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(word16); j++)
				{
					sum += 2*(vn[i]&0x1) - 1;
					vn[i] = vn[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*sizeof(word16));
			break;
		case 3:
			mt = randTwister(n);
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(word32); j++)
				{
					sum += 2*(mt[i]&0x1) - 1;
					mt[i] = mt[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*sizeof(word32));
			break;
		case 4:
			aes = randAES(n);
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(word32); j++)
				{
					sum += 2*(aes[i]&0x1) - 1;
					aes[i] = aes[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*sizeof(word32));
			break;
	}
	double pvaleur = erfc(sobs/sqrt(2));
	printf("\n pvaleur = %lf\n", pvaleur);
	return pvaleur;
}

double runs(int n, int algo)
{
	int ek, ek1;
	int i, j;
	double pi = 0.0;
	double to;
	double vobs = 1.0;
	double r;
	double size;
	int* weak,* weak2;
	int* strong,* strong2;
	word16* vn,* vn2;
	word32* mt,* mt2;
	word32* aes,* aes2;
	switch(algo)
	{
		case 0:
			weak = randWeak(n);
			weak2 = malloc(sizeof(int)*n);
			for(i=0; i<n; i++)
			{
				weak2[i] = weak[i];
			}
			size = (double)n*sizeof(int);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(int); j++)
				{
					pi += weak2[i]&0x1;
					weak2[i] = weak2[i] >> 1;
				}
			}
			free(weak2);
			pi /= size;
			to = 2/sqrt(size);
			if(abs(pi-0.5) >= to)
			{
				return 0.0;
			}
			else
			/* ~~ LE TEST ~~ */
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(int)-1; j++)
					{
						ek = weak[i]&0x1;
						weak[i] = weak[i] >> 1;
						ek1 = weak[i]&0x1;
						r = (ek == ek1) ? 0 : 1; 
						vobs += r;
					}
				}
			}
			printf("\n vobs = %lf", vobs);
			printf("\n size = %lf", size);
			break;
		case 1:
			strong = randStrong(n);
			strong2 = malloc(sizeof(int)*n);
			for(i=0; i<n; i++)
			{
				strong2[i] = strong[i];
			}
			size = (double)n*sizeof(int);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(int); j++)
				{
					pi += strong2[i]&0x1;
					strong2[i] = strong2[i] >> 1;
				}
			}
			free(strong2);
			pi /= size;
			to = 2/sqrt(size);
			if(abs(pi-0.5) >= to)
			{
				return 0.0;
			}
			else
			/* ~~ LE TEST ~~ */
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(int)-1; j++)
					{
						ek = strong[i]&0x1;
						strong[i] = strong[i] >> 1;
						ek1 = strong[i]&0x1;
						r = (ek == ek1) ? 0 : 1; 
						vobs += r;
					}
				}
			}
			printf("\n vobs = %lf", vobs);
			printf("\n size = %lf", size);
			break;
		case 2:
			vn = randNeumann(n);
			vn2 = malloc(sizeof(word16)*n);
			for(i=0; i<n; i++)
			{
				vn2[i] = vn[i];
			}
			size = (double)n*sizeof(word16);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(word16); j++)
				{
					pi += vn2[i]&0x1;
					vn2[i] = vn2[i] >> 1;
				}
			}
			free(vn2);
			pi /= size;
			to = 2/sqrt(size);
			printf("wololooooo");
			if(abs(pi-0.5) >= to)
			{
				return 0.0;
			}
			else
			/* ~~ LE TEST ~~ */
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(word16)-1; j++)
					{
						ek = vn[i]&0x1;
						vn[i] = vn[i] >> 1;
						ek1 = vn[i]&0x1;
						r = (ek == ek1) ? 0 : 1; 
						vobs += r;
					}
				}
			}
			printf("\n vobs = %lf", vobs);
			printf("\n size = %lf", size);
			break;
		case 3:
			mt = randTwister(n);
			mt2 = malloc(sizeof(word32)*n);
			for(i=0; i<n; i++)
			{
				mt2[i] = mt[i];
			}
			size = (double)n*sizeof(word32);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(word32); j++)
				{
					pi += mt2[i]&0x1;
					mt2[i] = mt2[i] >> 1;
				}
			}
			free(mt2);
			pi /= size;
			to = 2/sqrt(size);
			if(abs(pi-0.5) >= to)
			{
				return 0.0;
			}
			else
			/* ~~ LE TEST ~~ */
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(word32)-1; j++)
					{
						ek = mt[i]&0x1;
						mt[i] = mt[i] >> 1;
						ek1 = mt[i]&0x1;
						r = (ek == ek1) ? 0 : 1; 
						vobs += r;
					}
				}
			}
			printf("\n vobs = %lf", vobs);
			printf("\n size = %lf", size);
			break;
		case 4:
			aes = randAES(n);
			aes2 = malloc(sizeof(word32)*n);
			for(i=0; i<n; i++)
			{
				aes2[i] = aes[i];
			}
			size = (double)n*sizeof(word32);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<sizeof(word32); j++)
				{
					pi += aes2[i]&0x1;
					aes2[i] = aes2[i] >> 1;
				}
			}
			free(aes2);
			pi /= size;
			to = 2/sqrt(size);
			if(abs(pi-0.5) >= to)
			{
				return 0.0;
			}
			else
			/* ~~ LE TEST ~~ */
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(word32)-1; j++)
					{
						ek = aes[i]&0x1;
						aes[i] = aes[i] >> 1;
						ek1 = aes[i]&0x1;
						r = (ek == ek1) ? 0 : 1; 
						vobs += r;
					}
				}
			}
			printf("\n vobs = %lf", vobs);
			printf("\n size = %lf", size);
			break;
	}
	double pvaleur = erfc(abs(vobs-2*size*pi*(1-pi))/(2*sqrt(2*size)*pi*(1-pi)));
	printf("\n pvaleur = %lf\n", pvaleur);
	return pvaleur;
}

int main(int argc, char** args)
{
	
	/*word16 x=1111; // nombre entre 1000 et 9999 pour Von Neumann
	struct mt19937p mt; // Pour Mersenne-Twister
	int tmp = rand(); // Pour Mersenne-Twister
	u32 Kx[NK], Kex[NB*NR], Px[NB]; // pour l'AES

	int output_rand; // sortie du rand du C	
	word32 output_AES; // sortie pour l'AES
	word16 output_VN; // sortie pour pour Von Neumann
	word32 output_MT; // sortie pour Mersenne-Twister
	

	// initialisation des graines des generateurs
	srand(rdtsc());  // rand du C 
	sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
	// Initialisation de la clé et du plaintext pour l'AES 
	// 45 est un paramètre qui doit changer à chaque initialisation
	init_rand(Kx, Px, NK, NB, 45);
	KeyExpansion(Kex,Kx); // AES : sous-clefs


	// sorties des generateurs	
	output_rand = rand(); // rand du C
	output_VN = Von_Neumann(&x); // Von Neumann
	output_MT = genrand(&mt); // Mersenne-Twister
	output_AES = AES(Px, Kex); // AES

	// affichage
	printf("- Generation de nombres aleatoires -\n");
	printf("rand du C : %u \n",output_rand); 
	printf("Von Neumann : %u\n",output_VN);
	printf("Mersenne Twister : %u\n",output_MT);
	printf("AES : %u\n",output_AES);*/
	
	//20 pvaleurs
	int n = 1024;
	switch(atoi(args[1]))
	{
		case 0:
			switch(atoi(args[2]))
			{
				case 0:
					randWeak(n);
					break;
				case 1:
					randStrong(n);
					break;
				case 2:
					randNeumann(n);
					break;
				case 3:
					randTwister(n);
					break;
				case 4:
					randAES(n);
					break;
				default:
					randWeak(n);
					printf("\n");
					randStrong(n);
					printf("\n");
					randNeumann(n);
					printf("\n");
					randTwister(n);
					printf("\n");
					randAES(n);
					break;
			}
			break;
		case 1:
			frequency(n, atoi(args[2]));
			break;
		case 2:
			runs(n, atoi(args[2]));
			break;
	}
	return 0;
}

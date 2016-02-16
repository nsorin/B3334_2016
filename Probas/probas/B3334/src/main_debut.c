#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#include "von_neumann.h"
#include "aes.h"
#include "mersenne_twister.h"

#define ARRAY_MAX_SIZE 1000
#define n 1024

struct file_attente
{
	double* arrivee;
	int taille_arrivee;
	double* depart;
	int taille_depart;
};
typedef struct file_attente file_attente;

struct evolution
{
	double* temps;
	unsigned int* nombre;
};
typedef struct evolution evolution;

int rdtsc()
{
	// cette fonction cree un warning : c'est normal.
	__asm__ __volatile__("rdtsc");
}

int* randWeak(FILE * fp)
{
	int* tab = (int*) malloc(n*sizeof(int));
	int i;
	unsigned int value;
	srand(rdtsc());  // rand du C
	for(i=0; i<n;i++)
	{
		value = rand();
		value = value&0xF;
		tab[i] = value;
		fprintf(fp,"%u;", value);
	}
	fprintf(fp,"\r\n");
	return tab;
}

int* randStrong(FILE * fp)
{
	int* tab = (int*) malloc(n*sizeof(int));
	int i;
	unsigned int value;
	srand(rdtsc());  // rand du C
	for(i=0; i<n;i++)
	{
		value = rand();
		value = (value >> 27);
		value = value&0xF;
		tab[i]=value;
		fprintf(fp,"%u;", value);
	}
	fprintf(fp,"\r\n");
	return tab;
}

word16* randNeumann(FILE * fp, word16 x)
{
	word16* tab = (word16*) malloc(n*8*sizeof(word16));
	word16 output_VN; // sortie pour pour Von Neumann
	int i;
	for(i=0; i<n;i++)
	{
		output_VN = Von_Neumann(&x); // Von Neumann
		tab[i] = output_VN;
		fprintf(fp,"%u;",output_VN);
	}
	fprintf(fp,"\r\n");
	return tab;
}

word32* randTwister(FILE * fp)
{
	word32* tab = (word32*) malloc(n*8*sizeof(word32));
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
		fprintf(fp,"%u;", output_MT);
	}
	fprintf(fp,"\r\n");
	return tab;
}

word32* randAES(FILE * fp, u32* Px, u32* Kex)
{
	word32* tab = (word32*) malloc(n*8*sizeof(word32));
	int i;
	word32 output_AES; // sortie pour l'AES
	for(i=0; i<n;i++)
	{
		output_AES = AES(Px, Kex); // AES
		tab[i] = output_AES;
		fprintf(fp,"%u;", output_AES);
	}
	fprintf(fp,"\r\n");
	return tab;
}

double frequency(FILE * fp, int algo, u32* Px, u32* Kex, word16 x)
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
			weak = randWeak(fp);
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
			strong = randStrong(fp);
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
			vn = randNeumann(fp,x);
			for(i=0; i<n; i++)
			{
				for(j=0; j<8*sizeof(word16); j++)
				{
					sum += 2*(vn[i]&0x1) - 1;
					vn[i] = vn[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*8*sizeof(word16));
			break;
		case 3:
			mt = randTwister(fp);
			for(i=0; i<n; i++)
			{
				for(j=0; j<8*sizeof(word32); j++)
				{
					sum += 2*(mt[i]&0x1) - 1;
					mt[i] = mt[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*8*sizeof(word32));
			break;
		case 4:
			aes = randAES(fp, Px, Kex);
			for(i=0; i<n; i++)
			{
				for(j=0; j<8*sizeof(word32); j++)
				{
					sum += 2*(aes[i]&0x1) - 1;
					aes[i] = aes[i] >> 1;
				}
			}
			sobs = (double)abs(sum)/sqrt(n*8*sizeof(word32));
			break;
	}
	double pvaleur = erfc(sobs/sqrt(2));
	fprintf(fp,"Pvaleur : %lf\r\n", pvaleur);
	return pvaleur;
}

double runs(FILE * fp, int algo, u32* Px, u32* Kex, word16 x)
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
			weak = randWeak(fp);
			weak2 = (int*) malloc(sizeof(int)*n);
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
				ek = weak[0]&0x1;
				weak[i] = weak[i] >> 1;
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(int); j++)
					{
						if((j!=sizeof(int)-1 && i!=n-1) || (j!=0 && i!=0))
						{
							ek1 = weak[i]&0x1;
							r = (ek == ek1) ? 0 : 1;
							vobs += r;
							ek = weak[i]&0x1;
							weak[i] = weak[i] >> 1;
						}
					}
				}
			}
			break;
		case 1:
			strong = randStrong(fp);
			strong2 = (int*) malloc(sizeof(int)*n);
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
				ek = strong[0]&0x1;
				strong[i] = strong[i] >> 1;
				for(i=0; i<n; i++)
				{
					for(j=0; j<sizeof(int); j++)
					{
						if((j!=sizeof(int)-1 && i!=n-1) || (j!=0 && i!=0))
						{
							ek1 = strong[i]&0x1;
							r = (ek == ek1) ? 0 : 1;
							vobs += r;
							ek = strong[i]&0x1;
							strong[i] = strong[i] >> 1;
						}
					}
				}
			}
			break;
		case 2:
			vn = randNeumann(fp, x);
			vn2 = (word16*) malloc(8*sizeof(word16)*n);
			for(i=0; i<n; i++)
			{
				vn2[i] = vn[i];
			}
			size = (double)n*8*sizeof(word16);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<8*sizeof(word16); j++)
				{
					pi += vn2[i]&0x1;
					vn2[i] = vn2[i] >> 1;
				}
			}
			free(vn2);
			pi /= size;
			to = 2/sqrt(size);
			if(abs(pi-0.5) >= to)
			{
				return 0.0;
			}
			else
			/* ~~ LE TEST ~~ */
			{
				ek = vn[0]&0x1;
				vn[i] = vn[i] >> 1;
				for(i=0; i<n; i++)
				{
					for(j=0; j<8*sizeof(word16); j++)
					{
						if((j!=8*sizeof(word16)-1 && i!=n-1) || (j!=0 && i!=0))
						{
							ek1 = vn[i]&0x1;
							r = (ek == ek1) ? 0 : 1;
							vobs += r;
							ek = vn[i]&0x1;
							vn[i] = vn[i] >> 1;
						}
					}
				}
			}
			break;
		case 3:
			mt = randTwister(fp);
			mt2 = (word32*) malloc(8*sizeof(word32)*n);
			for(i=0; i<n; i++)
			{
				mt2[i] = mt[i];
			}
			size = (double)n*8*sizeof(word32);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<8*sizeof(word32); j++)
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
				ek = mt[0]&0x1;
				mt[i] = mt[i] >> 1;
				for(i=0; i<n; i++)
				{
					for(j=0; j<8*sizeof(word32); j++)
					{
						if((j!=8*sizeof(word32)-1 && i!=n-1) || (j!=0 && i!=0))
						{
							ek1 = mt[i]&0x1;
							r = (ek == ek1) ? 0 : 1;
							vobs += r;
							ek = mt[i]&0x1;
							mt[i] = mt[i] >> 1;
						}
					}
				}
			}
			break;
		case 4:
			aes = randAES(fp, Px, Kex);
			aes2 = (word32*) malloc(8*sizeof(word32)*n);
			for(i=0; i<n; i++)
			{
				aes2[i] = aes[i];
			}
			size = (double)n*8*sizeof(word32);
			/* ~~ LE PRETEST ~~ */
			for(i=0; i<n; i++)
			{
				for(j=0; j<8*sizeof(word32); j++)
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
				ek = aes[0]&0x1;
				aes[i] = aes[i] >> 1;
				for(i=0; i<n; i++)
				{
					for(j=0; j<8*sizeof(word32); j++)
					{
						if((j!=8*sizeof(word32)-1 && i!=n-1) || (j!=0 && i!=0))
						{
							ek1 = aes[i]&0x1;
							r = (ek == ek1) ? 0 : 1;
							vobs += r;
							ek = aes[i]&0x1;
							aes[i] = aes[i] >> 1;
						}
					}
				}
			}
			break;
	}
	double pvaleur = erfc(abs(vobs-2*size*pi*(1-pi))/(2*sqrt(2*size)*pi*(1-pi)));
	fprintf(fp,"Pvaleur : %lf;", pvaleur);
	return pvaleur;
}

double Alea()
{
	struct mt19937p mt; // Pour Mersenne-Twister
	int tmp = rand(); // Pour Mersenne-Twister
	sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
	word32 a = genrand(&mt);
	return (double)a/pow(2,32);
}

double Exponentielle(double lambda)
{
	double u = Alea();
	double a = -log(1-u)/lambda;
	return a;
}

file_attente FileMM1(double lambda, double mu, double D)
{
	file_attente fa;
	fa.arrivee = (double*) calloc(ARRAY_MAX_SIZE, sizeof(double));
	fa.taille_arrivee = 0;
	fa.depart = (double*) calloc(ARRAY_MAX_SIZE, sizeof(double));
	fa.taille_depart = 0;
	double ta = 0.0;
	while(ta<D)
	{
		ta += Exponentielle(lambda);
		fa.arrivee[fa.taille_arrivee] = ta;
		fa.taille_arrivee++;
	}
	fa.taille_arrivee--;

	int i;
	for(i=0; i<fa.taille_arrivee-1;i++)
	{
		if(i==0)
		{
			fa.depart[fa.taille_depart] = fa.arrivee[fa.taille_depart] + Exponentielle(mu);
			fa.taille_depart++;
		}
		else if(fa.depart[fa.taille_depart-1]<D)
		{
			if(fa.depart[fa.taille_depart-1]<fa.arrivee[fa.taille_depart])
			{
				fa.depart[fa.taille_depart] = fa.arrivee[fa.taille_depart] + Exponentielle(mu);
				fa.taille_depart++;
			}
			else
			{
				fa.depart[fa.taille_depart] = fa.depart[fa.taille_depart-1] + Exponentielle(mu);
				fa.taille_depart++;
			}
		}
	}
	fa.taille_depart--;
	return fa;
}

evolution clientsEvolution(file_attente fa)
{
    int i;
    evolution ev;
    ev.temps = (double*) calloc(ARRAY_MAX_SIZE*2, sizeof(double));
    ev.nombre = (unsigned int*) calloc(ARRAY_MAX_SIZE, sizeof(unsigned int));

    int cptArrivee = 0;
    int cptDepart = 0;

    ev.temps[0] = fa.arrivee[cptArrivee++];
    ev.nombre[0] = 1;

    for(i = 1; i<fa.taille_arrivee+fa.taille_depart; i++)
    {
            if(fa.arrivee[cptArrivee]<fa.depart[cptDepart])
            {
                    ev.temps[i] = fa.arrivee[cptArrivee++];
                    ev.nombre[i] = ev.nombre[i-1]+1;
            }
            else
            {
                    ev.temps[i] = fa.depart[cptDepart++];
                    ev.nombre[i] = ev.nombre[i-1]-1;
            }
    }
    return ev;
}

int main(int argc, char** args)
{
	word16 x=1111; // nombre entre 1000 et 9999 pour Von Neumann
	struct mt19937p mt; // Pour Mersenne-Twister
	int tmp = rand(); // Pour Mersenne-Twister
	u32 Kx[NK], Kex[NB*NR], Px[NB]; // pour l'AES

	// initialisation des graines des generateurs
	srand(rdtsc());  // rand du C
	sgenrand(time(NULL)+(tmp), &mt); // Mersenne-Twister
	// Initialisation de la clé et du plaintext pour l'AES
	// 45 est un paramètre qui doit changer à chaque initialisation
	init_rand(Kx, Px, NK, NB, 45);
	KeyExpansion(Kex,Kx); // AES : sous-clefs

	FILE * fp;
	fp = fopen("B3334.txt", "w+");
	int i,j;
	for(i=0;i<5;i++)
	{
		for(j=0;j<20;j++)
		{
			switch(i)
			{
				case 0:
					fprintf(fp,"Test %d Weak : \r\n",j+1);
					randWeak(fp);
					break;
				case 1:
					fprintf(fp,"Test %d Strong : \r\n",j+1);
					randStrong(fp);
					break;
				case 2:
					fprintf(fp,"Test %d Von Neumann : \r\n",j+1);
					randNeumann(fp,x);
					break;
				case 3:
					fprintf(fp,"Test %d Mersenne : \r\n",j+1);
					randTwister(fp);
					break;
				case 4:
					fprintf(fp,"Test %d AES : \r\n",j+1);
					randAES(fp, Px, Kex);
					break;
			}
			fprintf(fp,"Test %d frequence : \r\n",j+1);
			frequency(fp, i, Px, Kex, x);
			fprintf(fp,"Test %d runs : \r\n",j+1);
			runs(fp, i, Px, Kex, x);
			fprintf(fp,"\r\n\r\n");
		}
		fprintf(fp,"\r\n");
	}

	//Application 1
	file_attente f;
	f = FileMM1(0.2,0.33,180);
	fprintf(fp,"\r\nFile attente :");
	fprintf(fp,"\r\n%d Arrivees :\r\n",f.taille_arrivee);
	for(i=0;i<f.taille_arrivee;i++)
	{
		fprintf(fp,"%lf;",f.arrivee[i]);
	}
	fprintf(fp,"\r\n%d Departs :\r\n",f.taille_depart);
	for(i=0;i<f.taille_depart;i++)
	{
		fprintf(fp,"%lf;",f.depart[i]);
	}
	evolution ev = clientsEvolution(f);
	fprintf(fp,"\r\nEvolution : temps(nombre)\r\n");
	for(i=0;i<f.taille_depart+f.taille_arrivee;i++)
	{
		fprintf(fp,"%lf(%d);",ev.temps[i],ev.nombre[i]);
	}
	free(f.arrivee);
	free(f.depart);
	free(ev.nombre);
	free(ev.temps);

	//Application 2
	f = FileMM1(0.3,0.33,180);
	fprintf(fp,"\r\n\r\nFile attente :");
	fprintf(fp,"\r\n%d Arrivees :\r\n",f.taille_arrivee);
	for(i=0;i<f.taille_arrivee;i++)
	{
		fprintf(fp,"%lf;",f.arrivee[i]);
	}
	fprintf(fp,"\r\n%d Departs :\r\n",f.taille_depart);
	for(i=0;i<f.taille_depart;i++)
	{
		fprintf(fp,"%lf;",f.depart[i]);
	}
	ev = clientsEvolution(f);
	fprintf(fp,"\r\nEvolution : temps(nombre)\r\n");
	for(i=0;i<f.taille_depart+f.taille_arrivee;i++)
	{
		fprintf(fp,"%lf(%d);",ev.temps[i],ev.nombre[i]);
	}
	free(f.arrivee);
	free(f.depart);
	free(ev.nombre);
	free(ev.temps);

	fclose(fp);
	return 0;
}

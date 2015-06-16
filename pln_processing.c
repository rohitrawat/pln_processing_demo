/*
PLN model processing program in C
=================================

Rohit Rawat (rohitrawat@gmail.com)
*/

#include <stdio.h>
#include <stdlib.h>

/* Struct defining PLN structure and weights matrices */
struct PlnWeights {
    /* number of clusters, inputs, and outputs */
    int Nc; /* number of clusters */
    int N; /* inputs */
    int M; /* outputs */
    
    /* for pre-processing */
    double *inputMeans;
    double *inputStd;
    
    /* cluster centers and distance measure */
    double *distanceMeasure;
    double **clusterCenters;
    
    /* cluster weights */
    double ***W;

    /* Unused entries which can be left uninitialized */    
    int *Nv; /* samples in each cluster */
    double ***R; /* autocorrelation for each cluster */
    double ***C; /* crosscorrelation for each cluster */
    double **Et; /* variance of outputs */
    double *lambda; /* regularization parameter */
};

/* array creation */
double* mallocArray(int size) {
    double *ptr = NULL;
    ptr = (double*)malloc(size*sizeof(double));
    if(ptr == NULL) {
        printf("Malloc failed, size = %d\n\n", size);
        exit(0);
    }
    return ptr;
}

/* matrix creation */
double** mallocMatrix(int rows, int cols) {
    int r;
    double **ptr = NULL;
    ptr = (double**)malloc(rows*sizeof(double));
    if(ptr == NULL) {
        printf("Malloc failed, size = %d\n\n", rows);
        exit(0);
    }
    for(r=0; r<rows; r++) {
        ptr[r] = mallocArray(cols);
    }
    return ptr;
}

// Uncomment to print debugging messages:
//#define DEBUG_PRINT

#ifdef DEBUG_PRINT
#define dprintf0(FMT) printf(FMT)
#define dprintf(FMT, ARG) printf(FMT, ARG)
#else
#define dprintf0(FMT) //printf(FMT)
#define dprintf(FMT, ARG) //printf(FMT, ARG)
#endif

/* read PLN weights text file. 
Instead of reading from text file, the values can be directly coded into the structure */
void readPlnWeights(char *fname, struct PlnWeights *pln) {
        int cnt = 0;
        int n, m, k;
        
        FILE *fp = NULL;
        
        fp = fopen(fname, "r");
        if(!fp) {
            printf("Unable to open file to load PLN.\n");
            exit(0);
        }
        
        cnt = fscanf(fp, "PLN\n");
        
        cnt = fscanf(fp, "K\n%d\n", &pln->Nc);
        
        cnt = fscanf(fp, "N\n%d\n", &pln->N);

        cnt = fscanf(fp, "M\n%d\n", &pln->M);
        
        pln->distanceMeasure = mallocArray(pln->N);
        cnt = fscanf(fp, "DistanceMeasure\n");
        dprintf0("DistanceMeasure\n");
        for(n=0; n<pln->N; n++) {
            cnt = fscanf(fp, "%lf ", &pln->distanceMeasure[n]);
            dprintf("%e ", pln->distanceMeasure[n]);
        }
        dprintf0("\n");
        
        pln->inputMeans = mallocArray(pln->N);
        cnt = fscanf(fp, "InputMeans\n");
        dprintf0("InputMeans\n");
        for(n=0; n<pln->N; n++) {
            cnt = fscanf(fp, "%lf ", &pln->inputMeans[n]);
            dprintf("%e ", pln->inputMeans[n]);
        }
        dprintf0("\n");
        
        pln->inputStd = mallocArray(pln->N);
        cnt = fscanf(fp, "InputStd\n");
        dprintf0("InputStd\n");
        for(n=0; n<pln->N; n++) {
            cnt = fscanf(fp, "%lf ", &pln->inputStd[n]);
            dprintf("%e ", pln->inputStd[n]);
        }
        dprintf0("\n");
        
        pln->Nv = (int*)malloc(pln->Nc*sizeof(int));
        
        pln->clusterCenters = mallocMatrix(pln->Nc, pln->N);
        
        pln->R = (double***)malloc(pln->Nc*sizeof(double**));
        pln->C = (double***)malloc(pln->Nc*sizeof(double**));
        pln->W = (double***)malloc(pln->Nc*sizeof(double**));
        
        pln->Et = mallocMatrix(pln->Nc, pln->M);
        pln->lambda = mallocArray(pln->Nc);
        
        for(k=0; k<pln->Nc; k++) {
            int idx;
            cnt = fscanf(fp, "ClusterIndex\n%d\n", &idx);
            dprintf("Reading cluster %d\n", idx);
            if(k!=idx) {
                printf("Invalid file.\n");
                exit(0);
            }
            
            cnt = fscanf(fp, "Nv\n%d\n", &pln->Nv[k]);
            dprintf("Nv =  %d\n", pln->Nv[k]);
            
            cnt = fscanf(fp, "CenterVector\n");
            dprintf0("CenterVector\n");
            for(n=0; n<pln->N; n++) {
                cnt = fscanf(fp, "%lf ", &pln->clusterCenters[k][n]);
                dprintf("%e ", pln->clusterCenters[k][n]);
            }
            cnt = fscanf(fp, "\n");
            dprintf0("\n");
            
            pln->R[k] = mallocMatrix(pln->N+1, pln->N+1);
            dprintf0("R\n");
            cnt = fscanf(fp, "R\n");
            for(n=0; n<pln->N+1; n++) {
                for(m=0; m<pln->N+1; m++) {
                    cnt = fscanf(fp, "%lf ", &pln->R[k][n][m]);
                    dprintf("%e ", pln->R[k][n][m]);
                }
                cnt = fscanf(fp, "\n");
            }
            dprintf0("\n");
            
            pln->C[k] = mallocMatrix(pln->M, pln->N+1);
            cnt = fscanf(fp, "C\n");
            dprintf0("C\n");
            for(n=0; n<pln->M; n++) {
                for(m=0; m<pln->N+1; m++) {
                    cnt = fscanf(fp, "%lf ", &pln->C[k][n][m]);
                    dprintf("%e ", pln->C[k][n][m]);
                }
                cnt = fscanf(fp, "\n");
            }
            dprintf0("\n");
            
            pln->W[k] = mallocMatrix(pln->M, pln->N+1);
            cnt = fscanf(fp, "W\n");
            dprintf0("W\n");
            for(n=0; n<pln->M; n++) {
                for(m=0; m<pln->N+1; m++) {
                    cnt = fscanf(fp, "%lf ", &pln->W[k][n][m]);
                    dprintf("%e ", pln->W[k][n][m]);
                }
                cnt = fscanf(fp, "\n");
            }
            dprintf0("\n");
            
            cnt = fscanf(fp, "Et\n");
            dprintf0("Et\n");
            for(n=0; n<pln->M; n++) {
                cnt = fscanf(fp, "%lf ", &pln->Et[k][n]);
                dprintf("%e ", pln->Et[k][n]);
            }
            cnt = fscanf(fp, "\n");
            dprintf0("\n");
            
            cnt = fscanf(fp, "lambda\n%lf\n", &pln->lambda[k]);
            dprintf("lambda\n%lf\n", pln->lambda[k]);
        }
        
        cnt = fscanf(fp, "EOF\n");
        
        fclose(fp);
}

/* pre process an input vector */
void preProcess(double *in, const struct PlnWeights *pln, double *out) {
    int n=0;
    for(n=0; n<pln->N; n++) {
        out[n] = (in[n]-pln->inputMeans[n])/pln->inputStd[n];
    }
}

/* find the closest cluster to x */
int get_PLN_cluster_membership(double *x, const struct PlnWeights *pln) {
    double dmin;
    int kmin;
    int k, n;
    double d;
    dmin = 1e300;
    kmin = 0;
    if(pln->Nc == 1) {
        return 0;
    }
    for(k=0; k<pln->Nc; k++) {
        d = 0;
        for(n=0; n<pln->N+1; n++) {
            d += abs(x[n] - pln->clusterCenters[k][n]);
        }
        if(d<dmin) {
            dmin = d;
            kmin = k;
        }
    }
    return kmin;
}

/* calculate PLN output (for the pain management project, we limit to two outputs PDA and OSW) */
void get_PLN_output(double *x_in, const struct PlnWeights *pln, double *PDA, double *OSW) {
    double *y;
    double *x;
    int k;
    int n, m;
    
    x = mallocArray(pln->N);
    y = mallocArray(pln->M);
    preProcess(x_in, pln, x);

    k = get_PLN_cluster_membership(x, pln);
    dprintf("k=%d\n", k);
    for(m=0; m<pln->M; m++) {
        dprintf("m=%d\n", m);
        y[m] = pln->W[k][m][0];
        for(n=1; n<pln->N+1; n++) {
            y[m] += x[n-1]*pln->W[k][m][n];
        }
    }
    *PDA = y[0];
    *OSW = y[1];
}

/* Demo main program */
main() {
    struct PlnWeights pln1;
    readPlnWeights("data/file1_pln_weights.txt", &pln1);

    struct PlnWeights pln2;
    readPlnWeights("data/file2_pln_weights.txt", &pln2);

/*
Selected columns for file 1:
16: pre_OSW
783: RxGr7_1_pre_OSW
729: RxGr6_1_children
391: ProcGr11_1_phydx20
894: RxGr8_1_RxGr7_0
*/
    double x1[5];
    x1[0] = 1; // input 16
    x1[1] = 2; // input 783
    x1[2] = 3; // input 729
    x1[3] = 4; // input 391
    x1[4] = 5; // input 894
    double mid_PDA, mid_OSW;
    get_PLN_output(x1, &pln1, &mid_PDA, &mid_OSW);
    printf("mid_PDA = %lf\n", mid_PDA);
    printf("mid_OSW = %lf\n", mid_OSW);

    

/*
Selected columns for file 2:
31: mid_OSW
1830: RxGr8_2_mid_OSW
1755: RxGr7_2_mid_OSW
1005: ProcGr2_2_mid_OSW
1380: RxGr2_2_mid_OSW
*/
    double x2[5];
    x2[0] = 1; // input 31
    x2[1] = 2; // input 1830
    x2[2] = 3; // input 1755
    x2[3] = 4; // input 1005
    x2[4] = 5; // input 1380
    double post_PDA, post_OSW;
    get_PLN_output(x2, &pln2, &post_PDA, &post_OSW);
    printf("post_PDA = %lf\n", post_PDA);
    printf("post_OSW = %lf\n", post_OSW);
}

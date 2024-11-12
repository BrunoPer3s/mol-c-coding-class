#include <iostream>
#include <time.h>
#include <memory.h>
#include "pmm.h"

int main() {
    std::cout << "Hello World!" << std::endl;
    //srand(time(NULL)); // Deixar comentada quando testar as metas heuristicas
    char arq[50];
    //testar_alocacao();

    ler_dados("pmm1.txt");

    SolucaoBIN sBin;

    criar_solucaoBIN(sBin);
    escrever_solucaoBIN(sBin);
    return 0;
}

void ler_dados(char* arq) {
    FILE * f = fopen(arq, "r");
    fscanf(f, "%d %d", &num_obj, &num_moc);
    for(int i = 0; i < num_obj; i++) {
        fscanf(f, "%d", &vet_val_obj[i]);
    }
     for(int i = 0; i < num_obj; i++) {
        fscanf(f, "%d", &vet_pes_obj[i]);
    }
     for(int i = 0; i < num_moc; i++) {
        fscanf(f, "%d", &vet_cap_moc[i]);
    }

    fclose(f);
}

void testar_dados(char* arq) {
    FILE* f;
    if(arq == "") {
        f = stdout;
    } else {
        f = fopen(arq, "w");
    }
    fprintf(f, "%d %d\n", num_obj, num_moc);
    for(int i = 0; i < num_obj; i++) {
        fprintf(f, "%d ", vet_val_obj[i]);
    }
        fprintf(f, "\n");

     for(int i = 0; i < num_obj; i++) {
        fprintf(f, "%d ", vet_pes_obj[i]);

    }
        fprintf(f, "\n");

     for(int i = 0; i < num_moc; i++) {
        fprintf(f, "%d ", vet_cap_moc[i]);
    }
        fprintf(f, "\n");


    if(arq != "") {
        fclose(f);
    }
}


void testar_alocacao() {
    const int tamanho = 500;
    const int repeticoes = 1000;

    clock_t h;
    double tempo;

    int** mat_dinamica;
    int mat_estatica[tamanho][tamanho];

    //MALLOC

    h = clock();
    for(int r = 0; r < repeticoes; r++) {
        mat_dinamica = (int **)malloc(sizeof(int*) * tamanho);

        for(int i = 0; i < tamanho; i++) {
            mat_dinamica[i] = (int *)malloc(sizeof(int) * tamanho);
        }

        for(int i = 0; i < tamanho; i++) {
            free(mat_dinamica[i]);
        }

    free(mat_dinamica);
    }

    h = clock() - h;
    tempo = (double)h / CLOCKS_PER_SEC;
    printf("Tempo Malloc %.10f segundos!\n", tempo);

    // NEW

    h = clock();
    for(int r = 0; r < repeticoes; r++) {
        mat_dinamica = new int*[tamanho];
        for(int i = 0; i < tamanho; i++) {
        mat_dinamica[i] = new int[tamanho];
        }

        for(int i = 0; i < tamanho; i++) {
            delete[] mat_dinamica[i];
        }

    delete[] mat_dinamica;
    }

   
    h = clock() - h;
    tempo = (double)h / CLOCKS_PER_SEC;
    printf("Tempo NEW %.10f segundos!\n", tempo);

    //Estatica

    h = clock();
    for(int r = 0; r < repeticoes; r++) {
        for(int i = 0; i < tamanho; i++) {
            for(int j = 0; j < tamanho; j++) {
                mat_estatica[i][j] = 0;
            }
        }
    }

   
    h = clock() - h;
    tempo = (double)h / CLOCKS_PER_SEC;
    printf("Tempo Estatico %.10f segundos!\n", tempo);

    //Memset

    h = clock();
    for(int r = 0; r < repeticoes; r++) {
       memset(&mat_estatica, 0, sizeof(mat_estatica));
    }

   
   
    h = clock() - h;
    tempo = (double)h / CLOCKS_PER_SEC;
    printf("Tempo Memset %.10f segundos!\n", tempo);

     for(int i = 0; i < tamanho; i++) {
            for(int j = 0; j < tamanho; j++) {
                printf("%d ", mat_estatica[i][j]);
            }
            printf("\n");
    }

    

}


void escrever_solucaoBIN(SolucaoBIN& s) {
    printf("FO: %d\n", s.fo);
    for(int i = 0 ; i < num_moc; i++) {
        for(int j = 0; j < num_obj; j++) {
            printf("%d ", s.mat_sol[i][j]);
        }
        printf("\n");
    }
}

void criar_solucaoBIN(SolucaoBIN& s) {
    for(int i = 0 ; i < num_moc; i++) {
        for(int j = 0; j < num_obj; j++) {
            s.mat_sol[i][j] = rand() % 2;
        }
    }
}



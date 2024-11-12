#ifndef PMM_H_INCLUDED
#define PMM_H_INCLUDED

#define MAX_OBJ 500
#define MAX_MOC 50

typedef struct tSolucaoBIN {
    int mat_sol[MAX_MOC][MAX_OBJ];
    int fo;
} SolucaoBIN;

int num_obj;
int num_moc;
int vet_val_obj[MAX_OBJ];
int vet_pes_obj[MAX_OBJ];
int vet_cap_moc[MAX_MOC];

void testar_dados(char* arq);
void ler_dados(char* arq);

void testar_alocacao();

void criar_solucaoBIN(SolucaoBIN& s);
void calc_fo_solucaoBIN(SolucaoBIN& s); // Brincar em casa
void escrever_solucaoBIN(SolucaoBIN& s);


#endif

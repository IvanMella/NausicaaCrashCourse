#include <stdio.h>
#include <assert.h>

int compra(int N, int M, int A, int B) {

    // calcola il numero di carnet 0 se N < M
    int totS ,totC ,totM ;

    int numCr = (N - 1) / M + 1;
    int numBg = N % M;

    totS = N * A;
    totC = B * numCr;
    totM = numBg * A + (numCr - 1) * B;

    printf("numBg:%d, numCr:%d, S:%d, C:%d, H:%d\n",numBg, numCr, totS, totC, totM);

    if (totC < totS)
        if (totC < totM)
            return totC;
        else
            return totM;
    if (totS < totM)
            return totS;
        return totM;
}

int main() {
    FILE *fr, *fw;
    int N, M, A, B;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");

    assert(4 == fscanf(fr, "%d%d%d%d", &N, &M, &A, &B));

    fprintf(fw, "%d\n", compra(N, M, A, B));
    fclose(fr);
    fclose(fw);
    return 0;
}

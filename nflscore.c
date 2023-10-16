#include <stdio.h>

void printCombos(int score, int td2, int tdfg, int td, int fg, int safety) {
    printf("\n%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety", td2, tdfg, td, fg, safety);
}

void findCombos(int score) {
    for(int td2 = 0; td2 <= score / 8; td2++)
        for(int tdfg = 0; tdfg <= (score - td2 * 8) / 7; tdfg++)
            for(int td = 0; td <= (score - td2 * 8 - tdfg * 7) / 6; td++)
                for(int fg = 0; fg <= (score - td2 * 8 - tdfg * 7 - td * 6) / 3; fg++)
                    for(int safety = 0; safety <= (score- td2 * 8 - tdfg * 7 - td * 6 - fg * 3) / 2; safety++)
                        if(score == td2*8 + tdfg*7 + td*6 + fg*3 + safety*2)
                            printCombos(score, td2, tdfg, td, fg, safety);
}

int main() {
    int score;
    do {
        printf("\nEnter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);
        if(score > 1)
            findCombos(score);
    } while(score > 1);
    return 0;
}

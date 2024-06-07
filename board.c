#include "board.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

void InitSq120ToSq64() {
  int index = 0;
  int file = FILE_A;
  int rank = RANK_1;
  int sq = A1;
  int sq64 = 0;

  for(index = 0; index < BRD_SQ_NUM; ++index) {
    Sq120ToSq64[index] = 65;
  }

  for(index = 0; index < 64; ++index) {
    Sq64ToSq120[index] = 120;
  }

  for(rank = RANK_1; rank <= RANK_8; ++rank) {
    for(file = FILE_A; file <= FILE_H; ++file) {
      sq = FR2SQ(file,rank);
      Sq64ToSq120[sq64] = sq;
      Sq120ToSq64[sq] = sq64;
      sq64++;
    }
  }
}

void PrintBitBoard(U64 bb) {
  U64 shiftMe = 1ULL;

  int rank = 0; 
  int file = 0; 
  int sq = 0;
  int sq64 = 0;

  printf("\n");
  for(rank = RANK_8; rank >=RANK_1; --rank) {
    for(file = FILE_A; file <=FILE_H; ++file) {
      sq = FR2SQ(file, rank);
      sq64 = SQ64(sq);

      if((shiftMe << sq64) & bb) 
        printf("X");
      else 
        printf("-");
    }
    printf("\n");
  }
  printf("\n\n");
}

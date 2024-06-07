#include "board.h"

void Init() {
  InitSq120ToSq64();
}

int main() {
  printf("%s\n", ENGINE_NAME);

  Init();

  for(int i = 0; i < BRD_SQ_NUM; ++i) {
    if(i % 10 == 0) printf("\n");
    printf("%5d", Sq120ToSq64[i]);
  }

  printf("\n");
  printf("\n");

  for(int i = 0; i < 64; ++i) {
    if(i % 8 == 0) printf("\n");
    printf("%5d", Sq64ToSq120[i]);
  }

  U64 bitboard = 0ULL;

  printf("Start:\n\n");
  PrintBitBoard(bitboard);

  bitboard |= (1ULL << SQ64(D2));

  printf("D2 Added:\n\n");
  PrintBitBoard(bitboard);

  bitboard |= (1ULL << SQ64(G2));

  printf("G2 Added:\n\n");
  PrintBitBoard(bitboard);

  return 0;
}

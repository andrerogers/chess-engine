#include "board.h"

void Init() { InitSq120ToSq64(); }

int main() {
  printf("%s\n", ENGINE_NAME);

  Init();

  U64 bitboard = 0ULL;

  bitboard |= (1ULL << SQ64(D2));
  bitboard |= (1ULL << SQ64(D3));
  bitboard |= (1ULL << SQ64(D4));

  int sq64 = 0;
  while (bitboard) {
    sq64 = PopBit(&bitboard);
    printf("popped: %d\n", sq64);
    PrintBitBoard(bitboard);
  }

  return 0;
}

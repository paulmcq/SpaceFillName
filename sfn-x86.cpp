//* sfn - Space Fill Name
// The CDC assembly code of COMCSFN can be found at:
//   http://s3data.computerhistory.org/chess/chess.sourcecode.102645430.pdf
//   2020-06-27, PHM: downloaded from page 17
#include <iostream>

typedef uint64_t TWord;
static constexpr TWord mask80 = 0x8080808080808080;

// ============================================================== sfn
// 64-bit adapdation of CDC SFN
TWord sfn (const TWord name) {
  const TWord lo1s = name - 1;          // locate lowest 1
  const TWord hi1s = name | (~ lo1s);
  const TWord lo80 = mask80 & (~ hi1s);
  const TWord lo20 = lo80 >> 2;         // 80 -> blank
  const TWord fild = name | lo20;
  return fild;
}
// -------------------------------------------------------------- test
void test (const TWord name) {
  const TWord fild = sfn( name);
  std::cout << "sfn(" << std::hex << name << ") -> " << fild << "\n";
}
// ============================================================== main
int main () {
  const TWord ABC = 0x4162636465666768; // Abcdefgh
  TWord mask = 0;
  do {
    test( ABC & ~mask);
    mask |= (mask << 8) | 0xFFu;
  }while (mask != ~TWord(0));
  test( 0);
  return 0;
}

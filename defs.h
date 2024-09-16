#ifndef DEFS_H
#define DEFS_H

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(n)                                                              \
  if (!(n)) {                                                                  \
    printf("%s - Failed", #n);                                                 \
    printf("on %s ", __DATE__);                                                \
    printf("at - %s", __TIME__);                                               \
    printf("in file %s", __FILE__);                                            \
    printf("at line %s", __LINE__);                                            \
    exit(1);                                                                   \
  }
#endif

typedef unsigned long long U64;

#define ENGINE_NAME "chess-engine"

#endif

#ifdef _DEBUG_
  #ifndef __LOG__
  #include <stdio.h>
  #include <iostream>

  #define _LOG(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n",\
          __FILE__, __LINE__, ##__VA_ARGS__)

  #define _LOGERR(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n",\
          __FILE__, __LINE__, ##__VA_ARGS__)

  #endif
#endif
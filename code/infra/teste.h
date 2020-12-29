#ifndef __TESTE_H_
#define __TESTE_H_

# define assertEquals(str, a, b) { \
            if ((a) == (b)) { \
                printf("\033[38;5;2mPASS: \033[38;5;15m%s\n", str); \
            } else { \
                printf("\033[38;5;1mFAIL: \033[38;5;15m%s  ", str); \
                printf("Obtido: %08X / Esperado: %08X \n", a, b); \
                com_erro = -1; \
            } \
        }

#endif // __TESTE_H_

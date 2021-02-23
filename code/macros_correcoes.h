#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <systemd/sd-id128.h>

#include <curl/curl.h>


int tests_passed = 0;
int tests_failed = 0;

int __attribute__ ((noinline)) faz_nada() {
    asm("");
    return -10;
}

#define assertEquals(str, a, b) {if ((a) == (faz_nada(),(b))) { tests_passed++; } else { printf("FAIL: %s\n", str); tests_failed++; }  }

#define printSummary { printf("%d de %d testes passaram\n", tests_passed, (tests_passed + tests_failed)); }

#define rodaComEntradaEmOutroProcesso(entrada, expr, res, tipo_retorno) \
{ \
pid_t p = fork();                                \
if (p == 0) {                                    \
    int old = dup(STDIN_FILENO);                     \
    int fd = open("temp", O_RDWR | O_CREAT, 0700);   \
    write(fd, entrada, sizeof(entrada));             \
    lseek(fd, 0, SEEK_SET);                          \
    dup2(fd, STDIN_FILENO);                          \
                                                     \
    res = expr ; \
                                                     \
    dup2(old, STDIN_FILENO);                         \
    close(fd);                                       \
    unlink("temp");                                  \
    return 0;                                        \
} else {                                         \
    wait(p);                                     \
} \
}

#define asssertEqualsEntrada(entrada, a, b, tipo_expr, tam_tipo)      \
{                                                \
tipo_expr *ptr = mmap(NULL, tam_tipo * 2, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0 ); \
rodaComEntradaEmOutroProcesso(entrada, a, ptr[0], tipo_expr); \
rodaComEntradaEmOutroProcesso(entrada, b, ptr[1], tipo_expr); \
assertEquals("Testando com entrada ->" entrada, ptr[0], ptr[1]); \
\
}


 size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
    return size * nmemb;
 }



#define APP_ID SD_ID128_MAKE(2, 44, d5, f6, 77, b3, 12, 66, 44, 33, 12, ff, cd, ef, 11, 22)
sd_id128_t machine_id;
char server_url[] ="http://18.222.173.185:8081";

void send_data(char *course, char *task_id, char *content) {
    sd_id128_get_machine_app_specific(APP_ID, &machine_id);
    
    char url[1024];
    sprintf(url, "%s/courses/%s/activities/%s", server_url, course, task_id);

    char *fields_str;
    char machine_id_str[33];
    sd_id128_to_string(machine_id, machine_id_str);

    CURL *curl;

    curl_global_init(CURL_GLOBAL_ALL);
    curl = curl_easy_init();

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        char *encoded_content = curl_easy_escape(curl, content, 0);
        char *fields_format = "token=%s&content=%s&type=code";

        fields_str = malloc(strlen(encoded_content) + strlen(fields_format) + strlen(machine_id_str) + strlen(server_url) + 5);
        sprintf(fields_str, fields_format, machine_id_str, encoded_content);    
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, fields_str);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, NULL);

        curl_easy_perform(curl); 
        
        curl_easy_cleanup(curl);
        free(fields_str);
    }

    curl_global_cleanup();
}
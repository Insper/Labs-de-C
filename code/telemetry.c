FILE *f = fopen(SOLUTIONFILE, "r");
fseek(f, 0, SEEK_END);
long size = ftell(f);
fseek(f, 0, SEEK_SET);
char *content = malloc(size + 1);
fread(content, 1, size, f);

fclose(f);

send_data("1", SOLUTIONFILE, content);
free(content);
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 100

void merge(int *left, int nl, int *right, int nr, int *result, int n, int order) {
  int i, j, k;

  i = j = k = 0;
  while (i < nl && j < nr) {
    if (order == 0) {
      if (left[i] <= right[j]) {
        result[k++] = left[i++];
      } else {
        result[k++] = right[j++];
      }
    } else {
      if (left[i] >= right[j]) {
        result[k++] = left[i++];
      } else {
        result[k++] = right[j++];
      }
    }
  }

  while (i < nl) {
    result[k++] = left[i++];
  }

  while (j < nr) {
    result[k++] = right[j++];
  }
}

void sort_block(int *block, int n, int order) {
  int *left, *right, mid;

  if (n <= 1) {
    return;
  }

  mid = n / 2;
  left = block;
  right = block + mid;

  sort_block(left, mid, order);
  sort_block(right, n - mid, order);
  merge(left, mid, right, n - mid, block, n, order);
}

void sort_file(const char *filename, int order) {
  FILE *fp;
  int *buffer;
  int n;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo '%s'\n", filename);
    return;
  }

  buffer = malloc(BLOCK_SIZE * sizeof(int));
  if (buffer == NULL) {
    printf("Erro ao alocar memória para o buffer\n");
    fclose(fp);
    return;
  }

  while ((n = fread(buffer, sizeof(int), BLOCK_SIZE, fp)) > 0) {
    sort_block(buffer, n, order);
    fseek(fp, -n * sizeof(int), SEEK_CUR);
    fwrite(buffer, sizeof(int), n, fp);
    fseek(fp, n * sizeof(int), SEEK_CUR);
  }

  free(buffer);
  fclose(fp);
}

void print_file(const char *filename) {
  FILE *fp;
  int value;

  fp = fopen(filename, "rb");
  if (fp == NULL) {
    printf("Erro ao abrir o arquivo '%s'\n", filename);
    return;
  }

  while (fread(&value, sizeof(int), 1, fp) == 1) {
      printf("%d\n", value);
  }

  fclose(fp);
}

int main(int argc, char *argv[]) {
  const char *filename;
  int order;

  if (argc < 2) {
    printf("Uso: %s <arquivo> [0|1]\n", argv[0]);
    return 1;
  }

  filename = argv[1];
  if (argc >= 3) {
    order = atoi(argv[2]);
    if (order != 0 && order != 1) {
      printf("Ordem deve ser 0 (crescente) ou 1 (decrescente)\n");
      return 1;
    }
  } else {
    order = 0;
  }

  sort_file(filename, order);
  print_file(filename);

  return 0;
}

   

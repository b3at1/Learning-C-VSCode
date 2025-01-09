#include <stdio.h>

int main(void){
  printf("Please input the file to dump [limit 50 characters]: ");
  FILE* fpHexD;
  char sHexDName[51];
  scanf("%50s", &sHexDName);
  fpHexD = fopen(sHexDName, "rb");
  
  if(fpHexD == NULL){
    fprintf(stderr, "The File [%s] couldn't be opened", sHexDName);
    return 1;
  }

  char ch = '0'; // placeholder value
  int count = 0;
  while(ch != EOF){
    ch = fgetc(fpHexD);
    printf("%02hhx ", ch);
    count++;
    if(count %20 == 0)
      printf("\n");
  }
  printf("\n");
  return 0;
}
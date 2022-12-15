//
// Tomás Oliveira e Silva, AED, November 2021
//
// to compare strings use the function strcmp()
// to copy a string use the function strcpy()
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//
// complete the define T !!!
//

#define T int

#include "hash_table.h"


//
// complete the register_word function (count this word)
//

void register_word(char word[64])
{
  // se find_hash_table_node(word) == NULL
  //  cria/ preenche um novo no
  //  insere o novo nó hash table
  // else 
  // incrementa o valor do nó encontrado
    hash_table_node* node = find_hash_table_node(word);

  if(node != NULL){
    node->value++;
    return;
  }

  node = allocate_hash_table_node();
  strcpy(node->key, word);
  node->value=1;
  insert_hash_table_node(node);
}


//
// main program
//

int main(int argc,char **argv)
{
  char line[10000],word[64];
  hash_table_node *n;
  FILE *fp;
  int i,j;

  for(i = 1;i < argc;i++)
  {
    //
    // open file for reading
    //
    fp = fopen(argv[i],"r");
    if(fp == NULL)
    {
      fprintf(stderr,"Unable to open file %s\n",argv[i]);
      exit(1);
    }
    //
    // place your counter initialization code here (creation of the hash table ...)
    //
    init_hash_table(1000000);
    //
    // scan the entire file
    //
    while(fgets(line,sizeof(line),fp) != NULL)
    {
      // replace non-digits and non-letters by a space
      for(i = 0;line[i] != '\0';i++)
        if((line[i] < '0' || line[i] > '9') && (line[i] < 'A' || line[i] > 'Z') && (line[i] < 'a' || line[i] > 'z') && line[i] != '\'')
          line[i] = ' ';
      // go over the line and extract each word
      for(i = 0;line[i] != '\0';i += j)
        if(line[i] == ' ')
          j = 1;
        else
        {
          for(j = 0;line[i + j] != '\0' && line[i + j] != ' ';j++)
            if(j < 63)
              word[j] = line[i + j];
          word[(j < 63) ? j : 63] = '\0';
          register_word(word);
        }
    }
    //
    // close file
    //
    fclose(fp);
    //
    // place your code to print the words and respective number of occurrences here
    //
 for(int i = 0; i < hash_table_size;i++){
      n = hash_table[i];
      while(n != NULL){
        printf(" %s - %d occurences.\n",n->key,n->value);
        n=n->next;
      }
    }
  }
}

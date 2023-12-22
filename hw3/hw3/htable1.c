#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void insert(int*** table, int size, int num);

void rehash_add(int*** table, double *size){
    int i=0,j=0;
    int help=(*size)/2;
    int temp[help];
    
    for(i=0; i<(*size); i++){
        if((*table)[i] != NULL && (*table)[i] != (int*)0x1){
            temp[j]=*(*table)[i];
            j++;
        }
    }
    
    for(int i=0; i<(*size); i++){
        free((*table)[i]);
    }
    free(*table);
    (*size)=(*size)*2;
    *table=(int**)calloc((*size),sizeof(int*));
    for(i=0; i<j; i++){
       insert(table, (*size), temp[i]);
    }
    
}

void insert(int*** table, int size, int num){
    int pos=num%size;
    if((*table)[pos] == NULL || (*table)[pos] == (int*)0x1){
        (*table)[pos]=(int*)calloc(1,sizeof(int));
        *(*table)[pos]=num;
    }
    else{
        for(int i=pos; i<size; i++){
            if((*table)[i] == NULL || (*table)[i] == (int*)0x1){
                (*table)[i]=(int*)calloc(1,sizeof(int));
                *(*table)[i]=num;
                return;
            }
        }
        for(int i=0; i<size; i++){
            if((*table)[i] == NULL || (*table)[i] == (int*)0x1){
                (*table)[i]=(int*)calloc(1,sizeof(int));
                *(*table)[i]=num;
                return;
            }
        }
    }
}

void delete(int*** table, int size, int num){
    int i=0;
    while(i<size){
        if((*table)[i] != NULL && (*table)[i] != (int*)0x1){
            if(*(*table)[i] == num){
                free((*table)[i]);
                (*table)[i]=(int*)0x1;
                return;
            }
        }
        i++;
    }
}

int find(int** table, int num, int size){
    for(int i=0; i<size; i++){
        if(table[i] != NULL && table[i] != (int*)0x1){
            if(*table[i] == num){
                return 1;
            }
        }
    }
    return 0;
}

void rehash_delete(int*** table, double *size){
    int i=0,j=0;
    int help=(*size);
    int temp[help];
    
    for(i=0; i<(*size); i++){
        if((*table)[i] != NULL && (*table)[i] != (int*)0x1){
            temp[j]=*(*table)[i];
            j++;
        }
    }
    
    
    for(int i=0; i<(*size); i++){
        if((*table)[i] != NULL && (*table)[i] != (int*)0x1){
            free((*table)[i]);
        }
    }
    free(*table);
    (*size)=(*size)/2;
    *table=(int**)calloc((*size),sizeof(int*));
    for(i=0; i<j; i++){
       insert(table, (*size), temp[i]);
    }
}

int main(int argc, char* argv[]){
    char choice[3]={0},help='\0';
    double load_factor=0,size=2,elems=0,del=0;
    int num=0,val=0;
    int **table=NULL;
    
    table=(int**)calloc(size,sizeof(int*));
    scanf("%s",choice);
    while(1){
        if(strcmp(choice,"-i") == 0 || help == 'i'){
            help='i';
            while(1){
                scanf("%s",choice);
                if(strcmp(choice,"-d") == 0 || strcmp(choice,"-f") == 0 || strcmp(choice,"-p") == 0 || strcmp(choice,"-q") == 0){
                    break;
                }
                num=atoi(choice);
                load_factor=elems/size;
                if(load_factor >= 0.5){
                    rehash_add(&table, &size);
                }
                val=find(table, num, size);
                if(val == 0){
                    insert(&table, size, num);
                    printf("\nINSERTED %d\n",num);
                    elems++;
                    if(del>0){
                        del--;
                    }
                }
                else{
                    printf("\nNOT INSERTED %d\n",num);
                }
            }
        }
        if(strcmp(choice,"-d") == 0 || help == 'd'){
            help='d';
            while(1){
                scanf("%s",choice);
                if(strcmp(choice,"-i") == 0 || strcmp(choice,"-f") == 0 || strcmp(choice,"-p") == 0 || strcmp(choice,"-q") == 0){
                    break;
                }
                num=atoi(choice);
                val=find(table, num, size);
                if(val == 1){
                    delete(&table, size, num);
                    del++;
                    if(elems>0){
                        elems--;
                    }
                    printf("\nDELETED %d\n",num);
                }
                else{
                    printf("\nNOT DELETED %d\n",num);
                }
                load_factor=elems/size;
                if(load_factor <= 0.125){
                    rehash_delete(&table, &size);
                    del=0;
                }
            }
        }
        if(strcmp(choice,"-f") == 0 || help=='f'){
            help='f';
            while(1){
                scanf("%s",choice);
                if(strcmp(choice,"-d") == 0 || strcmp(choice,"-i") == 0 || strcmp(choice,"-p") == 0 || strcmp(choice,"-q") == 0){
                    break;
                }
                num=atoi(choice);
                val=find(table, num, size);
                if(val == 1){
                    printf("\nFOUND %d\n",num);
                }
                else{
                    printf("\nNOT FOUND %d\n",num);
                }
            }
        }
        if(strcmp(choice,"-p") == 0){
            printf("\nSIZE: %0.lf, INSERTED: %0.lf, DELETED: %0.lf\n",size, elems, del);
            for(int i=0; i<size; i++){
                printf("%3d ",i);
            }
            printf("\n");
            for(int i=0; i<size; i++){
                if(table[i] != NULL && table[i] != (int*)0x1){
                    printf("%3d ",*table[i]);
                }
                else if(table[i] == NULL){
                    printf("  * ");
                }
                else if(table[i] == (int*)0x1){
                    printf("  # ");
                }
            }
            printf("\n");
        }
        if(strcmp(choice,"-q") == 0){
            for(int i=0; i<size; i++){
                if(table[i] != NULL && table[i] != (int*)0x1){
                    free(table[i]);
                }
            }
            free(table);
            return 0;
        }
    }
}
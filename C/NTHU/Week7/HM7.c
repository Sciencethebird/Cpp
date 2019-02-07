#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct DOG{
    char name[16];
    int age;
    double weight;
};

struct TREE{
    struct DOG *dog;
    struct TREE *next[26];
};

struct TREE* newElement(){
    int i;
    struct TREE *temp = (struct TREE *)malloc(sizeof(struct TREE));
    /** Add your code here for initializaton **/
    return temp;
}

void insert(struct TREE *treePtr, struct DOG *dog){
    int i;
    for(i=0;i<strlen(dog->name);i++){
        /** Add your code here for moving treePtr **/
    }
    treePtr->dog = dog;
}

struct DOG* find(struct TREE *treePtr, char *name){
    int i;
    /** Add your code here for determining the existence of the dog and moving treePtr **/
}

void freeTree(struct TREE *treePtr){
    int i;
    if(treePtr!=NULL){
        for(i=0;i<26;i++){
            freeTree(treePtr->next[i]);
        }
        free(treePtr);
    }
}

struct DOG dogs[500000];
struct TREE *tree = NULL;

int main()
{
    char cmd[8], tempName[16];
    int counter = 0;
    struct DOG *result;
    tree = newElement();

    while(1){
        scanf("%s", cmd);
        if(0==strcmp(cmd,"finish")){
            break;
        }
        else if(0==strcmp(cmd,"new")){
            insert(tree, &dogs[counter]); /** Add some code above and/or below this line **/
        }
        else if(0==strcmp(cmd,"find")){
            scanf("%s", tempName);
            result = find(tree, tempName);
            if(result==NULL){
                printf("no such dog\n");
            }
            else {
                printf("name: %s, age: %d, weight: %.2lf\n", result->name, result->age, result->weight);
            }
        }
    }
    freeTree(tree);
    return 0;
}

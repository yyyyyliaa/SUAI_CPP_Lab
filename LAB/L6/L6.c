///Написать программу составления двоичного дерева слов по символьному файлу 
//и функцию определения глубины дерева

#include <stdio.h>
#include <stdlib.h>

typedef struct tnode {
    char *word;
    int capacity;
    int count;
    struct tnode *left; 
    struct tnode *right; 
    struct tnode *root;  
} tnode;

typedef struct tree {
    tnode *head; 
    int count;   
} tree;

typedef struct file {
    char *str;
    int size;
} file;

int fileSize(FILE *file) {
    fseek(file, 0, SEEK_END);
    int fsize = ftell(file);
    fseek(file, 0, SEEK_SET);
    return fsize;
}

file *readFile(char *path) {
    FILE *f = fopen(path, "rt");
    if (f == NULL) perror("Error opening file");
    int fsize = fileSize(f);
    char *str = (char *)malloc(fsize * sizeof(char));
    for (int i = 0; i < fsize; i++) str[i] = fgetc(f);
    fclose(f);
    file *temp_file = (file *)malloc(sizeof(file));
    temp_file->str = str;
    temp_file->size = fsize;
    return temp_file;
}

int strCmp(char *s1, char *s2) {
    char c1, c2;
    while ((c1 = *s1++) == (c2 = *s2++))
        if (c1 == '\0')
            return 0;
    return c1 - c2;
}

int isChar(char k) {
	if ((k >= 'a' && k <= 'z') || (k >= 'A' && k <= 'Z')) return 1;
	else return 0;
}

void addTree(tree *t, char *str, int capacity) {
    tnode *temp_node = (tnode *)malloc(sizeof(tnode));
    temp_node->word = str;
    temp_node->capacity = capacity;
    temp_node->right = NULL;
    temp_node->left = NULL;
    temp_node->root = NULL;
    temp_node->count = 1;
    if (t->head == NULL) t->head = temp_node;
    else {
        tnode *source = t->head;
        int flag = 0;
        do {
            if (strCmp(str, source->word) > 0)
                if (source->right != NULL)
                    source = source->right;
                else flag = -1;
            else if (strCmp(str, source->word) < 0)
                if (source->left != NULL)
                    source = source->left;
                else flag = 1;
            else {
                source->count++;
                free(temp_node);
                break;
            }
        } while (flag == 0);
        if (flag == -1) source->right = temp_node;
        else if (flag == 1) source->left = temp_node;
    }
    t->count++;
}

void parseStr(char *temp, int size, tree *t) {
    int capacity = 1, len = 0;
    char *str = (char *)malloc(sizeof(char));
    for (int i = 0; i < size; i++) {
        if (isChar(temp[i])) {
            str[len++] = temp[i];
            if (len >= capacity) str = (char *)realloc(str, (capacity *= 2) * sizeof(char));
            if (size - i == 1) goto word_end;
        }
        else {
        word_end:
            if (len){
                str[len] = '\0';
                addTree(t, str, capacity);
                capacity = 1;
                len = 0;
                str = (char *)malloc(sizeof(char));
            }
        }
    }
}

void init(struct tree *t) {
    t->head = NULL;
    t->count = 0;
}

void printTree(struct tnode *node) {
    printf("%d %s\n", node->count, node->word);
    if (node->left != NULL)
        printTree(node->left);
    if (node->right != NULL)
        printTree(node->right);
}

int DeepTree(tnode* tree) {
    int deepR = 1;
    int deepL= 1;
    if (tree == NULL) return 0;
    if (tree->left != NULL) {
        deepL = DeepTree(tree->left);
        deepL++;
    }
    if (tree->right != NULL) {
        deepR = DeepTree(tree->right);
        deepR++;
    }
    if (deepR > deepL) return deepR;
    else return deepL;
}

int main() {
    file *f = readFile("LAB/L6/file.txt");
    tree myTree;
    init(&myTree);
    parseStr(f->str, f->size, &myTree);
    printf("Deep tree: %d\n", DeepTree((&myTree)->head));
    printTree((&myTree)->head);
}
//
// Created by 44811 on 2020/10/26.
//
#include "mttree.h"
#include "queue.h"

Node** initalize_leaf(char* string) {
    pre_deal_dir(string);
    Node** node = (Node**) malloc(sizeof(Node*)*(files_cnt+1));
    for (int i = 0; i < files_cnt; i++) {
        node[i] = (Node*) malloc (sizeof(Node));
        if (node[i] == NULL) {
            printf("null\n");
            getchar();
        }
        sprintf(abs_path, "%s\\%s", string, file_names[i]);
        // printf("%s\n", abs_path);
        read_file(abs_path, text, MAXLEN);
        SHA256_CTX ctx;
        sha256_init(&ctx);
        sha256_update(&ctx, text, strlen(text));
        sha256_final(&ctx, buf);
        strcpy(node[i]->file_name, file_names[i]);
        node[i]->file_name[strlen(file_names[i])] = 0;
        strcpy(node[i]->hashval, buf);
        node[i]->hashval[SHA256_BLOCK_SIZE] = 0;
        node[i]->parent = NULL;
        node[i]->left = NULL;
        node[i]->right = NULL;
    }
    node[files_cnt] = NULL;
    return node;
}

int getFiles(char *path, char** _file_names) {
    DIR *dir;
    struct dirent* ptr;
    dir = opendir(path);
    int i = 0;
    while ((ptr=readdir(dir))!= NULL) {
        #ifdef DEBUG
        printf("%s\n", ptr->d_name);
        #endif
        if (strcmp(".", ptr->d_name) == 0 || strcmp("..", ptr->d_name) == 0) {
            continue;
        }
        _file_names[i] = (char*) malloc(strlen(ptr->d_name)+1);
        strcpy(_file_names[i], ptr->d_name);
        i++;
    }
    closedir(dir);
    _file_names[i] = NULL;
    return i;
}

void sort_files(char** _file_names) {
    char* tmp;
    int i, j;
    for (i = 0; i < files_cnt; i++) {
        for (j = i + 1; j < files_cnt; j++) {
            if (strcmp(_file_names[i], _file_names[j]) > 0) {
                tmp = _file_names[i];
                _file_names[i] = _file_names[j];
                _file_names[j] = tmp;
            }
        }
    }
}

void pre_deal_dir(char* dir_name) {
    // 好的， 现在我们已经生成了一个目录以及16个文件, 我们把它的文件名字符串按照大小排序之后存储起来
    files_cnt = getFiles(dir_name, file_names);
    sort_files(file_names);
    // just for debug
    #ifdef DEBUG
    for (int i = 0; i < files_cnt; i++) {
        printf("%s\n", file_names[i]);
    }
    #endif
}

int read_file(const char *filename, char *dest, int maxlen) {
    FILE *file;
    int pos, temp, i;

    //打开文件
    file = fopen(filename, "r");
    if( NULL == file ) {
        printf("error %s\n", filename);
        fprintf(stderr, "open %s error\n", filename);
        return -1;
    }
    pos = 0;
    //循环读取文件中的内容
    for(i=0; i< maxlen-1; i++) {
        temp = fgetc(file);
        if(EOF == temp)
            break;
        dest[pos++] = temp;
    }
    //关闭文件
    fclose(file);
    //在数组末尾加0
    dest[pos] = 0;

    return pos;
}

bool compare(Node** node, Node** oldnode) {
    if (oldnode == NULL) {
        return false;
    }
    for (int i = 0; i < files_cnt; i++) {
        if (oldnode[i] == NULL) {
            return false;
        }
        if (strcmp(oldnode[i]->file_name, node[i]->file_name)!=0 || strcmp(oldnode[i]->hashval, node[i]->hashval)!=0) {
            printf("===========\n");
            printf("oldnode--->: \n");
            printf("%s\n", oldnode[i]->file_name);
            for(int x = 0; x < SHA256_BLOCK_SIZE; x++)
                printf("%02x", oldnode[i]->hashval[x]);
            printf("==========\ncurnode--->: \n");
            printf("%s\n", node[i]->file_name);
            for(int x = 0; x < SHA256_BLOCK_SIZE; x++)
                printf("%02x", node[i]->hashval[x]);
            getchar();

            return false;
        }
    }
    if (oldnode[files_cnt] != NULL) {
        return false;
    }
    return true;
}

Node* push(Node* node1, Node* node2) {
    Node* new = malloc(sizeof(Node));
    int len = 0;
    if (node2 == NULL) {
        strcpy(text, node1->file_name);
        len = strlen(node1->file_name);
    } else {
        sprintf(text, "%s%s", node1->file_name, node2->file_name);
        len = strlen(node1->file_name) + strlen(node2->file_name);
    }
    text[len] = 0;
    strcpy(new->file_name, text);
    len = 0;
    if (node2 == NULL) {
        strcpy(text, node1->hashval);
        len = strlen(node1->hashval);
    } else {
        sprintf(text, "%s%s", node1->hashval, node2->hashval);
        len = strlen(node1->hashval) + strlen(node2->hashval);
    }
    text[len] = 0;
    // printf("new name: %s\n", text);
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, text, strlen(text));
    sha256_final(&ctx, buf);
    strcpy(new->hashval, buf);
    new->parent = NULL;
    new->left = node1;
    new->right = node2;
    node1->parent = new;
    if (node2 != NULL)
        node2->parent = new;
    return new;
}

void showtree(Node* root) {
    if (root == NULL)
        return;
    int depth = 1;
    Queue* q = CreateQueue();
    AddQ(q, root);
    int cnt = 0;
    int shift = 1;
    while (!IsEmptyQ(q)) {
        Node* p = DeleteQ(q);
        if (p->left != NULL) {
            AddQ(q, p->left);
        }
        if (p->right != NULL) {
            AddQ(q, p->right);
        }
        for (int k = 0; k < depth; k++) {
            printf("★");
        }
        printf(" key: %s hash: ", p->file_name);
        for(int x = 0; x < SHA256_BLOCK_SIZE; x++)
            printf("%02x", p->hashval[x]);
        printf("\n\n");
        cnt++;
        if (cnt >= shift) {
            depth++;
            shift<<=1;
            cnt=0;
        }
    }
}

void build_tree(MtTree * mt, Node** node) {
    int len = files_cnt;
    mt->treesize = 0;
    while (true) {
        // printf("%d\n", len);
        mt->treesize += len;
        if (len <= 1) {
            break;
        }
        int cnt = 0;
        for (int i = 0; i < len; i+=2) {
            if (i+1==len) {
                node[cnt++] = push(node[i], NULL);
            } else {
                node[cnt++] = push(node[i], node[i+1]);
            }
        }
        len = cnt;
        node[len] = NULL;
    }
    mt->arr = &node[0];
}

int traverse(Node* tree1, Node* tree2){
    // printf("digui\n");
    if(tree1 == NULL && tree2 == NULL){
        return 1;
    }
    // 由于这个实验只有一个文件不相同
    if (strcmp(tree1->hashval, tree2->hashval) == 0) {
        return 0;
    }
    int ret1 = traverse(tree1->left, tree2->left);
    int ret2 = traverse(tree1->right, tree2->right);
    if (ret1 || ret2) {
        printf("%s <------> %s 不一致\n", tree1->file_name, tree2->file_name);
        printf("%s\n%s\n", tree1->hashval, tree2->hashval);

        return 0;
    }
}

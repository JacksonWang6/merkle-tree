//
// Created by 44811 on 2020/10/26.
//

#ifndef BIGDATA_LAB3_MTTREE_H
#define BIGDATA_LAB3_MTTREE_H
#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <string.h>
#include <dirent.h>
#include "sha256.h"

#define MAX_FILE_NUM 128
#define MAXLEN 256
// #define DEBUG
typedef int bool;
#define true 1
#define false 0
typedef struct node {
    char file_name[256];                    //节点的键，用来加速检索，可选数据块或其名称的代表性特征
    char hashval[SHA256_BLOCK_SIZE+1];	//本节点的哈希值，叶子节点为数据块的哈希，中间节点和根节点为左右子节点拼接后值的哈希。
    struct node * parent;
    struct node * left;
    struct node * right;
} Node;

typedef struct mttree {
    int treesize;             //哈希树规模，节点数
    Node **arr;
} MtTree;
char text[MAXLEN];
char buf[SHA256_BLOCK_SIZE] ;
char abs_path[MAXLEN];
// 存储目录下的文件名
char* file_names[MAX_FILE_NUM+1];
// 文件个数
int files_cnt;
// 获取一个指定目录下面的文件名
int getFiles(char *path, char** file_names);
// 将文件名排序
void sort_files(char** file_names);
// 将一个文件的内容读取到一个数组里面
int read_file(const char *filename, char *dest, int maxlen);
// 预处理目录：遍历目录获得文件名，并且按照文件名字符串大小进行排序
void pre_deal_dir(char* dir_name);
// 比较node与oldnode是否相同
int compare(Node** node, Node** oldnode);
// 默克尔树的构建
void build_tree(MtTree * mt, Node** node);
//
Node* push(Node* node1, Node* node2);
// 按键进行默克尔树的遍历定位
int traverse(Node* tree1, Node* tree2);

// 默克尔树的遍历打印
void showtree(Node * root);

// initalize_leaf函数，输出Node类型的数组，每个叶子节点的key可使用文件名，哈希值为文件所有数据的哈希
// 叶子节点初始化时，父节点、左右子节点为空，数据结构参考前述数据结构。未初始化时，key值可以设成-1.
Node **initalize_leaf(char *string);



#endif //BIGDATA_LAB3_MTTREE_H

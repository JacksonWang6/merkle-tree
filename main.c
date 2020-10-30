#include "mttree.h"

int main(int argc, char *argv[]) {
    if(argc == 1 || argc > 3) {
        puts("error parameters");
        return 0;
    }
    //含程序自身参数，总参数数为2时，第2个参数为用于构建默克尔树的目录
    //含程序自身参数，总参数数为3时，第2个参数为用于构建默克尔树的目录，第3个参数为用于构建默克尔树和比较一致性的目录，
    //相关逻辑自行补充
    if (argc == 2) {
        Node **oldnode = NULL;
        char cmd[256] = {0};
        sprintf(cmd, "C:\\cmder\\vendor\\git-for-windows\\bin\\bash .\\create_dir.sh %d %d %s", 100, 200, argv[1]);
        system(cmd);
        Node **root = (Node **) malloc(sizeof(Node *) * (MAX_FILE_NUM + 1));
        for (int i = 0; i < MAX_FILE_NUM + 1; i++) {
            root[i] = NULL;
        }
        //整体实验大循环，完成实验3-1至3-4
        while (1) {
            //初始化创建叶子节点，注意根据目录下文件数分配空间
            Node **node = initalize_leaf(argv[1]);
            if (compare(node, oldnode)) {
                printf("No change in the directory.\n");
                for (volatile int i = 0; i < 1000000000; i++);
                continue;
            }
            if (oldnode == NULL) {
                oldnode = node;
            }
            for (int j = 0; j < files_cnt; j++) {
                // printf("debug: %d\n", j);
                if (root[j] == NULL)
                    root[j] = (Node *) malloc(sizeof(Node));
                strcpy(root[j]->hashval, node[j]->hashval);
                strcpy(root[j]->file_name, node[j]->file_name);
                root[j]->right = NULL;
                root[j]->left = NULL;
                root[j]->parent = NULL;
            }
            root[files_cnt] = NULL;
            MtTree *mt = (MtTree *) malloc(sizeof(MtTree));
            // 哈希树叶子节点构建，自行设计迭代实现整体默克尔树构建
            build_tree(mt, root);

            oldnode = node;
            showtree(root[0]);
            // break;
        } //结束大循环
    } else {
        // argc == 3
        Node** node1 = initalize_leaf(argv[1]);
        Node** node2 = initalize_leaf(argv[2]);
        MtTree *mt = (MtTree *) malloc(sizeof(MtTree));
        build_tree(mt, node1);
        build_tree(mt, node2);
        // printf("run here\n");
        traverse(node1[0], node2[0]);
    }
}



#!/bin/bash
# 这个脚本的用处是新建一个测试文件夹，并且创建16个文件，并且随机写入一些字符串
dir=$3
# 前缀
infix="test_file_"
enable_test=0
if [ ! -d  "$dir" ]; then
    mkdir "$dir"
fi

# 生成一个指定范围内的随机数,有两个参数，代表范围
gen_random_num() {
    min=$1
    max=$((2-min+1))
    num=$((RANDOM+1000000000)) #增加一个10位的数再求余
    echo $((num%max+min))
}

# 生成一个随机字符串
gen_random_str() {
    MATRIX="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz~!@#$%^&*()_+="
    LENGTH=$(gen_random_num "$1" "$2")
    # echo "$LENGTH"
    STR=""
    for ((i=0; i<LENGTH; i++)) {
        STR="$STR${MATRIX:$((RANDOM%${#MATRIX})):1}"
    }
    echo "${STR}"
}

test() {
    # just for test
    if [[ $enable_test -eq 1 ]]; then
        echo "start test"
        gen_random_num 100 1000
        gen_random_str 100 200
    fi
}

main() {
    # main function
    for ((j=0; j<16; j++)) {
        echo "正在为您生成第${j}个文件"
        gen_random_str "$1" "$2" > "${dir}""\\"${infix}${j}".txt"
    }
}

if [[ $# -ne 3 ]]; then
    echo "Usage: bash create_dir arg1 arg2 arg3"
    echo "arg1: 你期待的随机字符串的长度最小值"
    echo "arg2: 你期待的随机字符串的长度的最大值"
    echo "arg3: 用于构建默克尔树的目录"
    exit 0
fi

test
main "$1" "$2"
#!/bin/bash

set -e

# 引数
type=${1,,}       # abc / arc / agc / awc
number=$2         # コンテスト番号
last=${3:-g}      # 最終問題（省略時はg）

# 引数チェック
if [[ ! "$type" =~ ^(abc|arc|agc|awc)$ ]]; then
    echo "Error: type must be abc, arc, agc, or awc"
    exit 1
fi

if [[ ! "$number" =~ ^[0-9]+$ ]]; then
    echo "Error: invalid contest number"
    exit 1
fi

if [[ ! "$last" =~ ^[a-z]$ ]]; then
    echo "Error: last must be a-z"
    exit 1
fi

# コンテスト番号を3桁にする
contest=$(printf "%03d" "$((10#$number))")

# 出力先
dir="$type/$contest"
mkdir -p "$dir"

# A～指定された問題まで生成
for problem in {a..z}; do
    file="$dir/$problem.cpp"

    if [ ! -e "$file" ]; then
        {
            echo "// The template file is below"
            echo "// https://github.com/micci439899/atcoder"
            echo ""
            cat template.cpp
        } > "$file"

        echo "Created: $file"
    else
        echo "Skip: $file"
    fi

    if [ "$problem" = "$last" ]; then
        break
    fi
done
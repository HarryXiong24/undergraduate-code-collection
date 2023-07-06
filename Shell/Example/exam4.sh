#移除文件的.ok后缀,需要传入一个参数，为需要查找ok文件的路径
function mvok() {
    if [ $# -eq 1 ] ;then
        for file in `hdfs dfs -find $1 -name "*.ok"`
        do
            echo "move ok on file ${file}"
            hdfs dfs -mv ${file} ${file%.ok}
        done
    fi
}
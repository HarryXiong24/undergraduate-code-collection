interface Encrypt {
    (key: string, value: string): string;
}

const md5: Encrypt = function(key: string, value: string): string {
    // 模拟操作
    return key + value;
}

console.log(md5('hello', 'world'));
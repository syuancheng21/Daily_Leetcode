/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    // let 声明可重新赋值的变量（字符串不可变，后面需要重新赋值，所以用 let 不用 const）
    let tmp = "";

    // let 声明，ans 后面会被重新赋值，所以不用 const
    let ans = 0;

    // for...of 遍历字符串每个字符，x 是每次拿到的字符
    // const 因为 x 在循环体内不会被重新赋值
    for (const x of s) {

        // indexOf() 是字符串内置方法，找字符第一次出现的位置
        // 找不到返回 -1，对应 C++ 的 string::npos
        // const 因为 pos 不会被重新赋值
        const pos = tmp.indexOf(x);

        // !== 是严格不等于，JS 里永远用 !== 而不是 !=
        // != 会做类型转换，可能产生意外结果
        if (pos !== -1) {

            // tmp.length 是属性不是方法，不需要加 ()
            // 对应 C++ 的 s.size()
            if (tmp.length > ans) {
                ans = tmp.length;
            }

            // slice(start) 返回从 start 到末尾的新字符串
            // JS 字符串不可变，所以必须重新赋值给 tmp
            // 对应 C++ 的 s.erase(0, pos+1)，但 C++ 是原地修改，JS 是生成新字符串
            tmp = tmp.slice(pos + 1);
        }

        // += 字符串拼接，把字符 x 追加到 tmp 末尾
        // JS 里字符串拼接统一用 +=，对应 C++ 的 push_back()
        tmp += x;
    }

    // 循环结束后 tmp 里还有最后一段窗口，需要再判断一次
    if (tmp.length > ans) {
        ans = tmp.length;
    }

    // return 返回结果，JS 函数没有返回值类型声明，直接 return
    return ans;
};

console.log(lengthOfLongestSubstring("abcabcbb")); // 3
console.log(lengthOfLongestSubstring("bbbbb"));    // 1
console.log(lengthOfLongestSubstring("pwwkew"));   // 3

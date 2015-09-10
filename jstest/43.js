// http://www.nowcoder.com/practice/4ec56ad04a9a4402a01e50a390a8060a?rp=3&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function captureThreeNumbers(str) {
    var arr = str.match(/\d{3}/);
    if (arr) return arr[0];
    return false;
}

// 参考
// 题目描述有问题，实际考察的是字符串中是否含有连续的三个任意数字，而不是三个连续的数字。依题，若存在连续的三个任意数字，则返回最早出现的三个数字，若不存在，则返回false。因此需要用到match方法，match()返回的是正则表达式匹配的字符串数组，连续的三个任意数字用正则表达式表示为/\d{3}/。

// captureThreeNumbers('98x6523') = "652"

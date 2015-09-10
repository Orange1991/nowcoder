// http://www.nowcoder.com/practice/fb2d46b99947455a897f2e9fe2268355?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function partial(fn, str1, str2) {
    var result = function(str3) {
        return fn(str1, str2, str3);
    }
    return result;
}

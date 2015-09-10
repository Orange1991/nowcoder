// http://www.nowcoder.com/practice/a5de760a7cf24c0e890eb02eed34bc02?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function functions(flag) {
    if (flag) {
        var getValue = function() { return 'a'; }
    } else {
        var getValue = function() { return 'b'; }
    }
    return getValue();
}

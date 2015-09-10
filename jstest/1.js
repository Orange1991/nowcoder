// http://www.nowcoder.com/practice/e7835a8113dd48afb15f77ef8d1dcb1d?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function indexOf(arr, item) {
    var i = 0;
    while (i < arr.length) {
        if (arr[i] == item) return i;
        ++i;
    }
    return -1;
}

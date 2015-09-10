// http://www.nowcoder.com/practice/628339bd8e6e440590ad86caa7ac6849?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function count(arr, item) {
    var copy = arr.filter(function(x){return x == item});
    return copy.length;
}

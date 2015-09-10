// http://www.nowcoder.com/practice/0323822699da497b8822898e90025882?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function curtail(arr, item) {
    var copy = arr.filter(function(x){return true});
    copy.shift();
    return copy;
}

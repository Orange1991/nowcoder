// http://www.nowcoder.com/practice/93994cb28b1c4ec5ad7da4f9c33ebfbe?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function prepend(arr, item) {
    var copy = arr.filter(function(x){return true});
    copy.unshift(item);
    return copy;
}

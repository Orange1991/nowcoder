// http://www.nowcoder.com/practice/941bcfa5b87940869fda681c1597fd3a?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function insert(arr, item, index) {
    var copy = arr.filter(function(x){return true});
    copy.splice(index, 0, item);
    return copy;
}

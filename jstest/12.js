// http://www.nowcoder.com/practice/871a468deecf453589ea261835d6b78b?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function duplicates(arr) {
    var copy = arr.filter(function(x){
        var cur = arguments[1];
        var next = arr.indexOf(x, arguments[1] + 1);
        var first = arr.indexOf(x);
        return next != -1 && cur == first;
    });
    return copy;
}

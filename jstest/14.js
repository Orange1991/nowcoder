// http://www.nowcoder.com/practice/0a9af9cb20c34babb6232126e019c74d?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function findAllOccurrences(arr, target) {
    var pos = [];
    arr.filter(function(x){
        if(x == target)
            pos.push(arguments[1]);
        return false;
    });
    return pos;
}

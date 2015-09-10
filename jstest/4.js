// http://www.nowcoder.com/practice/a93dd26ebb8c425d844acc17bcce9411?rp=1&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function removeWithoutCopy(arr, item) {
    var i = 0;
    while (i < arr.length) {
        if (arr[i] == item)
            arr.splice(i, 1);
        else ++i;
    }  
    return arr;
}

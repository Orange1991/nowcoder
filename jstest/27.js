// http://www.nowcoder.com/practice/d47b482e7148497582c7a995df51f393?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function callIt(fn) {
    var param = [];
    for (var i = 1; i < arguments.length; ++i)
        param.push(arguments[i]);
    return fn.apply(this, param);
}

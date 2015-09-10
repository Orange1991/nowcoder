// http://www.nowcoder.com/practice/694afeb930f74392bda01a815219d81b?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function partialUsingArguments(fn) {
    var param = [];
    for (var i = 1; i < arguments.length; ++i)
        param.push(arguments[i]);
    var result = function() {
        for (var i = 0; i < arguments.length; ++i)
            param.push(arguments[i]);
        return fn.apply(this, param);
    };

    return result;
}

// var a = 1; var b = 2; var c = 3; var d = 4;var test = function (first, second, third, forth) {return first + second + third + forth;};partialUsingArguments(test, a, b)(c, d);

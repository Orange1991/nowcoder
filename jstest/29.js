// http://www.nowcoder.com/practice/bb78d69986794470969674a8b504ac00?rp=2&ru=/ta/js-assessment&qru=/ta/js-assessment/question-ranking

function curryIt(fn) {
    var a = function(paramA) {
        var b = function(paramB) {
             var c = function(paramC) {
                 return fn(paramA, paramB, paramC);
             }
             return c;
        }
        return b;
    };
    return a;
}

// var fn = function (a, b, c) {return a + b + c}; curryIt(fn)(1)(2)(3);
